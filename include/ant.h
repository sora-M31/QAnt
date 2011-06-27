#ifndef __ANT_H__
#define __ANT_H__
#include <stdint.h>

#include "sceneObject.h"
#include "trail.h"

namespace QtGLWindow
{
class Ant:public SceneObject
{
    public:

        ///\brief default constructor
        Ant();
        ~Ant();
        Ant(const Ant& _ant);
        Ant operator = (const Ant& _ant);

        void Update(uint32_t _time, const Trail& _trail,const std::vector<Ant*>& _antList,const SceneObject& _home, const SceneObject& _food);

        AntState m_state;

    protected:
        void SetHeight();
        bool Arrive(const SceneObject& _obj);
        bool Near(const SceneObject& _obj);
        bool DetectPheromone(PhrmType _type, const Trail& _trail);

        void DetectObstacle(const std::vector<Ant*>& _antList);
        void RandomWalk();
        void Wall();
        
        bool m_hit;
        int m_score;
        ///\counter for ant to walk and stop
        Vector m_pheromone;
        Vector m_wall;
        Vector m_attraction;
        Vector m_obstacles;
        ///\force when random walking
        Vector m_rand;
};
#endif
}//end of namespace
