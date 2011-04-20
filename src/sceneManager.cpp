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
void SceneManager::UpdateScene(Vector _pos, float _theta, Vector _axis)
{
    test->Move(_pos);
    test->Rotate(_theta,_axis);
    test->Update();
}
//------------------------------------------------------------------------------
}//end of namespace
