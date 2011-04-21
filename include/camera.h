#ifndef _CAMERA_H_
#define _CAMERA_H_
#include <OpenGL/openGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <stdint.h>
#include "vector.h"

namespace QtGLWindow
{
// --------------------------------------------------------------------------
/// \brief class camera, manipulate viewing transformation and projection transformation
class Camera
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        Camera();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Camera();
        // --------------------------------------------------------------------------
        /// \brief Set up viewing matrix and projection matrix
        void SetupCam();
        // --------------------------------------------------------------------------
        /// \brief Reset the eye position of the glulookat to modify th model view matrix
        /// \param _zoomFactor how much to zoom/pan
        void Zoom();
        void ResetView();

        Vector m_eye;
        Vector m_centre;
        Vector m_up;
};//end of class
}//end of namespace
#endif //end of define
