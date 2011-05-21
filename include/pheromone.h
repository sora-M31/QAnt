#ifndef __PHEROM_H__
#define __PHEROM_H__
#include "util.h"
#include "sceneObject.h"

namespace QtGLWindow
{
class Pheromone:public SceneObject
{
    public:
      Pheromone(Vector _pos, PhrmType _type);
      ///\brief default destructor
      ~Pheromone();
      Pheromone(const Pheromone& _phe);
      Pheromone operator = (const Pheromone& _phe);

      void Evaporate();

      uint32_t m_age;
      PhrmType m_phrmType;
      uint32_t m_maxAge;
};
}//end of namespace
#endif
