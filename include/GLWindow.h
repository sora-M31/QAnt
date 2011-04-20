#ifndef _GLWINDOW_H_
#define _GLWINDOW_H_

#include <QtOpenGL>
#include <QTimer>
#include <stdint.h>
#include "sceneManager.h"
#include "transform.h"
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
    public slots:
        void toggleWireframe(bool _mode);
        void setRotationX();
        void setRotationY();
        void setRotationZ();
        void setTranslationX(double _dis);
        void setTranslationY(double _dis);
        void setTranslationZ(double _dis);
    protected:
        void initializeGL();
        void resizeGL(
                        const uint32_t _w,
                        const uint32_t _h
                     );
        void paintGL();
    private:
        void RenderScene(const SceneManager& _scene);
        void Draw(const SceneObject* _obj);
        SceneManager m_scene;
        ObjLoader m_obj;
        uint32_t m_framerate;
        QTimer* m_timer;
        bool m_wireframe;
        Transform m_trans;
        SceneObject* pSelected;
};//end of class
}//end of namespace
#endif //end of define
