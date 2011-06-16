#ifndef __BOID_H_
#define __BOID_H_

#include "sceneObject.h"
#include "vector.h"
#include "transform.h"

namespace QtGLWindow
{
class Boid: public SceneObject
{
    friend class Flock;
    public:
        Boid();
        ~Boid();

        void Wall();
        void Separate();
        void Aggregate();
        void Align();
        void GetForce(float _cseparate, float _caggregate, float _calign, float _cwall);
        Boid *next;

    private:
        float m_maxRot;
        float m_viewAngle;
        float m_senseRad;
        float m_maxAccel;
        float m_maxAngle;
        float m_friction;
        Vector m_aggregate;
        Vector m_separate;
        Vector m_align;
        Vector m_wall;
        Vector m_tforce;
};//end of class
}//end of namespace
#endif //end of define
