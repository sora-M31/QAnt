#ifndef _SCENEMANAGER_H_
#define _SCENEMANGER_H_

#include "sceneNode.h"
#include "sceneObject.h"
#include "flock.h"
#include "ant.h"
namespace QtGLWindow
{
class SceneManager
{
    public:
        SceneManager();
        ~SceneManager();

        void InitScene();
        void UpdateScene();

        SceneNode m_root;
        SceneObject* test;
        Flock* m_pFlock;
        Ant* m_pAnt;
        SceneObject* m_pEnv;
};//end of class
}//end of namespace
#endif //end of define
