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
        virtual void Rotate(const float theta, const char _axis);
        virtual void Translate(const char _axis);
        void Translate(Vector _dis);
        void RotateAxis();
        virtual void Update();
        uint32_t GetType() const;

        Vector m_pos;
        float m_bound;
        DrawType m_type;
        SceneNode m_node;
        Transform m_trans;
        Vector m_axisX;
        Vector m_axisY;
        Vector m_axisZ;
        Vector m_vel;
        float m_mass;
        Vector m_force;
        Vector m_accel;
    private:
        void GetColorId();
        uint16_t m_colorId[3];
        static uint16_t uniqueColorId[3];
};//end of class
}//end of namespace
#endif //end of define
