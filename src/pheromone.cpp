#include "Pheromone.h"
namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Pheromone::Pheromone(Vector _pos, PhrmType _type)
    :m_age(0),
    m_phrmType(_type),
    m_maxAge(900)
{
    m_pos = _pos;
    m_type = kPhe;
    m_bound = 0.5;
}
//------------------------------------------------------------------------------------
Pheromone::Pheromone(const Pheromone& _phe):SceneObject()
{
    m_pos = _phe.m_pos;
    m_phrmType = _phe.m_phrmType;
    m_age = _phe.m_age;
    m_maxAge = _phe.m_maxAge;
    m_node = _phe.m_node;
    m_type = _phe.m_type;
}
//------------------------------------------------------------------------------------
Pheromone Pheromone::operator = (const Pheromone& _phe)
{
    m_pos = _phe.m_pos;
    m_phrmType = _phe.m_phrmType;
    m_age = _phe.m_age;
    m_maxAge = _phe.m_maxAge;
    m_node = _phe.m_node;
    m_type = _phe.m_type;
    return *this;
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
