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
                     Vector _dir,
                     float _bound,
                     float _mass,
                     DrawType _type
                    );
        virtual void Rotate(const float theta, const Vector& _axis);
        virtual void Move(const Vector& _dis);
        virtual void Update();
        uint32_t GetType() const;

        Vector m_pos;
        Vector m_dir;
        float m_mass;
        float m_bound;
        DrawType m_type;
        SceneNode m_node;
        Transform m_trans;
    private:
        void GetColorId();
        uint16_t m_colorId[3];
        static uint16_t uniqueColorId[3];
};//end of class
}//end of namespace
#endif //end of define
