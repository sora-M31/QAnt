#include "ant.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Ant::Ant()
     :m_hit(false)
{
    m_maxAngle =5*3.14/180;
    m_maxAccel = 8;
    m_vel = Vector (0,0,0);
    m_friction = 0.09;
    m_walkCounter = rand();
    m_mass =0.1;
    m_type = kAnt;
    m_force = Vector(0,0,0);
    srand ( time(NULL) );
    m_pheromone = Vector(0,0,0);
    m_trans.SetTranslate(m_pos);
    m_trans.ApplyTransform();
    m_bound = 0.5;
    m_state = HomeToFood;
}
//------------------------------------------------------------------------------------
Ant::Ant(const Ant& _ant):SceneObject()
{
    this->m_maxAccel = _ant.m_maxAccel;
    this->m_maxAngle = _ant.m_maxAngle;
    this->m_friction = _ant.m_friction;
    this->m_hit = _ant.m_hit;
    this->m_walkCounter = _ant.m_walkCounter;
    this->m_mass = _ant.m_mass;
    this->m_type = _ant.m_type;
    this->m_pheromone = _ant.m_pheromone;
    this->m_node = _ant.m_node;
}
//------------------------------------------------------------------------------------
Ant Ant::operator = (const Ant& _ant)
{
    this->m_maxAccel = _ant.m_maxAccel;
    this->m_maxAngle = _ant.m_maxAngle;
    this->m_friction = _ant.m_friction;
    this->m_hit = _ant.m_hit;
    this->m_walkCounter = _ant.m_walkCounter;
    this->m_mass = _ant.m_mass;
    this->m_type = _ant.m_type;
    this->m_pheromone = _ant.m_pheromone;
    this->m_node = _ant.m_node;
    return *this;
}
//------------------------------------------------------------------------------------
Ant::~Ant()
{
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
        if( CheckNeighbor(*_trail.m_phrmTrail[i], 180*3.1415/180, 2) && (_trail.m_phrmTrail[i]->m_phrmType == _type) )
        {
            phrm = _trail.m_phrmTrail[i]->m_pos;// * ( _trail.m_phrmTrail[i]->m_maxAge - _trail.m_phrmTrail[i]->m_age );
            phrmNum++;
        }
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
    if( CheckNeighbor( _obj, 90,10) )
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
        m_rand = Vector( ((float)rand() / (float)RAND_MAX -0.5),  0, ((float)rand() / (float)RAND_MAX-0.5) ) *10;
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
    #if 1
    RandomWalk();
    m_force = m_rand + m_wall*0.08;
    Move(_time);
    std::cout<<m_friction<<"@@@@@@@friction\n";

    #endif
    #if 0

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
                std::cout<<"Home to Food\n";
            }
            break;
        case FollowFoodPheromone:
            {
                if( DetectPheromone(ToFood, _trail))
                {
                    m_force = m_pheromone + m_obstacles + m_wall;
                    Move(_time);
                }
                else
                {
                     #if 1
                    RandomWalk();
                    if( m_wall == Vector(0,0,0) )
                    {
                        m_force = m_rand + m_obstacles;
                    }
                    else
                    {
                        m_force = m_wall + m_obstacles;
                    }
                    Move(_time);
                    #endif
                }
                m_state = HomeToFood;
                std::cout<<"Follow Food Pheromone \n";
            }
            break;
        case NearFood:
            {

                if( Arrive(_food) )
                {
                     m_force = Vector(0,0,0)-m_vel*m_friction*20;
                    Move(_time);
                    m_state = FoodToHome;
                }
                else
                {
                    m_force = m_attraction*3 + m_obstacles *0.1+ m_wall*3;
                    Move(_time);
                    m_state = NearFood;
                }
                std::cout<<"Near Food\n";
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
                std::cout<<"FoodToHome!!!!!!!!!!!!!!!!!!!!\n";
            }
            break;
        case FollowHomePheromone:
            {
                if(DetectPheromone(ToHome, _trail))
                {
                    m_force = m_pheromone + m_wall +m_obstacles;
                    Move(_time);
                }
                else
                {
                    RandomWalk();
                    m_force = m_rand + m_wall + m_obstacles;
                }
                m_state = FoodToHome;

                std::cout<<"Follow home pheromone\n";
            }
            break;
        case NearHome:
            {
                m_force = m_attraction * 0.1 + m_obstacles + m_wall;
                Move(_time);
                if( Arrive(_home) )
                {
                    m_state = HomeToFood;
                }
                else
                {
                    m_state = NearHome;
                }
                std::cout<<"NearHome\n";
            }
            break;
        default:
            std::cout<<"no such state\n";
    }
    #endif
}
}//end of namespace
