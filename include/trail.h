#ifndef __TRAIL_H__
#define __TRAIL_H__

#include "pheromone.h"
#include <vector>

namespace QtGLWindow
{
class Trail
{
    public:
      /// an array to store the pheromone laid by all the numbers of the colony
      std::vector<Pheromone*> m_phrmTrail;
      
      ///\brief default constructor
      Trail();
      ///\brief default destructor
      ~Trail();
      ///\brief push the given pheromone in to the array.
      ///@param[in] _phe pheromone to be added to the trail
      void AddPherom(Pheromone* _phe);
      ///\brief go through the trail and evaporate pheromone, if any pheromone's lifespam is not positive any morje ,it is deleted from the array.
      void DeleteEveporatedPherom();
};
}//end of namespace
#endif
