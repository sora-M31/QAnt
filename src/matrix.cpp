#include "matrix.h"
#include <stdint.h>

namespace QtGLWindow
{
//------------------------------------------------------------------------------
Matrix::Matrix()
{
    memset( m_mat, 0.0f, 16*sizeof(float));
    m00 = m11 = m22 = m33 = 1.0f;
}
//------------------------------------------------------------------------------
Matrix::~Matrix()
{
}
//------------------------------------------------------------------------------
void Matrix::operator = ( const Matrix& _param )
{
    for(uint8_t i=0; i<16; ++i)
    {
        m_mat[i] = _param.m_mat[i];
    }
}
//------------------------------------------------------------------------------
Vector Matrix::operator * ( const Vector& _param ) const
{
    return Vector(
                    m00*_param.GetX() + m01 *_param.GetY() + m02 *_param.GetZ(),
                    m10*_param.GetX() + m11 *_param.GetY() + m12 *_param.GetZ(),
                    m20*_param.GetX() + m21 *_param.GetY() + m22 *_param.GetZ());
}
//------------------------------------------------------------------------------
Matrix Matrix::operator * ( const Matrix& _param ) const
{
    Matrix mat;
    mat.m00 = m00*_param.m00 + m01 *_param.m10 + m02 *_param.m20 + m03*_param.m30;
    mat.m10 = m10*_param.m00 + m11 *_param.m10 + m12 *_param.m20 + m13*_param.m30;
    mat.m20 = m20*_param.m00 + m21 *_param.m10 + m22 *_param.m20 + m23*_param.m30;
    mat.m30 = m30*_param.m00 + m31 *_param.m10 + m32 *_param.m20 + m33*_param.m30;
    mat.m01 = m00*_param.m01 + m01 *_param.m11 + m02 *_param.m21 + m03*_param.m31;
    mat.m11 = m10*_param.m01 + m11 *_param.m11 + m12 *_param.m21 + m13*_param.m31;
    mat.m21 = m20*_param.m01 + m21 *_param.m11 + m22 *_param.m21 + m23*_param.m31;
    mat.m31 = m30*_param.m01 + m31 *_param.m11 + m32 *_param.m21 + m33*_param.m31;
    mat.m02 = m00*_param.m02 + m01 *_param.m12 + m02 *_param.m22 + m03*_param.m32;
    mat.m12 = m10*_param.m02 + m11 *_param.m12 + m12 *_param.m22 + m13*_param.m32;
    mat.m22 = m20*_param.m02 + m21 *_param.m12 + m22 *_param.m22 + m23*_param.m32;
    mat.m32 = m30*_param.m02 + m31 *_param.m12 + m32 *_param.m22 + m33*_param.m32;
    mat.m03 = m00*_param.m03 + m01 *_param.m13 + m02 *_param.m23 + m03*_param.m33;
    mat.m13 = m10*_param.m03 + m11 *_param.m13 + m12 *_param.m23 + m13*_param.m33;
    mat.m23 = m20*_param.m03 + m21 *_param.m13 + m22 *_param.m23 + m23*_param.m33;
    mat.m33 = m30*_param.m03 + m31 *_param.m13 + m32 *_param.m23 + m33*_param.m33;
    return mat;
}
}//end of namespace
