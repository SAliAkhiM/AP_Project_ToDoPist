QT       += core gui \
    quick
QT+=network
QT+=concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activity.cpp \
    activityinfo.cpp \
    listmanager.cpp \
    listwidget_mainwindow.cpp \
    login.cpp \
    logo.cpp \
    main.cpp \
    mainwindow.cpp \
    newactivitywindow.cpp \
    newlistwindow.cpp \
    sign_up_page.cpp \
    subactivity.cpp \
    user.cpp

HEADERS += \
    activity.h \
    activityinfo.h \
    data.h \
    listmanager.h \
    listwidget_mainwindow.h \
    login.h \
    logo.h \
    mainwindow.h \
    newactivitywindow.h \
    newlistwindow.h \
    sign_up_page.h \
    subactivity.h \
    user.h

FORMS += \
    activityinfo.ui \
    login.ui \
    logo.ui \
    mainwindow.ui \
    newactivitywindow.ui \
    newlistwindow.ui \
    sign_up_page.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pictures.qrc
