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
        GLWindow( QWidget *_parent );
        ~GLWindow();
    public slots:
        void toggleWireframe( bool _mode );
        void setRotationX();
        void setRotationY();
        void setRotationZ();
        void setTranslationX();
        void setTranslationY();
        void setTranslationZ();
        void setCamZoom(const int _dis);
        void setCamSpin(const int _angle);
        void setCamPitch(const int _theta);
        void setCamYaw(const int _theta);
        void setCamRoll(const int _theta);
        void setModel(int _index);
        void start();
        void restart();
        void setAngle(const double _angle);
        void setAccel(const int _accel);
        void setFriction(const double _friction);
        void updateScene();
    protected:
        void initializeGL();
        void resizeGL(
                        const uint32_t _w,
                        const uint32_t _h
                     );
        void paintGL();
    private:
        void RenderScene( const SceneManager& _scene );
        void Draw(SceneObject* _obj);
        SceneManager m_scene;
        ObjLoader* m_pBotObj;
        ObjLoader m_sphereObj;
        ObjLoader m_envObj;
        ObjLoader m_fishObj;
        ObjLoader m_arrowObj;
        Camera* m_pCam;
        uint32_t m_framerate;
        QTimer* m_timer;
        bool m_wireframe;
        Transform m_trans;
        SceneObject* pSelected;
        float m_spin;
        float m_zoom;
        float m_pitch;
        float m_yaw;
        float m_roll;
        uint32_t m_counter;

};//end of class
}//end of namespace
#endif //end of define
