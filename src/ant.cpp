#include "ant.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Ant::Ant()
     :m_hit(false)
{
    m_maxAngle = 10*3.14/180;
    m_maxAccel = 1;
    m_vel = m_axisX * 0.5;
    m_friction = 0.09;
    m_walkCounter = rand();
    m_mass =1;
    m_type = kAnt;
    m_force = Vector(0,0,0);
    srand ( time(NULL) );
    m_pheromone = Vector(0,0,0);
    m_trans.SetTranslate(m_pos);
    m_trans.ApplyTransform();
    m_bound = 1;
    m_state = HomeToFood;
    kPheromone = 1;
    kWall = 0.08;
    kAttract = 1;
    kObstacle = 0.5;
    kRand = 1;
}
//------------------------------------------------------------------------------------
Ant::Ant(const Ant& _ant):SceneObject()
{
    m_maxAccel = _ant.m_maxAccel;
    m_maxAngle = _ant.m_maxAngle;
    m_friction = _ant.m_friction;
    m_hit = _ant.m_hit;
    m_walkCounter = _ant.m_walkCounter;
    m_mass = _ant.m_mass;
    m_type = _ant.m_type;
    m_pheromone = _ant.m_pheromone;
    m_node = _ant.m_node;
}
//------------------------------------------------------------------------------------
Ant Ant::operator = (const Ant& _ant)
{
    m_maxAccel = _ant.m_maxAccel;
    m_maxAngle = _ant.m_maxAngle;
    m_friction = _ant.m_friction;
    m_hit = _ant.m_hit;
    m_walkCounter = _ant.m_walkCounter;
    m_mass = _ant.m_mass;
    m_type = _ant.m_type;
    m_pheromone = _ant.m_pheromone;
    m_node = _ant.m_node;
    return *this;
}
//------------------------------------------------------------------------------------
Ant::~Ant()
{
}
//------------------------------------------------------------------------------------
void Ant::Reset()
{
#ifdef _DEBUG
    std::cout<<"reset called...................\n";
#endif
    m_pos = Vector(0,0,0);
    m_vel = m_axisX * 0.7;
    m_force = Vector(0,0,0);
    m_trans.Reset();
    m_trans.ApplyTransform();
    m_state = HomeToFood;
}
//------------------------------------------------------------------------------------
bool Ant::Arrive(const SceneObject& _obj)
{
    float dis = (m_pos-_obj.m_pos).Length();
    if ( dis < (m_bound+_obj.GetBound()) )
    {
        return true;
    }
    else return false;
}
//------------------------------------------------------------------------------------
bool Ant::DetectPheromone(PhrmType _type, const Trail& _trail)
{
    Vector phrmCentre(0,0,0);
    uint32_t phrmNum(0);
    uint32_t num =_trail.m_phrmTrail.size();
    for( uint32_t i=0; i< num; ++i)
    {
        Vector phrm;
        if( CheckNeighbor(*_trail.m_phrmTrail[i], 3.0, 7) && (_trail.m_phrmTrail[i]->m_phrmType == _type) )
        {
            phrm = _trail.m_phrmTrail[i]->m_pos;// * ( _trail.m_phrmTrail[i]->m_maxAge - _trail.m_phrmTrail[i]->m_age );
            phrmNum++;
        }
        #ifdef _DEBUG
        std::cout<<phrmNum<<"phrm number\n";
        #endif
        phrmCentre += phrm;
    }

    if( phrmNum == 0)
    {
        return false;
    }
    else
    {
        phrmCentre /= phrmNum;
        m_pheromone = ( phrmCentre - m_pos).Normalise();
        return true;
    }
}
//------------------------------------------------------------------------------------
void Ant::DetectObstacle(const std::vector<Ant*>& _antList)
{
    size_t num = _antList.size();
    m_obstacles = Vector(0,0,0);
    for( uint32_t i=0; i<num; ++i )
    {
        if( (_antList[i]!=this) && (CheckNeighbor(*_antList[i],60*3.14/180,3)))//&& ( m_vel.AngleBetween(_antList[i]->m_vel) <0) )
        {
            Vector dis = m_pos - _antList[i]->m_pos;
            float disquare = dis.LengthSquare();
            if (disquare !=0)
            {
                m_obstacles +=  dis/disquare;
            }
        }
    }
    m_obstacles = m_obstacles.Normalise();
}
//------------------------------------------------------------------------------------
bool Ant::Near(const SceneObject& _obj)
{
    if( CheckNeighbor( _obj, 3,10) )
    {
        m_attraction = (_obj.m_pos - m_pos).Normalise();
        return true;
    }
    else
    {
        return false;
    }
}
//------------------------------------------------------------------------------------
void Ant::RandomWalk()
{
    const uint32_t frequency = 100;

    if(m_walkCounter%frequency==0)
    {
        m_rand = Vector( ((float)rand() / (float)RAND_MAX -0.5),  0, ((float)rand() / (float)RAND_MAX-0.5) ) *20;
        m_walkCounter++;
    }
    else
    {
        m_rand = m_axisX*m_maxAccel*m_mass;
        m_walkCounter++;
    }
}
//------------------------------------------------------------------------------------
void Ant::SetHeight()
{
}
//------------------------------------------------------------------------------------
void Ant::Wall()
{
    /*
      ------------------------
      |                      |
      |  |----------------|  |
      |  |                |  |
      |  |                | -|-blank(if boid is in this area, get repulsion force away from the wall)
      |  |                |  |
      |  |                |  |-wall
      |  |                |  |
    */
    const float forceScalar = 1;
    const float blank = 5;
    float wall =30;
    wall = wall -blank;

    m_wall = Vector(0,0,0);
    if ( m_pos.GetX()>wall )
        m_wall += Vector( -forceScalar, 0,0);

    else if ( m_pos.GetX()< -wall )
        m_wall += Vector(  forceScalar, 0,0);

    if ( m_pos.GetY()> wall )
        m_wall += Vector( 0, -forceScalar,0);

    else if ( m_pos.GetY()< -wall )
        m_wall += Vector( 0,  forceScalar,0);

    if ( m_pos.GetZ()>wall )
        m_wall += Vector( 0, 0,-forceScalar);

    else if ( m_pos.GetZ()<-wall )
        m_wall += Vector( 0, 0, forceScalar);

    m_wall = m_wall.Normalise();
}
//------------------------------------------------------------------------------------
void Ant::Update(uint32_t _time, const Trail& _trail, const std::vector<Ant*>& _antList,const SceneObject& _home, const SceneObject& _food)
{
    m_force = Vector(0,0,0);
    DetectObstacle(_antList);
    Wall();
#if 0
    RandomWalk();
    m_force = m_rand + m_wall*0.08;
    Move(_time);
    std::cout<<m_friction<<"@@@@@@@friction\n";
#endif
#if 1
    switch(m_state)
    {
        case HomeToFood:
            {
                if( Near(_food) )
                {
                    m_state = NearFood;
                }
                else
                {
                    m_state = FollowFoodPheromone;
                }
                #ifdef _DEBUG
                std::cout<<"Home to Food\n";
                #endif
            }
            break;
        case FollowFoodPheromone:
            { 
                #ifdef _DEBUG
                std::cout<<"Follow Food Pheromone \n";
                #endif
                if( DetectPheromone(ToFood, _trail))
                {
                    m_force = m_pheromone * kPheromone + m_obstacles * kObstacle + m_wall* kWall;
                    Move(_time);
                }
                else
                {
                    RandomWalk();
                    m_force = m_rand * kRand + m_wall * kWall + m_obstacles * kObstacle;
                    Move(_time);
                }
                m_state = HomeToFood;
            }
            break;
        case NearFood:
            {
                #ifdef _DEBUG
                std::cout<<"Near Food\n";
                #endif
                if( Arrive(_food) )
                {
                    m_force = Vector(0,0,0) - m_vel;
                    Move(_time);
                    m_state = FoodToHome;
                    #ifdef _DEBUG
                    std::cout<<"using arrive\n";
                    #endif
                }
                else
                {
                    Near(_food);
                    m_force = m_attraction * kAttract + m_obstacles * kObstacle + m_wall * kWall;
                    Move(_time);
                    m_state = NearFood;
                    #ifdef _DEBUG
                    std::cout<<"using attraction\n";
                    #endif
                }
            }
            break;
        case FoodToHome:
            {
                if( Near(_home) )
                {
                    m_state = NearHome;
                }
                else
                {
                    m_state = FollowHomePheromone;

                }
                #ifdef _DEBUG
                std::cout<<"FoodToHome!!!!!!!!!!!!!!!!!!!!\n";
                #endif
            }
            break;
        case FollowHomePheromone:
            {
                #ifdef _DEBUG
                std::cout<<"Follow home pheromone\n";
                #endif
                if(DetectPheromone(ToHome, _trail))
                {
                    m_force = m_pheromone * kPheromone + m_wall * kWall + m_obstacles * kObstacle;
                    #ifdef _DEBUG
                    std::cout<<m_pheromone<<"pheromone!!!!\n";
                    #endif
                    Move(_time);
                    #ifdef _DEBUG
                    std::cout<<"detected pheromone\n";
                    #endif
                }
                else
                {
                    RandomWalk();
                    m_force = m_rand * kRand+ m_wall * kWall + m_obstacles * kObstacle;
                    Move(_time);
                    #ifdef _DEBUG
                    std::cout<<m_rand<<"random\n";
                    std::cout<<m_force<<"random\n";
                    #endif
                }
                m_state = FoodToHome;
            }
            break;
        case NearHome:
            {
                if( Arrive(_home) )
                {
                    m_force = Vector(0,0,0)-m_vel;
                    Move(_time);
                    m_state = HomeToFood;
                }
                else
                {
                    m_state = NearHome;
                    Near(_home);
                    m_force = m_attraction * kAttract + m_obstacles * kObstacle + m_wall * kWall;
                    Move(_time);
                }
                #ifdef _DEBUG
                std::cout<<"NearHome\n";
                #endif
            }
            break;
        default:
            #ifdef _DEBUG
            std::cout<<"no such state\n";
            #endif
            break;
    }
    #endif
}
}//end of namespace
