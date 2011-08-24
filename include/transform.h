#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "matrix.h"
#include "vector.h"

namespace QtGLWindow
{
class Transform
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        Transform();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Transform();
        // --------------------------------------------------------------------------
        /// \brief Reset transformation matrix to identity matrix
        void Reset();
        // --------------------------------------------------------------------------
        /// \brief Set the value of translation matrix using given vector
        /// \param _pos Telative position
        void SetTranslate(Vector _pos);
        // --------------------------------------------------------------------------
        /// \brief Set the value of rotation with given axis and angle using quoternion,
        /// \param _theta Angle between new and old vector
        /// \param _v Axis vector
        void SetRotation(float _theta, Vector _v);
        // --------------------------------------------------------------------------
        /// \brief Multiply rotation matrix and translation matrix to get transformation matrix 
        void ApplyTransform();
        // --------------------------------------------------------------------------
        /// \brief Translation matrix
        Matrix m_translate;
        // --------------------------------------------------------------------------
        /// \brief Rotation matrix
        Matrix m_rotate;
        // --------------------------------------------------------------------------
        /// \brief transformation matrix
        Matrix m_transform;
};//end of class
}//end of namespace
#endif //end of define
