#include "GLWindow.h"
namespace QtGLWindow{
const static float PI  = 3.1415926;
//------------------------------------------------------------------------------
GLWindow::GLWindow(
                        QWidget *_parent
                  )
                   :QGLWidget( _parent ),
                     m_pBotObj(0),
                     pSelected(0)
{
    setFocus();
    resize(_parent->size());

    m_framerate = 50;
    m_wireframe = true;
    m_timer = new QTimer(this);
    m_pCam = new Camera;
    m_spin = 0.0;
    m_zoom =0;
    m_pitch = 0;
    m_yaw = 0;
    m_roll = 0;
    connect( m_timer, SIGNAL(timeout()), this, SLOT(updateGL()));
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

    glEnable(GL_DEPTH_TEST);
    m_scene.InitScene();
    m_pCam->SetupCam();

    pSelected = m_scene.m_root.m_pNext->m_pNext->m_pNext->m_pNext->m_pObject;

    m_sphereObj.ParseFile("sphere.obj");
    m_sphereObj.Load();
    m_sphereObj.m_pMesh->CreateVBO();

    m_envObj.ParseFile("plane.obj");
    m_envObj.Load();
    m_envObj.m_pMesh->CreateVBO();

    m_arrowObj.ParseFile("arrow.obj");
    m_arrowObj.Load();
    m_arrowObj.m_pMesh->CreateVBO();

    m_fishObj.ParseFile("fish.obj");
    m_fishObj.Load();
    m_fishObj.m_pMesh->CreateVBO();

    m_pBotObj = & m_fishObj;
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

    m_scene.UpdateScene();
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
void GLWindow::Draw(SceneObject* _obj)
{
    glPushMatrix();
        glRotatef(m_spin, 0,1,0);
        if(_obj->GetType() == kObject)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(1,1,1);
                glScalef(60,1,60);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                m_envObj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if ( _obj->GetType() == kAnt)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(1,0,0);
                glMultMatrixf( _obj->GetTransformation().m_transform.m_mat);
                m_pBotObj->m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if( _obj->GetType() == kPhe)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                if ( (static_cast<Pheromone*>(_obj))->m_phrmType == ToHome)
                {
                    glColor3f(0,0,1);
                }
                else
                {
                    glColor3f(0,1,0);
                }
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                glScalef(0.1,0.1,0.1);
                m_pBotObj->m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if( _obj->GetType() == kHome)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(1,0,0);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                m_sphereObj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }
        else if( _obj->GetType() == kFood)
        {
            glPushMatrix();
                glPushAttrib(GL_ENABLE_BIT | GL_POLYGON_BIT | GL_CURRENT_BIT);
                glColor3f(0,1,0);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                m_sphereObj.m_pMesh->DrawVBO();
                glPopAttrib();
            glPopMatrix();
        }

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
}
//------------------------------------------------------------------------------
void GLWindow::setRotationY()
{
}
//------------------------------------------------------------------------------
void GLWindow::setRotationZ()
{
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationX()
{
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationY()
{
}
//------------------------------------------------------------------------------
void GLWindow::setTranslationZ()
{
}
//------------------------------------------------------------------------------
void GLWindow::setCamPitch(const int _theta)
{
    this->m_pCam->Pitch(_theta - m_pitch);
    m_pitch = _theta;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setCamYaw(const int _theta)
{
    this->m_pCam->Yaw(_theta - m_yaw);
    m_yaw = _theta;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setCamRoll(const int _theta)
{
    this->m_pCam->Roll(_theta - m_roll);
    m_roll = _theta;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setCamZoom(const int _dis)
{
    m_pCam->Zoom(_dis-m_zoom);
    m_zoom = _dis;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setCamSpin(const int _angle)
{
    m_spin = _angle;
    updateGL();
}
//------------------------------------------------------------------------------
void GLWindow::setModel(int _index)
{
    #if 0
    //load slow but less memory
    switch(_index)
    {
        case 0:
            m_botObj.ParseFile("sphere.obj");
            break;
        case 1:
            m_botObj.ParseFile("arrow.obj");
            break;
        case 2:
            m_botObj.ParseFile("fish.obj");
            break;
    }
    m_botObj.Load();
    m_botObj.m_pMesh->UpdateVBO();
    #endif
    switch(_index)
    {
        case 0:
            m_pBotObj = &m_fishObj;
            break;
        case 1:
            m_pBotObj = &m_arrowObj;
            break;
        case 2:
            m_pBotObj = &m_sphereObj;
            break;
    }
    updateGL();
}
//------------------------------------------------------------------------------
void  GLWindow::start()
{
    m_timer->start(m_framerate);
}
//------------------------------------------------------------------------------
void GLWindow::restart()
{
    m_scene.ResetScene();
}
//------------------------------------------------------------------------------
void GLWindow::setAngle(const double _angle)
{
    std::cout<<"calling.....\n";
    pSelected->SetMaxRotAngle((float)_angle);
}
//------------------------------------------------------------------------------
void GLWindow::setAccel(const int _accel)
{
    pSelected->SetMaxAccel(_accel);
}
//------------------------------------------------------------------------------
void GLWindow::setFriction(const double _friction)
{
    pSelected->SetFriction((float)_friction);
}
//------------------------------------------------------------------------------
}//end of namespace
