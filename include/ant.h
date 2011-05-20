#ifndef __ANT_H__
#define __ANT_H__
#include <stdint.h>

#include "sceneObject.h"

namespace QtGLWindow
{
class Ant:public SceneObject
{
    public:

        ///\brief default constructor
        Ant();
        ~Ant();

        void Update(uint32_t _time);
        void Think();
        void Transform(uint32_t _time);

        bool m_foundFood;

    protected:
        void Translate(uint32_t _time);
        void Rotate();
        void Reset();
        double SetHeight();
        void Wall();
        void DetectPheromone();
        void DetectObstacle();
        void DetectFood();
        void DetectHome();
        void RandomWalk();
        
        uint32_t m_maxAccel;
        float m_friction;
        bool m_foundHome;
        bool m_foundPheromone;
        bool m_hit;
        int m_score;
        ///\counter for ant to walk and stop
        uint32_t m_walkCounter;
        Vector m_pheromone;
        Vector m_wall;
        Vector m_food;
        Vector m_home;
        Vector m_obstacles;
        float m_maxAngle;
};
#endif
}//end of namespace
