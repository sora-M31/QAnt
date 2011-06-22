#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
     m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl = new QtGLWindow::GLWindow(this);
    m_ui->s_mainLayout->addWidget(m_gl,0,0,3,1);
    connect( m_ui->m_wireframeCheck,SIGNAL(toggled(bool)), m_gl,SLOT(toggleWireframe(bool)) );
    connect( m_ui->m_model,SIGNAL(currentIndexChanged(int)),m_gl,SLOT(setModel(int)));
#if 1
    connect( m_ui->m_pitchSlider, SIGNAL(valueChanged(int)),m_ui->m_pitchBox,SLOT(setValue(int)));
    connect( m_ui->m_pitchBox, SIGNAL(valueChanged(int)),m_ui->m_pitchSlider,SLOT(setValue(int)));
    connect( m_ui->m_pitchSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setCamPitch(int)));
#endif
    connect( m_ui->m_yawSlider, SIGNAL(valueChanged(int)),m_ui->m_yawBox,SLOT(setValue(int)));
    connect( m_ui->m_yawBox, SIGNAL(valueChanged(int)),m_ui->m_yawSlider,SLOT(setValue(int)));
    connect( m_ui->m_yawSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setCamYaw(int)));

    connect( m_ui->m_rollSlider, SIGNAL(valueChanged(int)),m_ui->m_rollBox,SLOT(setValue(int)));
    connect( m_ui->m_rollBox, SIGNAL(valueChanged(int)),m_ui->m_rollSlider,SLOT(setValue(int)));
    connect( m_ui->m_rollSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setCamRoll(int)));

    connect( m_ui->m_spinSlider, SIGNAL(valueChanged(int)),m_ui->m_spinBox,SLOT(setValue(int)));
    connect( m_ui->m_spinBox, SIGNAL(valueChanged(int)),m_ui->m_spinSlider,SLOT(setValue(int)));
    connect( m_ui->m_spinSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setCamSpin(int)));

    connect( m_ui->m_zoomSlider, SIGNAL(valueChanged(int)),m_ui->m_zoomBox,SLOT(setValue(int)));
    connect( m_ui->m_zoomBox, SIGNAL(valueChanged(int)),m_ui->m_zoomSlider,SLOT(setValue(int)));
    connect( m_ui->m_zoomSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setCamZoom(int)));
#if 0
    connect( m_ui->m_rotX,SIGNAL(pressed()),m_gl, SLOT(setRotationX()) );
    connect( m_ui->m_rotY,SIGNAL(pressed()),m_gl, SLOT(setRotationY()) );
    connect( m_ui->m_rotZ,SIGNAL(pressed()),m_gl, SLOT(setRotationZ()) );
    connect( m_ui->m_transX,SIGNAL(pressed()),m_gl,SLOT(setTranslationX()) );
    connect( m_ui->m_transY,SIGNAL(pressed()),m_gl,SLOT(setTranslationY()) );
    connect( m_ui->m_transZ,SIGNAL(pressed()),m_gl,SLOT(setTranslationZ()) );

    connect( m_ui->m_zoom,SIGNAL(pressed()),m_gl, SLOT(setZoom()) );
    connect( m_ui->m_spin,SIGNAL(pressed()),m_gl, SLOT(setSpin()) );
    connect( m_ui->m_pitch,SIGNAL(pressed()),m_gl,SLOT(setCamPitch()));
    connect( m_ui->m_yaw,SIGNAL(pressed()),m_gl,SLOT(setCamYaw()));
    connect( m_ui->m_roll,SIGNAL(pressed()),m_gl,SLOT(setCamRoll()));
#endif
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_gl;
}
