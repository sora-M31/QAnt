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
        if (m_antList[i].m_foundFood)
        {
            m_pheromTrail.AddPherom( Pheromone( m_antList[i].m_pos, ToFood ) );
        }
        else
        {
            m_pheromTrail.AddPherom( Pheromone( m_antList[i].m_pos, ToHome ) );
        }
    }
    m_pheromTrail.DeleteEveporatedPherom();
}
//-----------------------------------------------------------------------------
void Colony::Update()
{
    UpdateTrail();
    for( uint32_t i=0; i<m_num; ++i)
    {
        m_antList[i].Update(50);
    }
}
}//end of namespace
