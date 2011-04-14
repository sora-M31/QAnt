#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <string.h>
#include <vector.h>
namespace QtGLWindow
{
class Matrix
{
    public:
    Matrix();
    ~Matrix();
    Matrix operator * ( const Matrix& _param ) const;
    Vector operator * ( const Vector& _param ) const;
    void operator = ( const Matrix& _param );

    union
    {
        struct
        {
            float  m00,m10,m20,m30,// m00,m01,m02,m03
                   m01,m11,m21,m31,// m10,m11,m12,m13
                   m02,m12,m22,m32,// m20,m21,m22,m23
                   m03,m13,m23,m33;// m30,m31,m32,m33
        };
        float m_mat[16]; 
    };
};//end of class
}//end of namespace
#endif //end of define
