QT += opengl \
       gui \
       core
INCLUDEPATH += include/
        += ui
OBJECTS_DIR = obj/
MOC_DIR = moc/
UI_HEADERS_DIR = ui/
TARGET = bin/test
CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/GLWindow.cpp

HEADERS += \
    include/mainwindow.h \
    ui/ui_mainwindow.h \
    include/GLWindow.h

FORMS += \
    ui/mainwindow.ui
