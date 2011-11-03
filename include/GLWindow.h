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
        // --------------------------------------------------------------------------
        /// \brief Constructor
        /// \param _parent
        GLWindow( QWidget *_parent );
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~GLWindow();
    public slots:
        // --------------------------------------------------------------------------
        /// \brief Reset wireframe to mode
        /// \param _mode wireframe mode
        void toggleWireframe( bool _mode );
        void drawPheromone( bool _mode );
        // --------------------------------------------------------------------------
        /// \brief Set the length camera move along the direction
        /// \param _dis length
        void setCamZoom(const int _dis);
        // --------------------------------------------------------------------------
        /// \brief Set the angle for camera pin
        /// \param _angle angle
        void setCamSpin(const int _angle);
        // --------------------------------------------------------------------------
        /// \brief Set pitch angle
        /// \param _theta angle
        void setCamPitch(const int _theta);
        // --------------------------------------------------------------------------
        /// \brief Set yaw angle
        /// \param _theta angle
        void setCamYaw(const int _theta);
        // --------------------------------------------------------------------------
        /// \brief Set roll angle
        /// \param _theta angle
        void setCamRoll(const int _theta);
        // --------------------------------------------------------------------------
        /// \brief Set to different polygon model
        /// \param _index index
        void setModel(int _index);
        // --------------------------------------------------------------------------
        /// \brief start simulation
        void start();
        // --------------------------------------------------------------------------
        /// \brief Restart simulation
        void stop();
        // --------------------------------------------------------------------------
        /// \brief Update properties and redraw
        void updateScene();
        void setNumber(int _num);
        void setPheromone(int _phe);
        void setObstacle(int _obs);
        void setWall(int _wall);
        void setRand(int _rand);
    protected:
        // --------------------------------------------------------------------------
        /// \brief Initlize open gl
        void initializeGL();
        // --------------------------------------------------------------------------
        /// \brief Resize window
        /// \param _w width
        /// \param _h height
        void resizeGL(
                        const uint32_t _w,
                        const uint32_t _h
                     );
        // --------------------------------------------------------------------------
        /// \brief Draw using opengl
        void paintGL();
    private:
        // --------------------------------------------------------------------------
        /// \brief Render using linked list
        /// \param _scene
        void RenderScene( const SceneManager& _scene );
        // --------------------------------------------------------------------------
        /// \brief Draw objects in gl
        /// \param _obj objects to draw
        void Draw(SceneObject* _obj);
        ///\ scene manager
        SceneManager m_scene;
        ObjLoader* m_pBotObj;
        ///\ sphere model
        ObjLoader m_sphereObj;
        ObjLoader m_circleObj;
        ///\ environment model
        ObjLoader m_envObj;
        ///\ fish model
        ObjLoader m_antObj;
        ///\ arrow model
        ObjLoader m_arrowObj;
        ///\ POinter to camera
        Camera* m_pCam;
        ///\ framerate
        uint32_t m_framerate;
        QTimer* m_timer;
        bool m_wireframe;
        bool m_drawPheromone;
        ///\ Transformation
        Transform m_trans;
        ///\ pointer to selected object
        SceneObject* pSelected;
        float m_spin;
        float m_zoom;
        float m_pitch;
        float m_yaw;
        float m_roll;
        float m_num;
        float m_phe;
        float m_obs;
        float m_wall;
        float m_rand;
        uint32_t m_counter;

};//end of class
}//end of namespace
#endif //end of define
