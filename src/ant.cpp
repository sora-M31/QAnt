#include "ant.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Ant::Ant()
    :m_foundFood(false),
     m_maxAccel(5),
     m_friction(5),
     m_foundPheromone(false),
     m_hit(false)
{
    m_maxAngle = 10*3.14/180;
    m_walkCounter = rand();
    m_mass =1;
    m_type = kAnt;
    m_force = Vector(0,0,0);
    srand ( time(NULL) );
    m_pheromone = Vector(0,0,0);
    m_pos = Vector(rand(),0,rand());
    m_trans.SetTranslate(m_pos);
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------------
Ant::Ant(const Ant& _ant):SceneObject()
{
    this->m_foundFood = _ant.m_foundFood;
    this->m_maxAccel = _ant.m_maxAccel;
    this->m_maxAngle = _ant.m_maxAngle;
    this->m_friction = _ant.m_friction;
    this->m_foundPheromone = _ant.m_foundPheromone;
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
    this->m_foundFood = _ant.m_foundFood;
    this->m_maxAccel = _ant.m_maxAccel;
    this->m_maxAngle = _ant.m_maxAngle;
    this->m_friction = _ant.m_friction;
    this->m_foundPheromone = _ant.m_foundPheromone;
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
void Ant::Reset()
{
  m_foundPheromone=false;
  m_foundFood=false;
  m_hit=false;
}
//------------------------------------------------------------------------------------
void Ant::Translate(uint32_t _time)
{
    float delta_t = _time*0.001 ;
    Vector pos = (m_vel*delta_t + m_accel * delta_t * delta_t /2);
    m_vel += ( m_accel * delta_t );

    m_pos +=pos;
    m_trans.SetTranslate(pos);
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------------
bool Ant::CheckNeighbor(const SceneObject& _obj, uint32_t _angle, uint32_t _rad)
{
    //*
    Vector relDis = _obj.m_pos - m_pos;
    if (   (relDis.AngleBetween(this->m_axisX) < _angle)
        && (relDis.Length() < _rad) )
    {
        return true;
    }
    else
    {
        return false;
    }//*/
    //return true;
}
//------------------------------------------------------------------------------------
void Ant::Rotate()
{
    float theta = m_axisX.AngleBetween( m_force);


    Vector vector = (m_axisX.Cross( m_force)).Normalise();

    if (theta > m_maxAngle)
    {
        theta = m_maxAngle;
    }
    m_trans.SetRotation( theta, vector);
    m_trans.ApplyTransform();
    std::cout<<m_axisX<<"before axis\n";
    std::cout<<theta<<"theta\n";
    SceneObject::RotateAxis();
    std::cout<<m_axisX<<"after axis\n";
}
//------------------------------------------------------------------------------------
void Ant::DetectPheromone(PhrmType _type, const Trail& _trail)
{
    Vector phrmCentre(0,0,0);
    uint32_t phrmNum(0);
    uint32_t num =_trail.m_phrmTrail.size();
    for( uint32_t i=0; i< num; ++i)
    {
        Vector phrm;
        if( CheckNeighbor(_trail.m_phrmTrail[i], 100, 3) && (_trail.m_phrmTrail[i].m_phrmType == _type) )
        {
            phrm = _trail.m_phrmTrail[i].m_pos * (_trail.m_phrmTrail[i].m_maxAge - _trail.m_phrmTrail[i]. m_age);
            phrmNum++;
        }
        phrmCentre += phrm;
        phrmCentre /= phrmNum;
    }
    Vector force = (phrmCentre - this->m_pos).Normalise();
    m_force += force;
}
//------------------------------------------------------------------------------------
void Ant::DetectObstacle()
{
}
//------------------------------------------------------------------------------------
void Ant::DetectFood()
{

}
//------------------------------------------------------------------------------------
void Ant::DetectHome()
{

}
//------------------------------------------------------------------------------------
void Ant::RandomWalk()
{
    const uint32_t frequency = 100;

    std::cout<<m_walkCounter<<" counter\n";
    if(m_walkCounter%frequency==0)
    {
        m_force = Vector((float)rand()/(float)RAND_MAX * 10, 0, (float)rand()/(float)RAND_MAX * 10);
        std::cout<<m_force<<" calling randomwalk\n";
        m_walkCounter++;
    }
    else
    {
        m_force = m_axisX*m_maxAccel*m_mass;
        std::cout<<m_force<<" randomwalk\n";
        m_walkCounter++;
    }
}
//------------------------------------------------------------------------------------
double Ant::SetHeight()
{
    return 0;
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
    const float blank = 6;
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
    m_force += m_wall*10;
    std::cout<<m_wall<<"  wall\n";
}
//------------------------------------------------------------------------------------
void Ant::Update(uint32_t _time, const Trail& _trail)
{
    Think(_trail);
    Move(_time);
}
//------------------------------------------------------------------------------------
void Ant::Think(const Trail& _trail)
{
    #if 0
    if(m_foundFood)
    {
        DetectHome();
        if(!m_foundHome)
        {
            DetectPheromone(ToHome,_trail);
        }
    }
    else
    {

        DetectFood();
        if(!m_foundFood)
        {
            DetectPheromone(ToFood,_trail);
            if(!m_foundPheromone)
            {
                RandomWalk();
            }
        }
    }
    #endif
    RandomWalk();
    DetectObstacle();
    Wall();
}
//------------------------------------------------------------------------------------
void Ant::Move(uint32_t _time)
{
    std::cout<<m_force<<"    raw force\n";
    Rotate();

    float scalar = m_force.Length();

    if (scalar > m_maxAccel)
    {
        scalar = m_maxAccel;
    }
    m_force =m_axisX * scalar;

    std::cout<<m_force<<"    rotated force\n";

    m_accel = (m_force -m_vel*m_friction) / m_mass;
    Translate(_time);
}
}//end of namespace
