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
    m_pAnt = new Ant();
}
//------------------------------------------------------------------------------
SceneManager::~SceneManager()
{
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
    m_root.AddNext(m_pAnt->m_node);
}
//------------------------------------------------------------------------------
void SceneManager::UpdateScene()
{
   // m_pFlock->Update(50);
    m_pAnt->Update(50);
}
//------------------------------------------------------------------------------
}//end of namespace
