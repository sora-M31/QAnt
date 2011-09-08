#include "GLWindow.h"
namespace QtGLWindow{
const static float PI  = 3.1415926;
//------------------------------------------------------------------------------
GLWindow::GLWindow(QWidget *_parent
                  )
                   :QGLWidget( _parent ),
                     m_pBotObj(0),
                     pSelected(0)
{
    setFocus();
    resize(_parent->size());

    m_framerate = 50;
    m_wireframe = true;
    m_pCam = new Camera;
    m_spin = 0.0;
    m_zoom =0;
    m_pitch = 0;
    m_yaw = 0;
    m_roll = 0;
    m_num = 10;
    m_phe = 1;
    m_obs = 1;
    m_wall = 5;
    m_rand = 5;
    m_counter = 1;
    m_timer = new QTimer(this);
    connect( m_timer, SIGNAL(timeout()), this, SLOT(updateScene()));
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
    glClearColor(0.3,0.3,0.3,1);

    glClearDepth(1);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    GLfloat DiffuseLight[] = {0.8,0.5,0.5};
    GLfloat AmbientLight[] = {0.1,0.1,0.1};
    GLfloat LightPosition[] = {0,5,5,0};


    glLightfv(GL_LIGHT0,GL_DIFFUSE,DiffuseLight);
    glLightfv(GL_LIGHT1,GL_AMBIENT,AmbientLight);
    glLightfv(GL_LIGHT0,GL_POSITION,LightPosition);
    glShadeModel (GL_SMOOTH);
    m_pCam->SetupCam();

    //pSelected = m_scene.m_root.m_pNext->m_pNext->m_pNext->m_pNext->m_pObject;

#if 1
    m_sphereObj.ParseFile("resources/sphere.obj");
    m_sphereObj.Load();
    m_sphereObj.m_pMesh->CreateVBO();
#endif
    m_envObj.ParseFile("resources/plane.obj");
    m_envObj.Load();
    m_envObj.m_pMesh->CreateVBO();

    m_arrowObj.ParseFile("resources/arrow.obj");
    m_arrowObj.Load();
    m_arrowObj.m_pMesh->CreateVBO();


    m_antObj.ParseFile("resources/ant.obj");
    m_antObj.Check();
    m_antObj.Load();
    m_antObj.m_pMesh->CreateVBO();

    m_pBotObj = & m_antObj;
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
    RenderScene(m_scene);
}
//------------------------------------------------------------------------------
void GLWindow::updateScene()
{
    m_scene.UpdateScene();
    updateGL();
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
                glColor3f(0.1,0.5,0.2);
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
                glColor3f(0.2,0.2,0.2);
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
                m_sphereObj.m_pMesh->DrawVBO();
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
                glColor3f(1,0,0);
                glTranslatef(_obj->m_pos.GetX(),_obj->m_pos.GetY(),_obj->m_pos.GetZ());
                glRotatef(m_counter, 0,1,0);
                m_counter++;
                m_arrowObj.m_pMesh->DrawVBO();
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
            m_pBotObj = &m_antObj;
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
    m_scene.InitScene(m_num, m_phe, m_obs, m_wall, m_rand);
}
//------------------------------------------------------------------------------
void GLWindow::stop()
{
    m_timer->stop();
}
//------------------------------------------------------------------------------
void GLWindow::setNumber(int _num)
{
    m_num = _num;
}
//------------------------------------------------------------------------------
void GLWindow::setPheromone(int _phe)
{
    if(m_scene.m_pColony==0)
    {
        m_phe = (float) _phe;
    }
    else
    {
        m_scene.m_pColony->SetPheromone(_phe);
    }
}
//------------------------------------------------------------------------------
void GLWindow::setObstacle(int _obs)
{
    if(m_scene.m_pColony==0)
    {
        m_obs = (float) _obs;
    }
    else
    {
        m_scene.m_pColony->SetObstacle(_obs);
    }
}
//------------------------------------------------------------------------------
void GLWindow::setWall(int _wall)
{
    if(m_scene.m_pColony==0)
    {
        m_wall = (float) _wall;
    }
    else
    {
        m_scene.m_pColony->SetWall(_wall);
    }
}
//------------------------------------------------------------------------------
void GLWindow::setRand(int _rand)
{
    if(m_scene.m_pColony==0)
    {
        m_rand = (float) _rand;
    }
    else
    {
        m_scene.m_pColony->SetRand(_rand);
    }
}
}//end of namespace
