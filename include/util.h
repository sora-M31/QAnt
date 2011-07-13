#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector>
#include <string>
#include "vector.h"
namespace QtGLWindow
{
class Vector;
// --------------------------------------------------------------------------
/// \brief simulation status
enum SimState{ OFF=0, ON };
// --------------------------------------------------------------------------
/// \brief drawing type
enum DrawType{ kObject, kGround, kFood, kHome, kAnt, kPhe, kBoid, kFlock };
enum PhrmType{ ToFood, ToHome };
enum AntState{HomeToFood, FollowFoodPheromone, FollowHomePheromone, FoodToHome, NearFood, NearHome};
// --------------------------------------------------------------------------
/// \brief Tokenizer, split a string into tokens by delimiters 
/// \param str string to tokenized
/// \param tokens resulted tokens
/// \param delimiters where to split
void Tokenize( const std::string& str, std::vector<std::string>& tokens,const std::string& delimiters) ;
bool RealCompare(const float _x, float _y);
uint32_t Hash(Vector _pos, float _cellSize, float _worldSize);
}
#endif
