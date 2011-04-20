#include "GLWindow.h"
namespace QtGLWindow{
const static float PI  = 3.1415926;
//------------------------------------------------------------------------------
GLWindow::GLWindow(
                        QWidget *_parent
                  )
                   :QGLWidget( _parent )
{
    setFocus();
    resize(_parent->size());

    m_framerate = 1000;
    m_wireframe = false;
    m_timer = new QTimer(this);
    //connect( m_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    //m_timer->start(m_framerate);
}
//------------------------------------------------------------------------------
GLWindow::~GLWindow()
{
    if( m_timer !=0 )
        delete m_timer;
}
//------------------------------------------------------------------------------
void GLWindow::initializeGL()
{
    glClearColor(0,0,0,1);

    m_scene.InitScene();
    pSelected = m_scene.m_root.m_pNext->m_pObject;

    m_obj.ParseFile("arrow.obj");
    m_obj.Load();
    m_obj.m_pMesh->CreateVBO();
}
//------------------------------------------------------------------------------
void GLWindow::resizeGL(
                            const uint32_t _w,
                            const uint32_t _h
                        )
{
    glViewport(0,0,_w,_h);
}
//------------------------------------------------------------------------------
void GLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if( m_wireframe )
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else
    {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }

   // m_scene.UpdateScene(m_pos,m_rot,m_axis);
    RenderScene(m_scene);
}
//------------------------------------------------------------------------------
void GLWindow::RenderScene(const SceneManager& _scene)
{
    const SceneNode* thisnode = &(_scene.m_root);

    while( thisnode->m_pNext !=NULL )
    {
        if( thisnode->m_pNext->m_pObject!= 0)
        {
            Draw(thisnode->m_pNext->m_pObject);
        }
        thisnode = thisnode->m_pNext;
    }
}
//------------------------------------------------------------------------------
void GLWindow::Draw(const SceneObject* _obj)
{
    glPushMatrix();
        glMultMatrixf( _obj->m_trans.m_transform.m_mat);
        //glMultMatrixf(m_trans.m_transform.m_mat);
        m_obj.m_pMesh->DrawVBO();
    glPopMatrix();
}
//------------------------------------------------------------------------------
void GLWindow::toggleWireframe(bool _mode)
{
    m_wireframe = _mode;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setRotationX()
{
    pSelected->m_trans.SetRotation(1*PI/180, pSelected->m_axisX);
    pSelected->RotateAxis();
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
void GLWindow::setRotationY()
{
    pSelected->m_trans.SetRotation(1*PI/180, pSelected->m_axisY);
    pSelected->RotateAxis();
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
void GLWindow::setRotationZ()
{
    pSelected->m_trans.SetRotation(1*PI/180, pSelected->m_axisZ);
    pSelected->RotateAxis();
    pSelected->m_trans.ApplyTransform();
    updateGL();
}
void GLWindow::setTranslationX(double _dis){}
void GLWindow::setTranslationY(double _dis){}
void GLWindow::setTranslationZ(double _dis){}
}//end of namespace
