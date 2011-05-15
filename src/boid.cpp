#include "boid.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------
Boid::Boid()
    :next(0),
    m_maxRot(0),
    m_viewAngle(150*3.14/180),
    m_senseRad(15),
    m_maxAccel(20),
    m_aggregate(0,0,0),
    m_separate(0,0,0),
    m_align(0,0,0),
    m_wall(0,0,0)
{
    m_maxAngle = 1*3.14 /180;
    m_type = kBoid;
    m_vel = Vector(10,0,0);
    m_friction =0.05;// 0.05;
    m_accel = Vector(0,0,0);
    m_mass = 0.01;
    m_bound = 1;
}
//------------------------------------------------------------------------------
Boid::~Boid()
{
}
//------------------------------------------------------------------------------
bool Boid::CheckNeighbor(const Boid& _boid)
{
    //*
    Vector relDis = _boid.m_pos - m_pos;
    if (   (relDis.AngleBetween(this->m_axisX) < m_viewAngle)
        && (relDis.Length() < m_senseRad) )
    {
        return true;
    }
    else 
    {
        return false;
    }//*/
    //return true;
}
//------------------------------------------------------------------------------
void Boid::Translate(uint32_t _time)
{
    float delta_t = _time*0.001 ;
    Vector pos = (m_vel*delta_t + m_accel * delta_t * delta_t /2);
    m_vel += ( m_accel * delta_t );

    m_pos +=pos;
    m_trans.SetTranslate(pos);
    m_trans.ApplyTransform();
}
//------------------------------------------------------------------------------
void Boid::Rotate()
{
    float theta = m_axisX.AngleBetween( m_tforce);
    Vector vector = (m_axisX.Cross( m_tforce)).Normalise();
    
    if (theta > m_maxAngle)
    {
        theta = m_maxAngle;
    }
    m_trans.SetRotation( theta, vector);
    m_trans.ApplyTransform();
    this->RotateAxis();
}
//------------------------------------------------------------------------------
void Boid::Wall()
{
    /*
      ------------------------
      |                      |
      |  |----------------|  |
      |  |                |  |
      |  |                | -|-blank(if boid is in this area, get repulsion force away from the wall)
      |  |                |  |
      |  |                |  |-wall
      |  |                |  |
    */
    float forceScalar = 1;
    float blank = 6;
    float wall =30;
    wall = wall -blank;

    m_wall = Vector(0,0,0);
    if ( m_pos.GetX()>wall )
        m_wall += Vector( -forceScalar, 0,0);
    
    else if ( m_pos.GetX()< -wall )
        m_wall += Vector(  forceScalar, 0,0);
    
    if ( m_pos.GetY()> wall )
        m_wall += Vector( 0, -forceScalar,0);

    else if ( m_pos.GetY()< -wall )
        m_wall += Vector( 0,  forceScalar,0);
    
    if ( m_pos.GetZ()>wall )
        m_wall += Vector( 0, 0,-forceScalar);

    else if ( m_pos.GetZ()<-wall )
        m_wall += Vector( 0, 0, forceScalar);

    m_wall = m_wall.Normalise();
}
//------------------------------------------------------------------------------
void Boid::Aggregate()
{
    Vector avrgPos;
    Boid * list = next;
    uint32_t num=0;
    while ( list!=0)
    {
        avrgPos += list->m_pos;
        ++num;
        list = list->next;
    }
    if (num !=0)
    {
        avrgPos/=num;
    }
    m_aggregate = ( avrgPos - m_pos);
    m_aggregate = m_aggregate.Normalise();
}
//------------------------------------------------------------------------------
void Boid::Separate()
{
    Vector repulsion;
    Boid* list = next;
    while(list !=0)
    {
        Vector dis = m_pos - list->m_pos;
        float length = dis.Length();
        if (length !=0)
        {
            float disquare = length * length;
            repulsion +=  dis/disquare;
        }
        list = list->next;
    }
    m_separate = repulsion.Normalise();
}
//------------------------------------------------------------------------------
void Boid::Align()
{
    Vector avrgVel(0,0,0);
    Boid * list = next;
    uint32_t num=0;
    while( list!=0)
    {
        avrgVel += list->m_vel;
        list = list ->next;
        ++num;
    }
    if( num !=0 )
    {
        avrgVel /= num;
    }
    m_align = ( avrgVel - m_vel).Normalise();
}
//------------------------------------------------------------------------------
void Boid::GetForce(float _cseparate, float _caggregate, float _calign, float _cwall)
{
    m_tforce = ( m_separate*_cseparate + m_aggregate*_caggregate + m_align*_calign + m_wall*_cwall);
    //boid rotate to the desired direction first
    Rotate();
    // add force on the moving direction
    float scalar = m_tforce.Length();

    if (scalar > m_maxAccel)
    {
        scalar = m_maxAccel;
    }
    m_force =m_axisX * scalar;

    m_accel = (m_force -m_vel*m_friction) / m_mass;
}
}//end of namespace
