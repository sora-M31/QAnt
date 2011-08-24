#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <GLWindow.h>

namespace Ui {
    class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        Ui::MainWindow *m_ui;
        QtGLWindow::GLWindow *m_gl;
};
#endif // MAINWINDOW_H
