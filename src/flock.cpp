#include "flock.h"

namespace QtGLWindow
{   
//------------------------------------------------------------------------------
Flock::Flock()
    : m_boidList(0)
{}
//------------------------------------------------------------------------------
Flock::Flock(
                uint32_t _num,
                float _caggregate,
                float _cseparate,
                float _calign,
                float _cwall
            )
    : m_caggregate( _caggregate ),
    m_cseparate(_cseparate),
    m_calign(_calign),
    m_cwall(_cwall),
    m_boidList(0),
    m_num(_num)
{
    m_boidList = new Boid[_num];
    for(uint32_t i=0; i<_num; ++i)
    {
        m_boidList[i].SceneObject::Translate( Vector(rand()%10,rand()%10,rand()%10) );

    }
}
//------------------------------------------------------------------------------
Flock::~Flock()
{
    if (m_num >0 )
    {
        delete [] m_boidList;
    }
}

//------------------------------------------------------------------------------
void Flock::Update( uint32_t _time )
{
    for(uint32_t i=0; i<m_num; ++i)
    {
        Boid* list = &( m_boidList[i] );
        //Boid* list = m_boidList + i;
        for (uint32_t j=0;j< m_num; ++j )
        {
            if( (i!=j) && ( m_boidList[i].CheckNeighbor( m_boidList[j], 60 *3.14, 3 ) ) )
            {
                while(list->next !=0)
                {
                    list = list->next;
                }
                list->next = &m_boidList[j];
            }
        }
        m_boidList[i].Separate();
        m_boidList[i].Aggregate();
        m_boidList[i].Align();
        for( uint32_t j=0; j<m_num; ++j)
        {
            m_boidList[j].next = NULL;
        }
        m_boidList[i].next = NULL;
        m_boidList[i].Wall();
        m_boidList[i].GetForce(m_cseparate, m_caggregate, m_calign,m_cwall);
        m_boidList[i].Translate(_time);
    }

}
//------------------------------------------------------------------------------
Boid* Flock::GetBoid(uint32_t _index) const
{
    return (_index < m_num) ? &m_boidList[_index] : NULL;
}
//------------------------------------------------------------------------------
uint32_t Flock::GetNum() const
{
    return m_num;
}
}//end of namespace
