/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Apr 13 16:17:32 2011
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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
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
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_7;
    QGroupBox *s_objTransGB;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *m_rotX;
    QLabel *label_2;
    QDoubleSpinBox *m_transX;
    QDoubleSpinBox *m_transY;
    QDoubleSpinBox *m_transZ;
    QDoubleSpinBox *m_rotY;
    QDoubleSpinBox *m_rotZ;
    QLabel *label_3;
    QDoubleSpinBox *m_scaleX;
    QDoubleSpinBox *m_scaleY;
    QDoubleSpinBox *m_scaleZ;
    QGroupBox *s_optGB;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox;
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

        doubleSpinBox = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));

        gridLayout_3->addWidget(doubleSpinBox, 1, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        gridLayout_3->addWidget(doubleSpinBox_2, 1, 1, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        gridLayout_3->addWidget(doubleSpinBox_3, 1, 2, 1, 1);

        label_6 = new QLabel(s_camTransGB);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        gridLayout_3->addWidget(doubleSpinBox_4, 3, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        gridLayout_3->addWidget(doubleSpinBox_5, 3, 1, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

        gridLayout_3->addWidget(doubleSpinBox_6, 3, 2, 1, 1);

        label_7 = new QLabel(s_camTransGB);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 4, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(s_camTransGB);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));

        gridLayout_3->addWidget(doubleSpinBox_7, 5, 0, 1, 1);


        s_mainLayout->addWidget(s_camTransGB, 1, 1, 1, 1);

        s_objTransGB = new QGroupBox(centralwidget);
        s_objTransGB->setObjectName(QString::fromUtf8("s_objTransGB"));
        gridLayout = new QGridLayout(s_objTransGB);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(s_objTransGB);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_rotX = new QDoubleSpinBox(s_objTransGB);
        m_rotX->setObjectName(QString::fromUtf8("m_rotX"));
        m_rotX->setMinimum(-360);
        m_rotX->setMaximum(360);

        gridLayout->addWidget(m_rotX, 1, 0, 1, 1);

        label_2 = new QLabel(s_objTransGB);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        m_transX = new QDoubleSpinBox(s_objTransGB);
        m_transX->setObjectName(QString::fromUtf8("m_transX"));

        gridLayout->addWidget(m_transX, 3, 0, 1, 1);

        m_transY = new QDoubleSpinBox(s_objTransGB);
        m_transY->setObjectName(QString::fromUtf8("m_transY"));

        gridLayout->addWidget(m_transY, 3, 1, 1, 1);

        m_transZ = new QDoubleSpinBox(s_objTransGB);
        m_transZ->setObjectName(QString::fromUtf8("m_transZ"));

        gridLayout->addWidget(m_transZ, 3, 2, 1, 1);

        m_rotY = new QDoubleSpinBox(s_objTransGB);
        m_rotY->setObjectName(QString::fromUtf8("m_rotY"));
        m_rotY->setMinimum(-360);
        m_rotY->setMaximum(360);

        gridLayout->addWidget(m_rotY, 1, 1, 1, 1);

        m_rotZ = new QDoubleSpinBox(s_objTransGB);
        m_rotZ->setObjectName(QString::fromUtf8("m_rotZ"));
        m_rotZ->setMinimum(-360);
        m_rotZ->setMaximum(360);

        gridLayout->addWidget(m_rotZ, 1, 2, 1, 1);

        label_3 = new QLabel(s_objTransGB);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        m_scaleX = new QDoubleSpinBox(s_objTransGB);
        m_scaleX->setObjectName(QString::fromUtf8("m_scaleX"));
        m_scaleX->setValue(1);

        gridLayout->addWidget(m_scaleX, 5, 0, 1, 1);

        m_scaleY = new QDoubleSpinBox(s_objTransGB);
        m_scaleY->setObjectName(QString::fromUtf8("m_scaleY"));
        m_scaleY->setValue(1);

        gridLayout->addWidget(m_scaleY, 5, 1, 1, 1);

        m_scaleZ = new QDoubleSpinBox(s_objTransGB);
        m_scaleZ->setObjectName(QString::fromUtf8("m_scaleZ"));
        m_scaleZ->setValue(1);

        gridLayout->addWidget(m_scaleZ, 5, 2, 1, 1);


        s_mainLayout->addWidget(s_objTransGB, 0, 1, 1, 1);

        s_optGB = new QGroupBox(centralwidget);
        s_optGB->setObjectName(QString::fromUtf8("s_optGB"));
        gridLayout_2 = new QGridLayout(s_optGB);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox = new QCheckBox(s_optGB);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 0, 0, 1, 1);

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
        s_camTransGB->setTitle(QApplication::translate("MainWindow", "Camera Transformation", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        s_objTransGB->setTitle(QApplication::translate("MainWindow", "Object Transformation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Rotation", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        s_optGB->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8));
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
