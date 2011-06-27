#include "vector.h"
#include <assert.h>

namespace QtGLWindow
{
//------------------------------------------------------------------------------
Vector::Vector():
    m_x(0.0f), m_y(0.0f), m_z(0.0f)
{
}
//------------------------------------------------------------------------------
Vector::~Vector()
{
}
//------------------------------------------------------------------------------
Vector::Vector(float _x, float _y, float _z):
    m_x(_x),m_y(_y),m_z(_z)
{
}
//------------------------------------------------------------------------------
Vector::Vector(const Vector& _param):
    m_x( _param.m_x ), m_y( _param.m_y ), m_z( _param.m_z )
{
}
//------------------------------------------------------------------------------
Vector Vector::Normalise() const
{
    float length = Length();

    if( length != 0)
    {
        return Vector( m_x / length, m_y / length, m_z / length );
    }
    else
    {
        return Vector();
    }
}
//------------------------------------------------------------------------------
float Vector::Dot(const Vector& _paramVector) const
{
    return  ( m_x * _paramVector.m_x + m_y * _paramVector.m_y + m_z * _paramVector.m_z );
}
//------------------------------------------------------------------------------
Vector Vector::Cross(const Vector& _paramVector) const
{
    return Vector ( m_y * _paramVector.m_z - m_z * _paramVector.m_y,
                    m_z * _paramVector.m_x - m_x * _paramVector.m_z,
                    m_x * _paramVector.m_y - m_y * _paramVector.m_x);
}
//------------------------------------------------------------------------------
float Vector::LengthSquare() const
{
    return ( m_x * m_x + m_y * m_y + m_z * m_z );
}
//------------------------------------------------------------------------------
float Vector::Length() const
{
    float lenSqr = LengthSquare();
    if (lenSqr == 0.0)
    {
        return 0.0;
    }
    else
    {
        return sqrt(lenSqr);
    }
}
//------------------------------------------------------------------------------
float Vector::AngleBetween(const Vector& _paramVector) const
{
    float length = this ->Length();
    float paramlength = _paramVector.Length();
    
    float angle=0;
    if(length ==0 || paramlength ==0)
    {
        angle =0;
    }
    else
    {
        angle = this->Dot(_paramVector)/ (this->Length()*_paramVector.Length());
    }
    if ( angle>1.0 ) 
    {
        angle = 1.0;
    }
    else if( angle < -1.0 )
    {
        angle = -1.0;
    }
    return acos(angle);
}
//------------------------------------------------------------------------------
Vector Vector::operator + (const Vector& _paramVector) const
{
    return Vector( m_x + _paramVector.m_x, m_y + _paramVector.m_y, m_z + _paramVector.m_z );
}
//------------------------------------------------------------------------------
Vector Vector::operator * (const float _param) const
{
    return Vector( m_x *  _param, m_y *  _param, m_z *  _param );
}
//------------------------------------------------------------------------------
Vector Vector::operator / (const float _param) const
{
    assert(_param!=0);
    return Vector( m_x /_param, m_y / _param, m_z / _param );
}
//------------------------------------------------------------------------------
Vector Vector::operator - (const Vector& _paramVector) const
{
    return Vector((m_x - _paramVector.m_x),(m_y - _paramVector.m_y),(m_z - _paramVector.m_z));
}
//------------------------------------------------------------------------------
Vector Vector::operator = (const Vector& _paramVector)
{
    m_x = _paramVector.m_x;
    m_y = _paramVector.m_y;
    m_z = _paramVector.m_z;
    return *this;
}
///------------------------------------------------------------------------------
Vector Vector::operator += (const Vector& _paramVector)
{
    m_x += _paramVector.m_x;
    m_y += _paramVector.m_y;
    m_z += _paramVector.m_z;
    return *this;
}
//------------------------------------------------------------------------------
Vector Vector::operator -= (const Vector& _paramVector)
{
    m_x -= _paramVector.m_x;
    m_y -= _paramVector.m_y;
    m_z -= _paramVector.m_z;
    return *this;
}
//------------------------------------------------------------------------------
Vector Vector::operator /= (const float _param)
{
    m_x /= _param;
    m_y /= _param;
    m_z /= _param;
    return *this;
}
//------------------------------------------------------------------------------
bool Vector::operator == (const Vector& _paramVector) const
{
    if ( RealCompare( m_x, _paramVector.m_x)
         && RealCompare( m_y, _paramVector.m_y)
         && RealCompare( m_z, _paramVector.m_z) )
        return true;
    else return false;
}
//------------------------------------------------------------------------------
float Vector::GetX() const
{
    return m_x;
}
//------------------------------------------------------------------------------
float Vector::GetY() const
{
    return m_y;
}

//------------------------------------------------------------------------------
float Vector::GetZ() const
{
    return m_z;
}

void Vector::SetX(float _x)
{
    m_x = _x;
}
void Vector::SetY(float _y)
{
    m_y = _y;
}
void Vector::SetZ(float _z)
{
    m_z = _z;
}
//------------------------------------------------------------------------------
std::ostream& operator << (std::ostream & _output, const Vector&  _VecToPrint)
{
    return _output << " vector[ "<<_VecToPrint.m_x<< " , "<<_VecToPrint.m_y<<" , "<<_VecToPrint.m_z<<" ]"; 
}
}//end of namespace
