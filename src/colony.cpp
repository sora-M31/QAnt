#include <Colony.h>

namespace QtGLWindow
{
//----------------------------------------------------------------------------------------------------------------------
Colony::Colony()
    :cellSize(12.0),worldSize(60.0)
{
    m_num =50;
    m_activeNum = 1;
    m_counter =0;

    for(uint32_t i=0;i<m_num; ++i)
    {
        m_antList.push_back(new Ant());
    }

    uint32_t cellNum = GetCellCount();
    std::cout<<cellNum;
    for(uint32_t i =0; i< cellNum; ++i)
    {
        Cell.push_back(Antlist());
    }
#if 1
    Vector _pos(0,0,0);
    for(uint32_t i=0; i<m_num; ++i)
    {
        uint32_t ID = Hash(_pos, 12.0,60.0);
        //should write a function to initialize ant at different initial position like Ant(_pos);
        Cell[ID].push_back( new Ant() );
    }

    #endif
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::UpdateID()
{
#if 1
    uint32_t cellNum = GetCellCount();
    for( uint32_t id =0; id< cellNum; id++)
    {
        std::list<Ant*>::iterator it;
        for(it =Cell[id].begin(); it!=Cell[id].end();++it)
        {
            uint32_t newId =  Hash( (*it)->m_pos, 12.0, 60.0 );
            if (newId != id)
            {
                Cell[newId].push_back(*it);
                Cell[id].erase(it);
            }
        }
    }
#endif
}
//----------------------------------------------------------------------------------------------------------------------
Colony::~Colony()
{
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::Emit(uint32_t _interval)
{
   if (m_counter%_interval == 0)
   {
        m_activeNum +=1;
   }
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::Reset()
{
    for( uint32_t i =0; i<m_num; ++i)
    {
        m_antList[i]->Reset();
    }
    m_trail.Reset();
    m_activeNum = 1;
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::UpdateTrail()
{
    if( m_counter%5 == 0)
    {
        for( uint32_t i=0;i<m_activeNum;++i )
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
    if (m_activeNum < m_num) Emit(30);
    for( uint32_t i=0; i<m_activeNum; ++i)
    {
        m_antList[i]->Update(50,m_trail,m_antList,_home, _food);
    }
    UpdateTrail();
}
inline uint32_t Colony::GetCellCount()
{
    uint32_t count= (uint32_t)worldSize/cellSize;
    return count * count;
}
}//end of namespace
