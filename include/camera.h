#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <OpenGL/openGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdint.h>
#include "vector.h"
#include "sceneObject.h"

namespace QtGLWindow
{
// --------------------------------------------------------------------------
/// \brief class camera, manipulate viewing transformation and projection transformation
class Camera: public SceneObject
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        Camera();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Camera();
        void Reset();
        // --------------------------------------------------------------------------
        /// \brief Set up viewing matrix and projection matrix
        void SetupCam();
        void Zoom(const float _length);
        void Pitch(const float _theta);
        void Yaw(const float _theta);
        void Roll(const float _theta);
    private:
        void ResetView();
        Vector m_eye;
        Vector m_centre;
        Vector m_up;
};//end of class
}//end of namespace
#endif //end of define
