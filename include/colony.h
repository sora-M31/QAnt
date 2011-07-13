#ifndef __COLONY_H__
#define __COLONY_H__
#include <vector>
#include <list>

#include "ant.h"
#include "trail.h"

namespace QtGLWindow
{
typedef std::list<Ant*> Antlist;
class Colony
{
    public:
        Colony();
        ~Colony();
        void Reset();
        void Emit(uint32_t _interval);
        void Update(const SceneObject& _home, const SceneObject& _food);
        void ApplyRule();
        void UpdateTrail(); 
        void Move();
        void UpdateID();

        /// number of ant in a colony
        uint32_t m_num;
        uint32_t m_activeNum;
        /// the list to store ants
        std::vector<Ant*> m_antList;
        /// trail create by ants in the list
        Trail m_trail;
        uint32_t m_counter;
        std::vector<Antlist> Cell;
        float const cellSize;
        float const worldSize;
    private:
        inline uint32_t GetCellCount();
};//end of class
}//end of namespace
#endif//
