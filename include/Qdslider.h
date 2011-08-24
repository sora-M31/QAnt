#ifndef _QDSLIDER_H_
#define _QDSLIDER_H_

#include <QSlider.h>
namespace Ui
{
class Qdslider:public QSlider
{
    Q_OBJECT
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        /// \param parent
        Qdslider( QWidget* parent );
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~Qdslider();
    signals:
        // --------------------------------------------------------------------------
        /// \brief Signal when value is changed
        /// \param _value New value
        void valueChanged( double _value );
    private slots:
        // --------------------------------------------------------------------------
        /// \brief slot, set the value to new value
        /// \param _value
        void setValue( double _value );
        // --------------------------------------------------------------------------
        /// \brief slot, cast int to double
        /// \param _value value to change to double
        void toDouble( int _value );
    private:
        ///\double version of m_value;
        double m_dvalue;

};//end of class
}//end of namespace
#endif //end of define
