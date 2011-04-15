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
}
//------------------------------------------------------------------------------
GLWindow::~GLWindow()
{}
//------------------------------------------------------------------------------
void GLWindow::initializeGL()
{
    glClearColor(0,0,0,1);
    m_scene.InitScene();
    m_obj.ParseFile("sphere.obj");
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
            Draw();
        }
        thisnode = thisnode->m_pNext;
    }
}
//------------------------------------------------------------------------------
void GLWindow::Draw()
{
    m_obj.m_pMesh->DrawVBO();
}
}//end of namespace
