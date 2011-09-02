#include "QtextPushButton.h"
#include <iostream>

namespace Ui
{
//------------------------------------------------------------------------------
QtextPushButton::QtextPushButton( const QString& text,
                                  QWidget* parent )
                                : QPushButton(text, parent)
{
    m_checked = false;
    connect(this,SIGNAL(released()), this, SLOT(changeText()) );
}
//------------------------------------------------------------------------------
QtextPushButton::QtextPushButton(QWidget* parent )
                                : QPushButton(parent)
{
    m_checked = false;
    QPushButton::setText("start");
    connect(this,SIGNAL(clicked()), this, SLOT(changeText()) );
}
//------------------------------------------------------------------------------
QtextPushButton::~QtextPushButton()
{
}
//------------------------------------------------------------------------------
void QtextPushButton::changeText()
{
    if( m_checked == false)
    {
        emit start();
        setText("stop");
        m_checked = true;
    }
    else if( m_checked == true)
    {
        emit stop();
        setText("restart");
        m_checked = false;
    }
}
}//end of namespace
