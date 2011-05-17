#include <Colony.h>

namespace QtGLWindow
{
//----------------------------------------------------------------------------------------------------------------------
Colony::Colony()
{
    for(uint32_t i=0;i<m_num; ++i)
    {
        m_antList.push_back(Ant());
    }
}
//----------------------------------------------------------------------------------------------------------------------
Colony::~Colony()
{}
//----------------------------------------------------------------------------------------------------------------------
void Colony::UpdateTrail()
{
  for( uint32_t i=0;i<m_num;++i )
  {
      /*
      Pheromone phe;
      phe.m_pos=m_antList[i].m_pos;
      phe.m_toFood=m_antList[i].m_foundfood;
      m_pheromTrail.AddPherom(phe); 
      */
      if (m_antList[i].m_foundFood)
      m_pheromTrail.AddPherom( Pheromone( m_antList[i].m_pos, ToFood ) );
      else
      m_pheromTrail.AddPherom( Pheromone( m_antList[i].m_pos, ToHome ) );
  }
  m_pheromTrail.DeleteEveporatedPherom();
}
//-----------------------------------------------------------------------------
void Colony::Update()
{
}
//-----------------------------------------------------------------------------
void Colony::ApplyRule()
{
}
}//end of namespace
