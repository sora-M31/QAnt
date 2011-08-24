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
        // --------------------------------------------------------------------------
        /// \brief Reset the camera to initial position
        void Reset();
        // --------------------------------------------------------------------------
        /// \brief Set up viewing matrix and projection matrix
        void SetupCam();
        // --------------------------------------------------------------------------
        /// \brief Track, along old direction, move eye position towards old direction with the length given
        /// \param _length
        void Zoom(const float _length);
        // --------------------------------------------------------------------------
        /// \brief Rotate around Z
        /// \param _theta Angle
        void Pitch(const float _theta);
        // --------------------------------------------------------------------------
        /// \brief Rotate around Y
        /// \param _theta Angle
        void Yaw(const float _theta);
        // --------------------------------------------------------------------------
        /// \brief Rotate around X
        /// \param _theta Angle
        void Roll(const float _theta);
    private:
        // --------------------------------------------------------------------------
        /// \brief Reset glulookat with the new eye center up value.
        void ResetView();
        // --------------------------------------------------------------------------
        /// \brief Eye position
        Vector m_eye;
        // --------------------------------------------------------------------------
        /// \brief Centre looking at
        Vector m_centre;
        /// \brief Up direction
        Vector m_up;
};//end of class
}//end of namespace
#endif //end of define
