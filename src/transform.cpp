#include "transform.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------
Transform::Transform()
{
}
//------------------------------------------------------------------------------
Transform::~Transform()
{}
//------------------------------------------------------------------------------
void Transform::SetTranslate(Vector _pos)
{
    m_translate.m_mat[12] = _pos.GetX();
    m_translate.m_mat[13] = _pos.GetY();
    m_translate.m_mat[14] = _pos.GetZ();
}
//------------------------------------------------------------------------------
void Transform::SetRotation(float _theta, Vector _v )
{
    float halfsin = sin(_theta/2);
    float x= halfsin*_v.GetX();
    float y= halfsin*_v.GetY();
    float z= halfsin*_v.GetZ();
    float w= cos(_theta/2);
    float xx = x*x;
    float xy = x*y;
    float xz = x*z;
    float yz = y*z;
    float yy = y*y;
    float zz = z*z;
    float wx = w*x;
    float wy = w*y;
    float wz = w*z;
    Matrix quat;
    quat.m00 = 1-2*(yy+zz);
    quat.m01 = 2*(xy-wz);
    quat.m02 = 2*(xz+wy);
    quat.m10 = 2*(xy+wz);
    quat.m11 = 1-2*(xx+zz);
    quat.m12 = 2*(yz-wx);
    quat.m20 = 2*(xz-wy);
    quat.m21 = 2*(yz+wx);
    quat.m22 = 1-2*(xx+yy);

    m_rotate = quat * m_rotate;
}
//------------------------------------------------------------------------------
void Transform::ApplyTransform()
{
    m_transform = m_translate * m_rotate;
}
}//end of namespace
