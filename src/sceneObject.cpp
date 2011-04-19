#include "sceneObject.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------
uint16_t SceneObject::uniqueColorId[3] = {0,0,0};
//------------------------------------------------------------------------------
SceneObject::SceneObject()
    : m_pos(0,0,0),
      m_dir(0,0,0),
      m_mass(1),
      m_bound(0.0),
      m_type(kObject),
      m_node(this)
{
    GetColorId();
}
//------------------------------------------------------------------------------
SceneObject::SceneObject(
                            Vector _pos, 
                            Vector _dir, 
                            float _bound, 
                            float _mass, 
                            DrawType _type)
    : m_pos(_pos),
      m_dir(_dir),
      m_mass(_mass),
      m_bound(_bound),
      m_type(_type),
      m_node(this)
{
    GetColorId();
}
//------------------------------------------------------------------------------
SceneObject::~SceneObject()
{
}
//------------------------------------------------------------------------------
void SceneObject::GetColorId()
{
    m_colorId[0] = uniqueColorId[0];
    m_colorId[1] = uniqueColorId[1];
    m_colorId[2] = uniqueColorId[2];

    ++uniqueColorId[0];
    if ( uniqueColorId[0]>255 )
    {
        uniqueColorId[0] = 0;
        ++uniqueColorId[1];
        if (uniqueColorId[1]>255)
        {
            uniqueColorId[1] = 0;
            ++uniqueColorId[2];
        }
    }
}
//------------------------------------------------------------------------------
void SceneObject::Rotate(const float _theta, const Vector& _axis)
{
    m_trans.SetRotation(_theta, _axis);
}
//------------------------------------------------------------------------------
void SceneObject::Move(const Vector&  _dis)
{
    this->m_pos += _dis;
    m_trans.SetTranslate(m_pos);
}
//------------------------------------------------------------------------------
void SceneObject::Update()
{
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------
uint32_t SceneObject::GetType() const
{
    return m_type;
}
}//end of namespace
