#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "util.h"

namespace QtGLWindow
{
class Vector
{
    public:
        friend  std::ostream& operator << (std::ostream& _output, const Vector& _VecToPrint);
        Vector();
        ~Vector();
        Vector(float _x, float _y, float _z);
        Vector(const Vector& _param);
        Vector Normalise() const;
        float Dot(const Vector& _paramVector) const;
        Vector Cross(const Vector& _paramVector) const;
        float Length() const;
        float LengthSquare() const;
        float AngleBetween(const Vector& _paramVector) const;

        Vector operator + (const Vector& _paramVector) const;
        Vector operator - (const Vector& _paramVector) const;
        Vector operator * (const float _param) const;
        Vector operator / (const float _param) const;
        Vector operator = (const Vector& _paramVector);
        Vector operator += (const Vector& _paramVector);
        Vector operator -= (const Vector& _paramVector);
    
        Vector operator /= (const float _param);
        bool operator == (const Vector& _paramVector) const;
        float GetX() const;
        float GetY() const;
        float GetZ() const;
        void SetX(float _x);
        void SetY(float _y);
        void SetZ(float _z);
    protected:
        float m_x;
        float m_y;
        float m_z;
};//end of class
    std::ostream& operator << (std::ostream& _output, const Vector& _VecToPrint);
}//end of namespace
#endif //end of define
