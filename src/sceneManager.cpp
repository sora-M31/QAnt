#include "sceneManager.h"
namespace QtGLWindow
{
//------------------------------------------------------------------------------
SceneManager::SceneManager()
    :m_root(0),
     test(0)
{
    std::cout<<"initializing sceneManager\n";
    //aggr,separ, align, wall
  //  m_pFlock = new Flock(500,0.2,0.3,0.3,0.2);
    m_pColony = new Colony;
    m_pEnv = new SceneObject;
    m_pFood = new SceneObject(Vector(10,0,10),0.5,kFood);
    m_pHome = new SceneObject(Vector(0,0,0),0.5,kHome);
    ptest = new Pheromone(Vector(0,0,0),ToHome);
}
//------------------------------------------------------------------------------
SceneManager::~SceneManager()
{
    delete m_pColony;
    delete m_pEnv;
    delete m_pFood;
    delete m_pHome;
    delete ptest;
}
//------------------------------------------------------------------------------
void SceneManager::InitScene()
{
/*
    m_root.AddNext(m_pFlock->m_boidList[0].m_node);
    for(int i =0; i<m_pFlock->GetNum()-1; ++i)
    {
        m_pFlock->m_boidList[i].m_node.AddNext(m_pFlock->m_boidList[i+1].m_node);
    }
*/
    m_root.AddNext(m_pEnv->m_node);
    m_pEnv->m_node.AddNext(m_pFood->m_node);
    m_pFood->m_node.AddNext(m_pHome->m_node);
    m_pHome->m_node.AddNext(m_pColony->m_antList[0]->m_node);



    uint32_t num = m_pColony->m_antList.size()-1;
    for( uint32_t i=0; i<num; ++i)
    {
        m_pColony->m_antList[i]->m_node.AddNext(m_pColony->m_antList[i+1]->m_node);
    }
    //m_pColony->m_antList[num].m_node.AddNext(ptest->m_node);

}
//------------------------------------------------------------------------------
void SceneManager::UpdateScene()
{
    m_pColony->Update(*m_pHome, *m_pFood);
#if 1
    uint32_t num = m_pColony->m_antList.size()-1;
    size_t count = m_pColony->m_trail.m_phrmTrail.size();
    if(count>0)
    {
        m_pColony->m_antList[num]->m_node.AddNext(m_pColony->m_trail.m_phrmTrail[0]->m_node);
        #if 1
        if(count>1)
        {
            for( uint32_t i=0; i<count-1; ++i)
            {
                m_pColony->m_trail.m_phrmTrail[i]->m_node.AddNext(m_pColony->m_trail.m_phrmTrail[i+1]->m_node);
            }
        }
        m_pColony->m_trail.m_phrmTrail[count-1]->m_node.m_pNext = NULL;
        #endif
    }
#endif
   // m_pFlock->Update(50);
}
//------------------------------------------------------------------------------
}//end of namespace
