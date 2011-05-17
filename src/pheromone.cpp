#include "Pheromone.h"
namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Pheromone::Pheromone(Vector _pos, PhrmType _type)
    :m_age(0),
    m_phrmType(_type),
    m_maxAge(1000)
{
    m_pos = _pos;
}
//------------------------------------------------------------------------------------
Pheromone::~Pheromone()
{}
//------------------------------------------------------------------------------------
void Pheromone::Evaporate()
{
    m_age++;
}
}//end of namespace
