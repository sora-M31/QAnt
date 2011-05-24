#include "trail.h"
namespace QtGLWindow
{
//------------------------------------------------------------------------------------
Trail::Trail( )
{
}
//------------------------------------------------------------------------------------
Trail::~Trail()
{
}
//------------------------------------------------------------------------------------
void Trail::AddPherom(Pheromone* _phe)
{
  m_phrmTrail.push_back(_phe);
}
//------------------------------------------------------------------------------------
void Trail::DeleteEveporatedPherom()
{
    uint32_t num=m_phrmTrail.size();
    for (uint32_t i=0;i< num;i++)
    {
        m_phrmTrail[i]->Evaporate();
        if(m_phrmTrail[i]->m_age > m_phrmTrail[i]->m_maxAge)
        {
            m_phrmTrail.erase(m_phrmTrail.begin()+i);
        }
    }
}
}//end of namespace
