#include <Colony.h>

namespace QtGLWindow
{
//----------------------------------------------------------------------------------------------------------------------
Colony::Colony()
{
    m_num=3;
    m_counter =0;
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
    if( m_counter%5 == 0)
    {
        for( uint32_t i=0;i<m_num;++i )
        {
            if ( (m_antList[i]->m_state == FoodToHome) || (m_antList[i]->m_state == NearHome) )
            {
                m_trail.AddPherom( new Pheromone( m_antList[i]->m_pos, ToFood ) );
            }
            else if( (m_antList[i]->m_state == HomeToFood) || m_antList[i]->m_state == NearFood)
            {
                m_trail.AddPherom( new Pheromone( m_antList[i]->m_pos, ToHome ) );
            }
        }
    }
    m_counter++;
    m_trail.DeleteEveporatedPherom();
}
//-----------------------------------------------------------------------------
void Colony::Update(const SceneObject& _home, const SceneObject& _food)
{
    for( uint32_t i=0; i<m_num; ++i)
    {
        m_antList[i]->Update(50,m_trail,m_antList,_home, _food);
    }
    UpdateTrail();
}
}//end of namespace
