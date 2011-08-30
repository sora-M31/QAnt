#ifndef _QTEXTPUSHBUTTON_H_
#define _QTEXTPUSHBUTTON_H_

#include<QPushButton.h>
namespace Ui
{
class QtextPushButton:public QPushButton
{
    Q_OBJECT
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        /// \param parent
        QtextPushButton( const QString &text ="start", QWidget* parent=0);
        QtextPushButton( QWidget* parent=0);
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~QtextPushButton();
    signals:
        void start();
        void stop();
    private slots:
        void changeText();
    private:
        ///\double version of m_value;
        bool m_checked;

};//end of class
}//end of namespace
#endif //end of define

