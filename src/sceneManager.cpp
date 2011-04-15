#include "sceneManager.h"
namespace QtGLWindow
{
//------------------------------------------------------------------------------
SceneManager::SceneManager()
    :m_root(0),
     test(0)
{
    std::cout<<"initializing sceneManager\n";
}
//------------------------------------------------------------------------------
SceneManager::~SceneManager()
{
}
//------------------------------------------------------------------------------
void SceneManager::InitScene()
{
    test= new SceneObject;
    m_root.AddNext(test->m_node);
}
//------------------------------------------------------------------------------
void SceneManager::UpdateScene()
{
}
//------------------------------------------------------------------------------
}//end of namespace
