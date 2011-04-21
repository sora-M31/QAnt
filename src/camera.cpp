#include "camera.h"
#include <stdio.h>
namespace QtGLWindow
{
//------------------------------------------------------------------------------
Camera::Camera()
    :m_eye(20,0,20),
     m_centre(0,0,0),
     m_up(0,1,0)
{
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
void Camera::Zoom()//pan?
{ 	Vector direction = (m_centre-m_eye).Normalise();
    m_eye += direction*1;
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
}//end of namespace
