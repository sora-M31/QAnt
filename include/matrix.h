#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <string.h>
#include <vector.h>
namespace QtGLWindow
{
class Matrix
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        Matrix();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Matrix();
        // --------------------------------------------------------------------------
        /// \brief Set matrix to identity matrix
        void AsIdentity();
        // --------------------------------------------------------------------------
        /// \brief operator * overload, get product of two matrix
        /// \param _param parameter matrix
        /// \return result matrixc
        Matrix operator * ( const Matrix& _param ) const;
        // --------------------------------------------------------------------------
        /// \brief Operator * overload, get product of a matrix and a vector
        /// \param _param parameter vector
        /// \return result vector
        Vector operator * ( const Vector& _param ) const;
        // --------------------------------------------------------------------------
        /// \brief Operator = overload, set parameter matrix value to this matrix
        /// \param _param
        /// \return 
        void operator = ( const Matrix& _param );
        // --------------------------------------------------------------------------
float Get(uint8_t _id) const;
        // --------------------------------------------------------------------------

void Set(uint8_t _id, float _value);
        // --------------------------------------------------------------------------
        /// \4*4 matrix members, array share same space with 16 floats for easy access
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
