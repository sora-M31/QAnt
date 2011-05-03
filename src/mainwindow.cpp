#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl = new QtGLWindow::GLWindow(this);
    m_ui->s_mainLayout->addWidget(m_gl,0,0,3,1);
    connect( m_ui->m_wireframeCheck,SIGNAL(toggled(bool)), m_gl,SLOT(toggleWireframe(bool)) );
    connect( m_ui->m_rotX,SIGNAL(pressed()),m_gl, SLOT(setRotationX()) );
    connect( m_ui->m_rotY,SIGNAL(pressed()),m_gl, SLOT(setRotationY()) );
    connect( m_ui->m_rotZ,SIGNAL(pressed()),m_gl, SLOT(setRotationZ()) );
    connect( m_ui->m_transX,SIGNAL(pressed()),m_gl,SLOT(setTranslationX()) );
    connect( m_ui->m_transY,SIGNAL(pressed()),m_gl,SLOT(setTranslationY()) );
    connect( m_ui->m_transZ,SIGNAL(pressed()),m_gl,SLOT(setTranslationZ()) );
    connect( m_ui->m_zoom,SIGNAL(pressed()),m_gl, SLOT(setZoom()) );
    connect( m_ui->m_spin,SIGNAL(pressed()),m_gl, SLOT(setSpin()) );
    connect( m_ui->m_model,SIGNAL(currentIndexChanged(int)),m_gl,SLOT(setModel(int)));
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_gl;
}
