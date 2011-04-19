#include "GLWindow.h"
namespace QtGLWindow{
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
   // m_scene.UpdateScene();
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
        m_obj.m_pMesh->DrawVBO();
    glPopMatrix();
}
//------------------------------------------------------------------------------
void GLWindow::toggleWireframe(bool _mode)
{
    m_wireframe = _mode;
    updateGL();
}
}//end of namespace
