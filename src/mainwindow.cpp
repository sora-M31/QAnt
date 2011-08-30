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
    connect( m_ui->m_pitchSlider, SIGNAL(valueChanged(int)),m_ui->m_pitchBox,SLOT(setValue(int)));
    connect( m_ui->m_pitchBox, SIGNAL(valueChanged(int)),m_ui->m_pitchSlider,SLOT(setValue(int)));
    connect( m_ui->m_pitchSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setCamPitch(int)));
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


    connect( m_ui->m_numSlider, SIGNAL(valueChanged(int)),m_ui->m_numBox,SLOT(setValue(int)));
    connect( m_ui->m_numBox, SIGNAL(valueChanged(int)),m_ui->m_numSlider,SLOT(setValue(int)));
    connect( m_ui->m_numSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setNumber(int)));

    connect( m_ui->m_pheSlider, SIGNAL(valueChanged(int)),m_ui->m_pheBox,SLOT(setValue(int)));
    connect( m_ui->m_pheBox, SIGNAL(valueChanged(int)),m_ui->m_pheSlider,SLOT(setValue(int)));
    connect( m_ui->m_pheSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setPheromone(int)));

    connect( m_ui->m_obsSlider, SIGNAL(valueChanged(int)),m_ui->m_obsBox,SLOT(setValue(int)));
    connect( m_ui->m_obsBox, SIGNAL(valueChanged(int)),m_ui->m_obsSlider,SLOT(setValue(int)));
    connect( m_ui->m_obsSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setObstacle(int)));

    connect( m_ui->m_wallSlider, SIGNAL(valueChanged(int)),m_ui->m_wallBox,SLOT(setValue(int)));
    connect( m_ui->m_wallBox, SIGNAL(valueChanged(int)),m_ui->m_wallSlider,SLOT(setValue(int)));
    connect( m_ui->m_wallSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setWall(int)));

    connect( m_ui->m_randSlider, SIGNAL(valueChanged(int)),m_ui->m_randBox,SLOT(setValue(int)));
    connect( m_ui->m_randBox, SIGNAL(valueChanged(int)),m_ui->m_randSlider,SLOT(setValue(int)));
    connect( m_ui->m_randSlider, SIGNAL(valueChanged(int)),m_gl,SLOT(setRand(int)));
#if 0
    connect( m_ui->m_angleBox, SIGNAL(valueChanged(double)),m_ui->m_angleSlider,SLOT(setValue(double)));
    connect( m_ui->m_angleSlider, SIGNAL(valueChanged(double)),m_ui->m_angleBox,SLOT(setValue(double)));
    connect( m_ui->m_angleSlider, SIGNAL(valueChanged(double)),m_gl,SLOT(setAngle(double)));

#endif
    connect( m_ui->m_startButton, SIGNAL( start() ), m_gl, SLOT(start()) );
    connect( m_ui->m_startButton, SIGNAL( stop() ), m_gl, SLOT(stop()) );
}

MainWindow::~MainWindow()
{
    if( m_ui !=0)
        delete m_ui;
    if( m_gl != 0)
        delete m_gl;
}
