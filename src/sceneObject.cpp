#include "sceneObject.h"
#define PI 3.1415926

namespace QtGLWindow
{
//------------------------------------------------------------------------------
uint16_t SceneObject::uniqueColorId[3] = {0,0,0};
//------------------------------------------------------------------------------
SceneObject::SceneObject()
    : m_pos(0,0,0),
      m_bound(0.0),
      m_type(kObject),
      m_node(this),
      m_axisX(Vector(1,0,0)),
      m_axisY(Vector(0,1,0)),
      m_axisZ(Vector(0,0,1))
{
    GetColorId();
}
//------------------------------------------------------------------------------
SceneObject::SceneObject(
                            Vector _pos, 
                            float _bound, 
                            DrawType _type)
    : m_pos(_pos),
      m_bound(_bound),
      m_type(_type),
      m_node(this),
      m_axisX(Vector(1,0,0)),
      m_axisY(Vector(0,1,0)),
      m_axisZ(Vector(0,0,1))
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
void SceneObject::Rotate(const float _theta, const char _axis)
{
    switch(_axis)
    {
        case 'X':
            m_trans.SetRotation(1*PI/180, m_axisX);
            break;
        case 'Y':
            m_trans.SetRotation(1*PI/180, m_axisY);
            break;
        case 'Z':
            m_trans.SetRotation(1*PI/180, m_axisZ);
            break;
    }
    RotateAxis();
    m_trans.ApplyTransform();

}
//------------------------------------------------------------------------------
void SceneObject::Translate(const char _axis)
{
    switch(_axis)
    {
        case 'X':
            m_trans.SetTranslate( m_axisX * 0.1 );
        case 'Y':
            m_trans.SetTranslate( m_axisY * 0.1 );
        case 'Z':
            m_trans.SetTranslate( m_axisZ * 0.1 );
    }
        m_trans.ApplyTransform();
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
void SceneObject::RotateAxis()
{
    m_axisX = m_trans.m_rotate * Vector(1,0,0);
    m_axisY = m_trans.m_rotate * Vector(0,1,0);
    m_axisZ = m_trans.m_rotate * Vector(0,0,1);
}
}//end of namespace
