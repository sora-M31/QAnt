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
        // --------------------------------------------------------------------------
        /// \brief Overloading output to print out all memeber of a vector in square bracket
        /// \param _output Output stream
        /// \param _VecToPrint The vector needs printing
        /// \return Output stream
        friend  std::ostream& operator << (std::ostream& _output, const Vector& _VecToPrint);
        // --------------------------------------------------------------------------
        /// \brief Default constructor
        Vector();
        // --------------------------------------------------------------------------
        /// \brief Default destructor
        ~Vector();
        // --------------------------------------------------------------------------
        /// \brief Constuctor by passed in value
        /// \param _x x component
        /// \param _y y component
        /// \param _z z component
        Vector(float _x, float _y, float _z);
        // --------------------------------------------------------------------------
        /// \brief Copy constructor
        /// \param _param Vector to copy from
        Vector(const Vector& _param);
        // --------------------------------------------------------------------------
        /// \brief Get a vector which is equal to the this vector after normalising
        /// \return Normalised vector
        Vector Normalise() const;
        // --------------------------------------------------------------------------
        /// \brief Get dot product of this vector and parameter vector
        /// \param _paramVector The parameter vector
        /// \return Dot product
        float Dot(const Vector& _paramVector) const;
        // --------------------------------------------------------------------------
        /// \brief Get cross product of this vector and parameter vector
        /// \param _paramVector The parameter vector
        /// \return Cross product
        Vector Cross(const Vector& _paramVector) const;
        // --------------------------------------------------------------------------
        /// \brief Get the length of this vector
        /// \return The length
        float Length() const;
        // --------------------------------------------------------------------------
        /// \brief Get squared value of the length of the vector, for calculating convinience
        /// \return Sqaured length
        float LengthSquare() const;
        // --------------------------------------------------------------------------
        /// \brief Calculating the angle between this vector and parameter vector
        /// \param _paramVector Parameter vector
        /// \return Angle in radiant
        float AngleBetween(const Vector& _paramVector) const;

        // --------------------------------------------------------------------------
        /// \brief Operator + overload by adding individual component
        /// \param _paramVector Parameter Vector
        /// \return Result vector
        Vector operator + (const Vector& _paramVector) const;
        // --------------------------------------------------------------------------
        /// \brief Operator - overload by minusing individual component
        /// \param _paramVector parameter vector
        /// \return Result vector
        Vector operator - (const Vector& _paramVector) const;
        // --------------------------------------------------------------------------
        /// \brief Operator * overload, product of the vector and a float number
        /// \param _param parameter vector
        /// \return Product
        Vector operator * (const float _param) const;
        // --------------------------------------------------------------------------
        /// \brief Operator / overload, divide vector by a float number
        /// \param _param parameter number
        /// \return Result vector
        Vector operator / (const float _param) const;
        // --------------------------------------------------------------------------
        /// \brief Operator = overload, assign the value of parameter vector to this vector
        /// \param _paramVector Parameter vector
        /// \return This vector 
        Vector operator = (const Vector& _paramVector);
        // --------------------------------------------------------------------------
        /// \brief Operator += overload, assign the value of the sum of the parameter vector and this vector to this vector
        /// \param _paramVector parameter vector
        /// \return This vector
        Vector operator += (const Vector& _paramVector);
        // --------------------------------------------------------------------------
        /// \brief Operator -= overload, assign cha of parameter vector and this vector to this vector
        /// \param _paramVector parameter vector
        /// \return this vector
        Vector operator -= (const Vector& _paramVector);
        // --------------------------------------------------------------------------
        /// \brief Operator /= overload, assign divison of parameter by this vector to this vector 
        /// \param _param parameter 
        /// \return this vector
        Vector operator /= (const float _param);
        // --------------------------------------------------------------------------
        /// \brief Operator == overload to get rid of floating point unprecisioness, Compare whether two vector are equal
        /// \param _paramVector parameter vector
        /// \return Real if equal, false if not.
        bool operator == (const Vector& _paramVector) const;
        // --------------------------------------------------------------------------
        /// \brief Accestor, get x component value
        /// \return Value of m_x
        float GetX() const;
        // --------------------------------------------------------------------------
        /// \brief Accestor, get y component value
        /// \return Value of m_y
        float GetY() const;
        // --------------------------------------------------------------------------
        /// \brief Accestor, get z component value
        /// \return Value of m_z
        float GetZ() const;
        // --------------------------------------------------------------------------
        /// \brief Set value of x to passed in value
        /// \param _x Value to be set
        void SetX(float _x);
        // --------------------------------------------------------------------------
        /// \brief Set value of y to passed in value
        /// \param _y Value to be set
        void SetY(float _y);
        // --------------------------------------------------------------------------
        /// \brief Set value of z to passed in value
        /// \param _z Value to be set
        void SetZ(float _z);
    protected:
        ///\ m_x x component in cartisian world
        float m_x;
        ///\ m_x y component in cartisian world
        float m_y;
        ///\ m_x z component in cartisian world
        float m_z;
};//end of class
    std::ostream& operator << (std::ostream& _output, const Vector& _VecToPrint);
}//end of namespace
#endif //end of define
