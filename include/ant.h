#ifndef __ANT_H__
#define __ANT_H__
#include <stdint.h>
#include <list>
#include "sceneObject.h"
#include "trail.h"
#include "colony.h"
namespace QtGLWindow
{
class Colony;
class Ant:public SceneObject
{
    public:

        ///\brief default constructor
        Ant(Colony* _mycolony);
        ~Ant();
        Ant(const Ant& _ant);
        Ant operator = (const Ant& _ant);
        void Move(uint32_t _timte);
        void Reset();
        void SetID(uint32_t _id);
        uint32_t GetID();
        void Update(uint32_t _time);//, const Trail& _trail,std::list<Ant*> _antList,const SceneObject& _home, const SceneObject& _food);

        AntState m_state;

    protected:
        void SetHeight();
        bool Arrive(const SceneObject& _obj);
        bool Near(const SceneObject& _obj);
        bool DetectPheromone(PhrmType _type);//, const Trail& _trail);

        //void DetectObstacle(const std::vector<Ant*>& _antList);
        void DetectObstacle();//const std::list<Ant*>& _antList);
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
        float m_speed;
        float kPheromone;
        float kWall;
        float kAttract;
        float kObstacle;
        float kRand;
        float kWalk;
        float kBrake;
        uint32_t m_ID;
        Colony* m_pColony;
    private:
        Ant();
};
}//end of namespace
#endif
