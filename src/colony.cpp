#include <Colony.h>

namespace QtGLWindow
{
//----------------------------------------------------------------------------------------------------------------------
Colony::Colony()
{
    m_num=10;
    for(uint32_t i=0;i<m_num; ++i)
    {
        m_antList.push_back(new Ant());
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
        if (m_antList[i]->m_foundFood)
        {
            m_trail.AddPherom( new Pheromone( m_antList[i]->m_pos, ToFood ) );
        }
        else
        {
            m_trail.AddPherom( new Pheromone( m_antList[i]->m_pos, ToHome ) );
        }
    }
    m_trail.DeleteEveporatedPherom();
}
//-----------------------------------------------------------------------------
void Colony::Update()
{
    for( uint32_t i=0; i<m_num; ++i)
    {
        m_antList[i]->Update(50,m_trail,m_antList);
    }
    UpdateTrail();
}
}//end of namespace
