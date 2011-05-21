#ifndef __COLONY_H__
#define __COLONY_H__
#include <vector>

#include "ant.h"
#include "trail.h"
namespace QtGLWindow
{
class Colony
{
    public:
        Colony();
        ~Colony();
        void Update();
        void ApplyRule();

        void UpdateTrail();

        void Move();

        /// number of ant in a colony
        uint32_t m_num;
        /// the list to store ants
        std::vector<Ant> m_antList;
        /// trail create by ants in the list
        Trail m_trail;
};//end of class
}//end of namespace
#endif//
