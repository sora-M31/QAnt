#include "sceneManager.h"
namespace QtGLWindow
{
//------------------------------------------------------------------------------
SceneManager::SceneManager()
    :m_root(0),m_pColony(0)
{
#ifdef _DEBUG
    std::cout<<"initializing sceneManager\n";
#endif
    //m_pColony = new Colony;
    m_pEnv = new SceneObject;
}
//------------------------------------------------------------------------------
SceneManager::~SceneManager()
{
    if (m_pColony!=0)
        delete m_pColony;
    if (m_pEnv !=0)
        delete m_pEnv;
}
//------------------------------------------------------------------------------
void SceneManager::SetPheromone(float _phe)
{
    for( uint32_t i; i< m_pColony->m_num; ++i)
    {
        m_pColony->m_antList[i]->SetkPheromone(_phe);
    }

}
//------------------------------------------------------------------------------
void SceneManager::SetObstacle(float _obs)
{
    for( uint32_t i; i< m_pColony->m_num; ++i)
    {
        m_pColony->m_antList[i]->SetkObstacle(_obs);
    }

}
//------------------------------------------------------------------------------
void SceneManager::SetWall(float _wall)
{
    for( uint32_t i; i< m_pColony->m_num;++i)
    {
        m_pColony->m_antList[i]->SetkWall(_wall);
    }

}
//------------------------------------------------------------------------------
void SceneManager::SetRand(float _rand)
{
    for( uint32_t i; i< m_pColony->m_num; ++i)
    {
        m_pColony->m_antList[i]->SetkRand(_rand);
    }

}
//------------------------------------------------------------------------------
void SceneManager::InitScene(uint32_t _num, float _phe, float _obs, float _wall, float _rand)
{
    m_pColony = new Colony();
    m_pColony->Init(_num, _phe, _obs, _wall, _rand);
    //connect nodes
    m_root.AddNext(m_pEnv->m_node);
    m_pEnv->m_node.AddNext(m_pColony->m_pFood->m_node);
    m_pColony->m_pFood->m_node.AddNext(m_pColony->m_pHome->m_node);
    m_pColony->m_pHome->m_node.AddNext(m_pColony->m_antList[0]->m_node);
#if 1
    uint32_t num = m_pColony->m_antList.size()-1;
    for( uint32_t i=0; i<num; ++i)
    {
        m_pColony->m_antList[i]->m_node.AddNext(m_pColony->m_antList[i+1]->m_node);
    }
#endif
}
//------------------------------------------------------------------------------
void SceneManager::ResetScene()
{
    m_pColony->Reset();
}
//-----------------------------------------------------------------:wq-------------
void SceneManager::UpdateScene()
{

    m_pColony->Update();
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
}
//------------------------------------------------------------------------------
}//end of namespace
