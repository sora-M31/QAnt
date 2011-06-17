#include "sceneObject.h"
#define PI 3.1415926

namespace QtGLWindow
{
//------------------------------------------------------------------------------
uint16_t SceneObject::uniqueColorId[3] = {0,0,0};
//------------------------------------------------------------------------------
SceneObject::SceneObject()
    : m_pos(0,0,0),
      m_node(this),
      m_bound(0.0),
      m_type(kObject),
      m_axisX(Vector(1,0,0)),
      m_axisY(Vector(0,1,0)),
      m_axisZ(Vector(0,0,1)),
      m_vel(0,0,0),
      m_mass(0),
      m_friction(0),
      m_force(0,0,0),
      m_accel(0,0,0),
      m_maxAccel(0),
      m_maxAngle(0)
{
    GetColorId();
    m_walkCounter=0;
}
//------------------------------------------------------------------------------
SceneObject::SceneObject(
                            Vector _pos, 
                            float _bound, 
                            DrawType _type
                        )
    : m_pos(_pos),
      m_node(this),
      m_bound(_bound),
      m_type(_type),
      m_axisX(Vector(1,0,0)),
      m_axisY(Vector(0,1,0)),
      m_axisZ(Vector(0,0,1)),
      m_vel(0,0,0),
      m_mass(0),
      m_friction(0),
      m_force(0,0,0),
      m_accel(0,0,0),
      m_maxAccel(0),
      m_maxAngle(0)

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
void SceneObject::Translate(const Vector& _dis)
{
    m_pos+=_dis;
    m_trans.SetTranslate(_dis);
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------------
void SceneObject::Translate(const uint32_t _time)
{
    float delta_t = _time*0.001 ;
    Vector pos = (m_vel*delta_t + m_accel * delta_t * delta_t /2);
    m_vel += ( m_accel * delta_t );

    m_pos +=pos;
    m_trans.SetTranslate(pos);
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------
void SceneObject::Rotate(const float _theta, const char _axis)
{
    switch(_axis)
    {
        case 'X':
            m_trans.SetRotation(_theta*PI/180, m_axisX);
            break;
        case 'Y':
            m_trans.SetRotation(_theta*PI/180, m_axisY);
            break;
        case 'Z':
            m_trans.SetRotation(_theta*PI/180, m_axisZ);
            break;
    }
    RotateAxis();
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------------
void SceneObject::Rotate()
{
    float theta = m_axisX.AngleBetween( m_force);

    Vector vector = (m_axisX.Cross( m_force)).Normalise();

    if (theta > m_maxAngle)
    {
        theta = m_maxAngle;
    }
    m_trans.SetRotation( theta, vector);
    m_trans.ApplyTransform();
    RotateAxis();
}
//------------------------------------------------------------------------------------
bool SceneObject::CheckNeighbor(const SceneObject& _obj, uint32_t _angle, uint32_t _rad)
{
    Vector relDis = _obj.m_pos - m_pos;
    if ( (relDis.AngleBetween(this->m_axisX) < _angle) &&
          (relDis.Length() < _rad) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
//------------------------------------------------------------------------------
void SceneObject::Update()
{
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------------
void SceneObject::Move(const uint32_t _time)
{
    Rotate();
    float scalar = m_force.Length();

    if (scalar > m_maxAccel)
    {
        scalar = m_maxAccel;
    }
    m_force =m_axisX * scalar * m_mass;
    m_accel = (m_force -m_vel*m_friction) / m_mass;
    Translate(_time);
}
//------------------------------------------------------------------------------
uint32_t SceneObject::GetType() const
{
    return m_type;
}
//------------------------------------------------------------------------------
float SceneObject::GetBound() const
{
    return m_bound;
}
//------------------------------------------------------------------------------
void SceneObject::SetMaxRotAngle(const float _angle)
{
    m_maxAngle = _angle;
}
//------------------------------------------------------------------------------
void SceneObject::SetMaxAccel(const float _accel)
{
    m_maxAccel = _accel;
}
//------------------------------------------------------------------------------
void SceneObject::SetFriction(const float _friction)
{
    m_friction = _friction;
}
//------------------------------------------------------------------------------
void SceneObject::SetBound(const float _bound)
{
    m_bound = _bound;
}
//------------------------------------------------------------------------------
void SceneObject::RotateAxis()
{
    m_axisX = m_trans.m_rotate * Vector(1,0,0);
    m_axisY = m_trans.m_rotate * Vector(0,1,0);
    m_axisZ = m_trans.m_rotate * Vector(0,0,1);
}
}//end of namespace
