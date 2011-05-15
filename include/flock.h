#ifndef _FLOCK_H_
#define _FLOCK_H_
#include "boid.h"

namespace QtGLWindow
{
class Flock
{
    friend class SceneManager;
    public:
        Flock();
        Flock(uint32_t _num, float _caggregate, float _cseparate, float _calign, float _cwall);
        ~Flock();
        void Update(uint32_t _time);
        Boid* GetBoid(uint32_t _index) const;
        uint32_t GetNum() const;
    private:
        float m_caggregate;
        float m_cseparate;
        float m_calign;
        float m_cwall;
        Boid* m_boidList;
        uint32_t m_num;

};//end of class
}//end of namespace
#endif //end of define
