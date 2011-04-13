#ifndef _GLWINDOW_H_
#define _GLWINDOW_H_

#include <QtOpenGL>
#include <stdint.h>

class GLWindow : public QGLWidget
{
    Q_OBJECT
    public:
        GLWindow(
                    QWidget *_parent
                );
        ~GLWindow();
    protected:
        void initializeGL();
        void resizeGL(
                        const uint32_t _w,
                        const uint32_t _h
                     );
        void paintGL();
    private:

};//end of class
#endif //end of define
