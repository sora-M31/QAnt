#include "ant.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Ant::Ant()
    :m_maxAccel(10),
     m_friction(5),
     m_foundFood(false),
     m_hit(false)
{
    m_walkCounter = rand();
    m_mass =1;
}
//------------------------------------------------------------------------------------
Ant::~Ant()
{
}
//------------------------------------------------------------------------------------
void Ant::Reset()
{
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
    m_walkCounter++;
}
//------------------------------------------------------------------------------------
void Ant::Rotate()
{
}
//------------------------------------------------------------------------------------
bool Ant::CheckPheromone()
{
    return true;
}
//------------------------------------------------------------------------------------
double Ant::SetHeight()
{
    return 0;
}
//------------------------------------------------------------------------------------
void Ant::Update(uint32_t _time)
{
    if(m_foundFood)
    {
        //move towards force
        //Rotate(_tforce )
        //Translate()
    }
    else
    {
        //move randomly
        //Rotate(random)
        if(m_walkCounter%100==0)
        {
            SceneObject::Rotate(10,'Y');
            this->m_walkCounter++;
        }
        else
        {
            m_force = m_axisX * m_maxAccel * m_mass - m_vel *m_friction;
            m_accel = m_force /m_mass;
            Translate(_time);
        };
        std::cout<<m_vel<<"speed \n";
    }
}
}//end of namespace
