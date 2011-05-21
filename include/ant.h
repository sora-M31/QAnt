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

        void Update(uint32_t _time, const Trail& _trail);
        void Think(const Trail& _trail);
        void Transform(uint32_t _time);

        bool m_foundFood;

    protected:
        bool CheckNeighbor(const SceneObject& _obj, uint32_t _angle, uint32_t _rad);
        void Translate(uint32_t _time);
        void Rotate();
        void Reset();
        double SetHeight();
        void Wall();
        void DetectPheromone(PhrmType _type, const Trail& _trail);
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
