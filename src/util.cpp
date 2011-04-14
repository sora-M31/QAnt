#include "util.h"
#include <math.h>
#define Eps 0.0001

namespace QtGLWindow
{
//------------------------------------------------------------------------------
//Method from http://oopweb.com/CPP/Documents/CPPHOWTO/Volume/C++Programming-HOWTO-7.html
void Tokenize ( const std::string& str,
           std::vector<std::string>& tokens,
           const std::string& delimiters)
{
    std::string::size_type lastPos = str.find_first_not_of( delimiters, 0);
    std::string::size_type pos = str.find_first_of(delimiters, lastPos);

    while( pos != std::string::npos || lastPos != std::string::npos )
    {
        tokens.push_back(str.substr(lastPos, pos-lastPos) );
        lastPos = str.find_first_not_of(delimiters,pos);
        pos = str.find_first_of( delimiters, lastPos);
    }
}
//------------------------------------------------------------------------------
bool RealCompare(const float _x, const float _y)
{
    if( fabs(_x - _y) < Eps )
        return true;
    else return false;
}
}//end of namespace
