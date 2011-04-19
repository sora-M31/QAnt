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
    test->Move(Vector(0,0.1,0));
    test->Rotate(10*3.1415926/180,Vector(0,0,1));
    test->Update();
}
//------------------------------------------------------------------------------
}//end of namespace
