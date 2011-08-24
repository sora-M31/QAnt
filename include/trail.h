#ifndef __TRAIL_H__
#define __TRAIL_H__

#include "pheromone.h"
#include <vector>

namespace QtGLWindow
{
class Trail
{
    public:
      ///An array to store the pheromone laid by all the members of the colony
      std::vector<Pheromone*> m_phrmTrail;
      ///\brief default constructor
      Trail();
      ///\brief default destructor
      ~Trail();
      // --------------------------------------------------------------------------
      /// \brief Clear trail array, used for resetting the program
      void Reset();
      // --------------------------------------------------------------------------
      /// \brief Add given pheromone to the trail
      /// \param _phe Pheormone to be added
      void AddPherom(Pheromone* _phe);
      ///\brief Go through the trail add age to pheromone and deleted pheromone when it gets to max age
      void DeleteEveporatedPherom();
};
}//end of namespace
#endif
