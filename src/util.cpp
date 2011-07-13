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
    return false;
}
//------------------------------------------------------------------------------
uint32_t Hash(Vector _pos, float _cellSize, float _worldSize)// cellsize worldsize
{
    // |--------------|
    // |  6 |  7 |  8 |
    // |----|----|----|
    // |  3 |  4 |  5 |
    // |----|----|----|
    // |  0 |  1 |  2 |
    // |--------------| count three

    uint32_t count = (int) _worldSize/_cellSize;
    //translate the square to positive space
    Vector newPos;
    newPos.SetX(_pos.GetX()+_worldSize/2.0);
    newPos.SetZ(_pos.GetZ()+_worldSize/2.0);
#if _DEBUG
    std::cout<<(int)newPos.GetX()/_cellSize<<" x ";
    std::cout<<(int)newPos.GetZ()/_cellSize<<" z \n";
#endif
    uint32_t id = (int)newPos.GetX()/_cellSize + (int)newPos.GetZ()/_cellSize * count;
    return id;
}
}//end of namespace
