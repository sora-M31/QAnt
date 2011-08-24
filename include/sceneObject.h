#ifndef _SCENEOBJECT_H_
#define _SCENEOBJECT_H_
#include "vector.h"
#include "transform.h"
#include "util.h"
#include "sceneNode.h"
namespace QtGLWindow
{
class SceneObject
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        SceneObject();
        // --------------------------------------------------------------------------
        /// \brief Virtual destructor
        virtual ~SceneObject();
        // --------------------------------------------------------------------------
        /// \brief Constructor
        /// \param _pos 
        /// \param _bound
        /// \param 
        SceneObject(
                     Vector _pos,
                     float _bound,
                     DrawType _type
                    );
        // --------------------------------------------------------------------------
        /// \brief Update Object properties
        virtual void Update();
        // --------------------------------------------------------------------------
        /// \brief Accessor, get render type
        /// \return Render type
        uint32_t GetType() const;
        // --------------------------------------------------------------------------
        /// \brief Accessor, get the boundry radius
        /// \return Radius
        float GetBound() const;
        // --------------------------------------------------------------------------
        /// \brief Set Maximum Rotation
        /// \param _angle Rotated angle
        void SetMaxRotAngle(const float _angle);
        // --------------------------------------------------------------------------
        /// \brief Set Maximum Acceleration
        /// \param _accel Acceleration
        void SetMaxAccel(const float _accel);
        // --------------------------------------------------------------------------
        /// \brief Set boundry radius
        /// \param _bound boundry
        void SetBound(const float _bound);
        // --------------------------------------------------------------------------
        /// \brief Set friction coefficient
        /// \param _friction friction coefficient
        void SetFriction(const float _friction);
        // --------------------------------------------------------------------------
        /// \brief Rotate object
        /// \param theta Angle
        /// \param _axis Axis
        virtual void Rotate(const float theta, const char _axis);
        // --------------------------------------------------------------------------
        /// \brief Translate object
        /// \param theta Length
        /// \param _axis Axis 
        virtual void Translate(const float theta, const char _axis);
        // --------------------------------------------------------------------------
        /// \brief Translate object to time
        /// \param _time Time passed by
        void Translate(const uint32_t _time);
        // --------------------------------------------------------------------------
        /// \brief Get transformation matrix
        /// \return Transformation
        Transform GetTransformation() const;
        // --------------------------------------------------------------------------
        /// \brief Position
        Vector m_pos;
        ///\ m_node, Node this object attached to
        SceneNode m_node;

    protected:
        // --------------------------------------------------------------------------
        /// \brief Check whether an object is neighbor of this object
        /// \param _obj Object to check
        /// \param _angle Angle limitation
        /// \param _rad Radius limitation
        /// \return 
        bool CheckNeighbor(const SceneObject& _obj, float _angle, float _rad);
        // --------------------------------------------------------------------------
        /// \brief Rotate to force
        void Rotate();
        // --------------------------------------------------------------------------
        /// \brief Translate to a new position
        /// \param _dis the distance vector between new position and old position
        void Translate(const Vector& _dis);
        // --------------------------------------------------------------------------
        /// \brief Rotate axis
        void RotateAxis();
        // --------------------------------------------------------------------------
        /// \brief Move object to time
        /// \param _time Time passed by
        void Move(const uint32_t _time);
        ///\m_trans, transformation 
        Transform m_trans;
        ///\m_walkCounter counter
        uint32_t m_walkCounter;
        ///\ boundry radius
        float m_bound;
        ///\ Drawing type  
        DrawType m_type;
        ///\ Axis X
        Vector m_axisX;
        ///\ Axis Y
        Vector m_axisY;
        ///\ Axis Z
        Vector m_axisZ;
        /// \brief velocity
        Vector m_vel;
        ///\ Mass
        float m_mass;
        ///\ friction
        float m_friction;
        ///\ Force applied to this object
        Vector m_force;
        ///\ Acceleration of the object
        Vector m_accel;
        ///\ Maximum acceleration allowed
        uint32_t m_maxAccel;
        ///\ Maximum angle this object can turn within a timestep
        float m_maxAngle;
        ///\ Set the Color ID for picking
        void GetColorId();
        ///\ Color id of this object
        uint16_t m_colorId[3];
        ///\ Array for storing the id
        static uint16_t uniqueColorId[3];
};//end of class
}//end of namespace
#endif //end of define
