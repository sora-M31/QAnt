#ifndef _GLWINDOW_H_
#define _GLWINDOW_H_

#include <QtOpenGL>
#include <QTimer>
#include <stdint.h>
#include "sceneManager.h"
#include "transform.h"
#include "objLoader.h"
#include "camera.h"

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
        void setTranslationX();
        void setTranslationY();
        void setTranslationZ();
        void setZoom();
        void setSpin();
        void setCamPitch();
        void setCamYaw();
        void setCamRoll();
        void setModel(int _index);
    protected:
        void initializeGL();
        void resizeGL(
                        const uint32_t _w,
                        const uint32_t _h
                     );
        void paintGL();
    private:
        void RenderScene(const SceneManager& _scene);
        void Draw(SceneObject* _obj);
        SceneManager m_scene;
        ObjLoader m_obj;
        ObjLoader m_envObj;
        Camera* m_pCam;
        uint32_t m_framerate;
        QTimer* m_timer;
        bool m_wireframe;
        Transform m_trans;
        SceneObject* pSelected;
        float m_spin;
};//end of class
}//end of namespace
#endif //end of define
