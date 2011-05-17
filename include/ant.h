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

        void Translate(uint32_t _time);
        void Rotate();
        void Reset();
        void Wall();
        void DetectPheromone();
        void DetectObstacle();
        void DetectFood();
        void DetectHome();
        double SetHeight();
        void Update(uint32_t _time);

        uint32_t m_maxAccel;
        float m_friction;
        bool m_foundFood;
        bool m_foundPheromone;
        bool m_hit;
        int m_score;
        ///\counter for ant to walk and stop
        uint32_t m_walkCounter;
        Vector m_pheromone;
        Vector m_wall;
        float m_maxAngle;
};
#endif
}//end of namespace
