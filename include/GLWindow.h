#ifndef _GLWINDOW_H_
#define _GLWINDOW_H_

#include <QtOpenGL>
#include <stdint.h>
#include "sceneManager.h"
#include "objLoader.h"

namespace QtGLWindow{
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
        void RenderScene(const SceneManager& _scene);
        void Draw();
        SceneManager m_scene;
        ObjLoader m_obj;

};//end of class
}//end of namespace
#endif //end of define
