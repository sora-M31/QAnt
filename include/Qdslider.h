#ifndef _QDSLIDER_H_
#define _QDSLIDER_H_

#include <QSlider.h>
namespace Ui
{
class Qdslider:public QSlider
{
    Q_OBJECT
    public:
        Qdslider(QWidget* parent);
        ~Qdslider();
    signals:
        void valueChanged( double _value);
    private slots:
        void setValue( double _value);
        void toDouble( int _value);
    private:
        ///\double version of m_value;
        double m_dvalue;

};//end of class
}//end of namespace
#endif //end of define
