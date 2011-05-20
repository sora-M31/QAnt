#include "ant.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Ant::Ant()
    :m_foundFood(false),
     m_maxAccel(10),
     m_friction(5),
     m_foundPheromone(false),
     m_hit(false),
     m_maxAngle(10)
{
    m_walkCounter = rand();
    m_mass =1;
    m_type = kAnt;
    m_pheromone = Vector(0,0,0);
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
    this->RotateAxis();
}
//------------------------------------------------------------------------------------
void Ant::DetectPheromone()
{}
//------------------------------------------------------------------------------------
void Ant::DetectObstacle()
{}
//------------------------------------------------------------------------------------
void Ant::DetectFood()
{}
//------------------------------------------------------------------------------------
void Ant::DetectHome()
{}
//------------------------------------------------------------------------------------
void Ant::RandomWalk()
{
    const uint32_t frequency = 100;
    if(m_walkCounter%frequency==0)
    {
        m_force = Vector(rand(),rand(),rand());
        m_walkCounter++;
    }
    else
    {
        m_force = m_axisX*m_maxAccel*m_mass;
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
}
//------------------------------------------------------------------------------------
void Ant::Update(uint32_t _time)
{
    Think();
    Transform(_time);
}
//------------------------------------------------------------------------------------
void Ant::Think()
{
    if(m_foundFood)
    {
        DetectHome();
        if(!m_foundHome)
        {
            DetectPheromone();
        }
    }
    else
    {

        DetectFood();
        if(!m_foundFood)
        {
            DetectPheromone();
            if(!m_foundPheromone)
            {
                RandomWalk();
            }
        }
    }
    DetectObstacle();
    Wall();
}
//------------------------------------------------------------------------------------
void Ant::Transform(uint32_t _time)
{
    Rotate();
    m_accel = (m_axisX*m_maxAccel*m_mass - m_vel * m_friction)/m_mass;
    Translate(_time);
}
}//end of namespace
