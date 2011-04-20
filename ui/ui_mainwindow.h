/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 20 16:41:25 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *s_mainLayout;
    QSpacerItem *horizontalSpacer;
    QGroupBox *s_camTransGB;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *s_objTransGB;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *m_rotX;
    QPushButton *m_rotY;
    QPushButton *m_rotZ;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QGroupBox *s_optGB;
    QGridLayout *gridLayout_2;
    QCheckBox *m_wireframeCheck;
    QComboBox *comboBox;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(797, 614);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        s_mainLayout = new QGridLayout(centralwidget);
        s_mainLayout->setObjectName(QString::fromUtf8("s_mainLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        s_mainLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        s_camTransGB = new QGroupBox(centralwidget);
        s_camTransGB->setObjectName(QString::fromUtf8("s_camTransGB"));
        gridLayout_3 = new QGridLayout(s_camTransGB);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(s_camTransGB);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        label_6 = new QLabel(s_camTransGB);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);


        s_mainLayout->addWidget(s_camTransGB, 1, 1, 1, 1);

        s_objTransGB = new QGroupBox(centralwidget);
        s_objTransGB->setObjectName(QString::fromUtf8("s_objTransGB"));
        gridLayout = new QGridLayout(s_objTransGB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(s_objTransGB);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_rotX = new QPushButton(s_objTransGB);
        m_rotX->setObjectName(QString::fromUtf8("m_rotX"));

        gridLayout->addWidget(m_rotX, 2, 0, 1, 1);

        m_rotY = new QPushButton(s_objTransGB);
        m_rotY->setObjectName(QString::fromUtf8("m_rotY"));

        gridLayout->addWidget(m_rotY, 3, 0, 1, 1);

        m_rotZ = new QPushButton(s_objTransGB);
        m_rotZ->setObjectName(QString::fromUtf8("m_rotZ"));

        gridLayout->addWidget(m_rotZ, 4, 0, 1, 1);

        pushButton_4 = new QPushButton(s_objTransGB);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 7, 0, 1, 1);

        pushButton_5 = new QPushButton(s_objTransGB);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 8, 0, 1, 1);

        pushButton_6 = new QPushButton(s_objTransGB);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 9, 0, 1, 1);

        label_2 = new QLabel(s_objTransGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 6, 0, 1, 1);


        s_mainLayout->addWidget(s_objTransGB, 0, 1, 1, 1);

        s_optGB = new QGroupBox(centralwidget);
        s_optGB->setObjectName(QString::fromUtf8("s_optGB"));
        gridLayout_2 = new QGridLayout(s_optGB);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_wireframeCheck = new QCheckBox(s_optGB);
        m_wireframeCheck->setObjectName(QString::fromUtf8("m_wireframeCheck"));

        gridLayout_2->addWidget(m_wireframeCheck, 0, 0, 1, 1);

        comboBox = new QComboBox(s_optGB);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_2->addWidget(comboBox, 2, 0, 1, 1);

        label_4 = new QLabel(s_optGB);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);


        s_mainLayout->addWidget(s_optGB, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 797, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        s_camTransGB->setTitle(QApplication::translate("MainWindow", "Camera local Transformation", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        s_objTransGB->setTitle(QApplication::translate("MainWindow", "Object Local Transformation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Rotation", 0, QApplication::UnicodeUTF8));
        m_rotX->setText(QApplication::translate("MainWindow", "RotateX", 0, QApplication::UnicodeUTF8));
        m_rotY->setText(QApplication::translate("MainWindow", "Rotate Y", 0, QApplication::UnicodeUTF8));
        m_rotZ->setText(QApplication::translate("MainWindow", "Rotate Z", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        s_optGB->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        m_wireframeCheck->setText(QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sphere", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Fish", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MainWindow", "Choose Model:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
