#include "Qdslider.h"
#include <iostream>

namespace Ui
{
//------------------------------------------------------------------------------
Qdslider::Qdslider( QWidget *parent = 0 )
                : QSlider(parent)
{
    m_dvalue= (double)value();
    setTracking(true);
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(toDouble(int)));
}
//------------------------------------------------------------------------------
Qdslider::~Qdslider()
{
}
//------------------------------------------------------------------------------
void Qdslider::toDouble(int _value)
{
    emit valueChanged((double) _value);
}
//------------------------------------------------------------------------------
void Qdslider::setValue(double _value)
{
    if( _value != m_dvalue)
    {
        m_dvalue = _value;
        QSlider::setValue ( (int) m_dvalue);
    }
}
}//end of namespace
