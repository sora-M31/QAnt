#ifndef _SCENEMANAGER_H_
#define _SCENEMANGER_H_

#include "sceneNode.h"
#include "sceneObject.h"
#include "colony.h"
namespace QtGLWindow
{
class SceneManager
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        SceneManager();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~SceneManager();
        // --------------------------------------------------------------------------
        /// \brief Initialize scene
        void InitScene(uint32_t _num, float _phe, float _obs, float _wall, float _rand);
        //void InitScene();
        // --------------------------------------------------------------------------
        /// \brief Reset scene to be ready to restart the simulation
        void ResetScene();
        // --------------------------------------------------------------------------
        /// \brief Update scene
        void UpdateScene();
        void SetPheromone(float _phe);
        void SetObstacle(float _obs);
        void SetWall(float _wall);
        void SetRand(float _rand);
        /// \m_root
        SceneNode m_root;
        // --------------------------------------------------------------------------
        /// \brief Pointer to colony
        Colony* m_pColony;
        // --------------------------------------------------------------------------
        /// \brief Pointer to sceneobject
        SceneObject* m_pEnv;
};//end of class
}//end of namespace
#endif //end of define
