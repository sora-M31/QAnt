#include <Colony.h>

namespace QtGLWindow
{
//----------------------------------------------------------------------------------------------------------------------
Colony::Colony()
    :cellSize(12.0),worldSize(60.0)
{
    m_num =50;
    m_activeNum = 0;
    m_counter =0;
    #if 1
    for(uint32_t i=0;i<m_num; ++i)
    {
        m_antList.push_back(new Ant(this));
    }
   #endif
    uint32_t cellNum = GetCellCount()*GetCellCount();
    for(uint32_t i =0; i< cellNum; ++i)
    {
        Cell.push_back(Antlist());
    }
    m_pFood = new SceneObject(Vector(20,0,10),0.5,kFood);
    m_pHome = new SceneObject(Vector(0,0,0),0.5,kHome);
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
                (*it)->SetID(newId);
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
    //delete new
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::Emit(uint32_t _interval)
{
   if (m_counter%_interval == 0)
   {
        uint32_t ID = Hash(m_antList[m_activeNum]->m_pos, 12.0,60.0);
        Cell[ID].push_back(m_antList[m_activeNum]);
        m_antList[m_activeNum]->SetID(ID);
        m_activeNum +=1;
   }
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::Reset()
{
#if 0
    for( uint32_t i =0; i<m_num; ++i)
    {
        m_antList[i]->Reset();
    }
#endif
    uint32_t cellNum = GetCellCount();
    for( uint32_t id =0; id< cellNum; id++)
    {
        std::list<Ant*>::iterator it;
        for(it =Cell[id].begin(); it!=Cell[id].end();++it)
        {
            (*it)->Reset();
        }
    }
    m_trail.Reset();
    m_activeNum = 1;
}
//----------------------------------------------------------------------------------------------------------------------
void Colony::UpdateTrail()
{
    if( m_counter%5 == 0)
    {
#if 0
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
#endif
        uint32_t cellNum = GetCellCount();
        for( uint32_t id =0; id< cellNum; id++)
        {
            std::list<Ant*>::iterator it;
            for(it =Cell[id].begin(); it!=Cell[id].end();++it)
            {
                if ( ((*it)->m_state == FoodToHome) || ((*it)->m_state == NearHome) )
                {
                    m_trail.AddPherom( new Pheromone( (*it)->m_pos, ToFood ) );
                }
                else if( ((*it)->m_state == HomeToFood) || ((*it)->m_state == NearFood))
                {
                    m_trail.AddPherom( new Pheromone( (*it)->m_pos, ToHome ) );
                }
            }
        }

    }
    m_counter++;
    m_trail.DeleteEveporatedPherom();
}
//-----------------------------------------------------------------------------
void Colony::Update()//const SceneObject& _home, const SceneObject& _food)
{
    if (m_activeNum < m_num)
    {
        Emit(30);
    }
#if 0
    for( uint32_t i=0; i<m_activeNum; ++i)
    {
        m_antList[i]->Update(50,m_trail,m_antList,_home, _food);
    }
#endif
    uint32_t cellNum = GetCellCount();
    for( uint32_t id =0; id< cellNum; id++)
    {
        std::list<Ant*>::iterator it;
        for(it =Cell[id].begin(); it!=Cell[id].end();++it)
        {
            (*it)->SetID(id);
            (*it)->Update(50);//,m_trail, Cell[id], _home, _food);
        }
    }
    UpdateTrail();
    UpdateID();
}
//-----------------------------------------------------------------------------
inline uint32_t Colony::GetCellCount()
{
    uint32_t count= (uint32_t)worldSize/cellSize;
    return count*count;
}
//-----------------------------------------------------------------------------
std::list<Ant*> Colony::GetLocalList(Ant* _pAnt)
{
#if 0
    if right top
    {

    }
    else if left top
    {

    }
    else if righ bottom
    {

    }
    else if left  bottom
    {

    }
#endif
    // id-1+cellNum | id +cellNum  |id +1+cellNum
    //--------------|--------------|--------------
    //   id-1       |      id      |    id+1
    //--------------|--------------|--------------
    // id-1-cellNum | id -cellNum  | id+1-cellNum
    //
    uint32_t cellNum = (uint32_t)worldSize/cellSize;
    uint32_t id = _pAnt->GetID();
    std::list<Ant*> neighbour;
    std::list<Ant*>::iterator it;

    if( Cell[id].size()!= 0 )
    for( it = Cell[id].begin(); it!=Cell[id].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if(id%cellNum >0)
    for( it = Cell[id-1].begin(); it!=Cell[id-1].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if(id%cellNum <cellNum-1)
    for( it = Cell[id+1].begin(); it!=Cell[id+1].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if(id/cellNum > 0)
    for( it = Cell[id-cellNum].begin(); it!=Cell[id-cellNum].end(); ++it )
    {
        neighbour.push_back(*it);
    }
#if 1
    for( it = Cell[id+cellNum].begin(); it!=Cell[id+cellNum].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if( ((id%cellNum) > 0) && ((id/cellNum)>0) )
    for( it = Cell[id-1-cellNum].begin(); it!=Cell[id-1-cellNum].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if( ((id%cellNum) > 0) && ((id/cellNum)<(cellNum-1)) )
    for( it = Cell[id-1+cellNum].begin(); it!=Cell[id-1+cellNum].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if( ((id%cellNum) < (cellNum-1)) && (id/cellNum>0) )
    for( it = Cell[id+1-cellNum].begin(); it!=Cell[id+1-cellNum].end(); ++it )
    {
        neighbour.push_back(*it);
    }
    if( ((id%cellNum) <(cellNum-1)) && ((id/cellNum)<(cellNum-1)) )
    for( it = Cell[id+1+cellNum].begin(); it!=Cell[id+1+cellNum].end(); ++it )
    {
        if (*it !=0 )
        neighbour.push_back(*it);
    }
#endif
    return neighbour;
}
//-----------------------------------------------------------------------------
const Trail& Colony::GetTrail()
{
    return m_trail;
}
//-----------------------------------------------------------------------------
const SceneObject& Colony::GetFood()
{
    return *m_pFood;
}
//-----------------------------------------------------------------------------
const SceneObject& Colony::GetHome()
{
    return *m_pHome;
}
}//end of namespace
