#ifndef _SCENEMANAGER_H_
#define _SCENEMANGER_H_


#include "sceneNode.h"
#include "sceneObject.h"
namespace QtGLWindow
{
class SceneManager
{
    public:
        SceneManager();
        ~SceneManager();

        void InitScene();
        void UpdateScene();
        void UpdateScene(Vector _pos, float _theta, Vector _axis);

        SceneNode m_root;
        SceneObject* test;
};//end of class
}//end of namespace
#endif //end of define
