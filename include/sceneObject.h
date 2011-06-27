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
        SceneObject();
        virtual ~SceneObject();
        SceneObject(
                     Vector _pos,
                     float _bound,
                     DrawType _type
                    );
        virtual void Update();
        uint32_t GetType() const;
        float GetBound() const;

        void SetMaxRotAngle(const float _angle);
        void SetMaxAccel(const float _accel);
        void SetBound(const float _bound);
        void SetFriction(const float _friction);
        virtual void Rotate(const float theta, const char _axis);
        virtual void Translate(const float theta, const char _axis);
        void Translate(const uint32_t _time);
        Transform GetTransformation() const;
        Vector m_pos;
        SceneNode m_node;

    protected:
        bool CheckNeighbor(const SceneObject& _obj, uint32_t _angle, uint32_t _rad);
        void Rotate();
        void Translate(const Vector& _dis);
        void RotateAxis();
        void Move(const uint32_t _time);

        Transform m_trans;
        uint32_t m_walkCounter;
        float m_bound;
        DrawType m_type;
        Vector m_axisX;
        Vector m_axisY;
        Vector m_axisZ;
        Vector m_vel;
        float m_mass;
        float m_friction;
        Vector m_force;
        Vector m_accel;
        uint32_t m_maxAccel;
        float m_maxAngle;
        void GetColorId();
        uint16_t m_colorId[3];
        static uint16_t uniqueColorId[3];
};//end of class
}//end of namespace
#endif //end of define
