#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    m_gl = new GLWindow(this);
    m_ui->s_mainLayout->addWidget(m_gl,0,0,3,1);
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_gl;
}
