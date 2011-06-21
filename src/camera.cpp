#include "camera.h"
#include <stdio.h>
namespace QtGLWindow
{
//------------------------------------------------------------------------------
Camera::Camera()
    :m_centre(0,0,0)
{
    this->Rotate(-30,'Z');
    m_eye = m_centre - this->m_axisX*60;
    m_up = m_axisY;
    m_pos = m_eye;
}
//------------------------------------------------------------------------------
Camera::~Camera()
{
}
//------------------------------------------------------------------------------
void Camera::SetupCam()
{
    glMatrixMode(GL_PROJECTION);//switch to projection matrix stack
    glLoadIdentity();//clear the stack
    gluPerspective(60.0, float(1024/768),0.001,1000);//multiply the current matrix with this

    glMatrixMode(GL_MODELVIEW);// switch to model view stack
    glLoadIdentity();//clear the stack
    gluLookAt(m_eye.GetX(), m_eye.GetY(), m_eye.GetZ(),
              m_centre.GetX(),m_centre.GetY(), m_centre.GetZ(),
              m_up.GetX(), m_up.GetY(), m_up.GetZ());
}
//------------------------------------------------------------------------------
void Camera::Zoom(const float _length)//track
{ 	Vector direction = (m_centre-m_eye).Normalise();
    m_eye += direction*_length;
    ResetView();
}
//------------------------------------------------------------------------------
void Camera::ResetView()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
                m_eye.GetX(), m_eye.GetY(), m_eye.GetZ(),
                m_centre.GetX(),m_centre.GetY(), m_centre.GetZ(),
                m_up.GetX(), m_up.GetY(), m_up.GetZ()
             );
}
//------------------------------------------------------------------------------
void Camera::Pitch(const float _theta)
{
    this->Rotate(_theta,'Z');
    this->m_up = m_axisY;
    m_centre = m_axisX*(m_centre - m_eye).Length();
    ResetView();
}
//------------------------------------------------------------------------------
void Camera::Yaw(const float _theta)
{
    this->Rotate(_theta,'Y');
    this->m_up = m_axisY;
    m_centre = m_axisX*(m_centre - m_eye).Length();
    ResetView();
}
//------------------------------------------------------------------------------
void Camera::Roll(const float _theta)
{
    this->Rotate(_theta,'X');
    this->m_up = m_axisY;
    m_centre = m_axisX*(m_centre - m_eye).Length();
    ResetView();
}
}//end of namespace
