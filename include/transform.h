#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "matrix.h"
#include "vector.h"

namespace QtGLWindow
{
class Transform
{
    public:
        Transform();
        ~Transform();
        void Reset();
        void SetTranslate(Vector _pos);
        void SetRotation(float _theta, Vector _v);
        void ApplyTransform();
        Matrix m_translate;
        Matrix m_rotate;
        Matrix m_transform;
};//end of class
}//end of namespace
#endif //end of define
