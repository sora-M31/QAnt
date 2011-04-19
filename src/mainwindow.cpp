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
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_gl;
}
