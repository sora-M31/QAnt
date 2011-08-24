#ifndef __PHEROM_H__
#define __PHEROM_H__
#include "util.h"
#include "sceneObject.h"

namespace QtGLWindow
{
class Pheromone:public SceneObject
{
    public:
      // --------------------------------------------------------------------------
      /// \brief Constructor
      /// \param _pos Position
      /// \param _type Pheromone type
      Pheromone(Vector _pos, PhrmType _type);
      ///\brief Default destructor
      ~Pheromone();
      // --------------------------------------------------------------------------
      /// \brief Copy constructor
      /// \param _phe Pheromone to copy from
      Pheromone(const Pheromone& _phe);
      // --------------------------------------------------------------------------
      /// \brief Operator = overlaod
      /// \param _phe parameter pheromone
      /// \return This pheromone
      Pheromone operator = (const Pheromone& _phe);
      // --------------------------------------------------------------------------
      /// \brief Add 1 to age
      void Evaporate();
      ///\m_age Current age
      uint32_t m_age;
      ///\m_phrmType Pheromone type, to home pheromone, or to food pheromone
      PhrmType m_phrmType;
      // --------------------------------------------------------------------------
      /// \brief Maximum age allowed
      uint32_t m_maxAge;
};
}//end of namespace
#endif
