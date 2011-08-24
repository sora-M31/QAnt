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
        // --------------------------------------------------------------------------
        ///\brief Constructor
        /// \param _mycolony Pointer to the colony this ants belongs to
        Ant(Colony* _mycolony);
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Ant();
        // --------------------------------------------------------------------------
        /// \brief Copy constructor
        /// \param _ant
        Ant(const Ant& _ant);
        // --------------------------------------------------------------------------
        /// \brief Operator = overload 
        /// \param _ant Reference of ant to copy
        /// \return This ant
        Ant operator = (const Ant& _ant);
        // --------------------------------------------------------------------------
        /// \brief Apply transformation to the object
        /// \param _time time passed by
        void Move(uint32_t _time);
        // --------------------------------------------------------------------------
        /// \brief Reset all properties of ant class
        void Reset();
        // --------------------------------------------------------------------------
        /// \brief Set id
        /// \param _id id
        void SetID(uint32_t _id);
        // --------------------------------------------------------------------------
        /// \brief Get id
        /// \return id
        uint32_t GetID();
        // --------------------------------------------------------------------------
        /// \brief Update ant status with a state machine
        /// \param _time time passed
        void Update(uint32_t _time); 
        ///\ Status of ant
        AntState m_state;

    protected:
        // --------------------------------------------------------------------------
        ///\todo Set height 
        void SetHeight();
        // --------------------------------------------------------------------------
        /// \brief Check whether ant arrive at home or food
        /// \param _obj the other object
        /// \return True if arrive, false if not
        bool Arrive(const SceneObject& _obj);
        // --------------------------------------------------------------------------
        /// \brief Check ant close to home or food
        /// \param _obj
        /// \return 
        bool Near(const SceneObject& _obj);
        // --------------------------------------------------------------------------
        /// \brief Detectpheromone and calculate the force
        /// \param _type Pheromone type
        /// \return True if designated pheromone around, false if not
        bool DetectPheromone(PhrmType _type);
        // --------------------------------------------------------------------------
        /// \brief Calculate obstacle force 
        void DetectObstacle();
        // --------------------------------------------------------------------------
        /// \brief Calculate force if random walking
        void RandomWalk();
        // --------------------------------------------------------------------------
        /// \brief Repeling force from environment
        void Wall();
        ///\ Whether object was hit by other object        
        bool m_hit;
        ///\counter for ant to walk and stop
        uint32_t m_counter;
        ///\ Pheromone force
        Vector m_pheromone;
        ///\ Environment repelling force
        Vector m_wall;
        ///\ Home and fod attraction force
        Vector m_attraction;
        ///\ Obstacle repelling force
        Vector m_obstacles;
        ///\force when random walking
        Vector m_rand;
        ///\ speed
        float m_speed;
        ///\ pheromone attraction coefficient
        float kPheromone;
        ///\ Environment repelling force coefficient
        float kWall;
        ///\ Food home attraction coefficient
        float kAttract;
        ///\ Obstacle repelling force coefficient
        float kObstacle;
        ///\ Random walk coefficient
        float kRand;
        ///\ Walk coefficient
        float kWalk;
        ///\ Brake coefficient
        float kBrake;
        ///\ ant cell id
        uint32_t m_ID;
        ///\ Pointer to colony this ant belongs to
        Colony* m_pColony;
    private:
        // --------------------------------------------------------------------------
        /// \brief Default constructor
        Ant();
};
}//end of namespace
#endif
