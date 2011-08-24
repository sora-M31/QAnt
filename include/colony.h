#ifndef __COLONY_H__
#define __COLONY_H__
#include <vector>
#include <list>

#include "ant.h"
#include "trail.h"

namespace QtGLWindow
{
class Ant;
typedef std::list<Ant*> Antlist;
class Colony
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        Colony();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Colony();
        // --------------------------------------------------------------------------
        /// \brief Reset all ants status
        void Reset();
        // --------------------------------------------------------------------------
        /// \brief Emit ants
        /// \param _interval
        void Emit(uint32_t _interval);
        // --------------------------------------------------------------------------
        /// \brief Update status of ants
        void Update();
        // --------------------------------------------------------------------------
        /// \brief Update trail
        void UpdateTrail(); 
        // --------------------------------------------------------------------------
        /// \brief Move all ants
        void Move();
        // --------------------------------------------------------------------------
        /// \brief Update hashing id
        void UpdateID();
        // --------------------------------------------------------------------------
        /// \brief Get a ant list which is considered to be neighbor of the passed in ant
        /// \param _pAnt pointer to ant which needs a neighbor list
        /// \return Ant list
        Antlist GetLocalList(Ant* _pAnt);
        // --------------------------------------------------------------------------
        /// \brief Get access to the trail of colony
        /// \return Reference of the trail
        const Trail& GetTrail();
        // --------------------------------------------------------------------------
        /// \brief Get access to food 
        /// \return Reference of food
        const SceneObject& GetFood();
        // --------------------------------------------------------------------------
        /// \brief Get access to home of colony
        /// \return Refernce of home
        const SceneObject& GetHome();
        ///\number of ant in a colony
        uint32_t m_num;
        ///\ number of ants that is active(alive)
        uint32_t m_activeNum;
        ///\ the list to store ants
        std::vector<Ant*> m_antList;
        ///\ trail create by ants in the list
        Trail m_trail;
        uint32_t m_counter;
        ///\ Container using spatial hashing
        std::vector<Antlist> Cell;
        ///\ Length of each cell square
        float const cellSize;
        ///\ Length of whole environment square
        float const worldSize;
        ///\ Food
        SceneObject* m_pFood;
        ///\ Home
        SceneObject* m_pHome;
    private:
        inline uint32_t GetCellCount();
};//end of class
}//end of namespace
#endif//
