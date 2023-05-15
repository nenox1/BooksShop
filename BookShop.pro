QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogbuybook.cpp \
    dlgnewbook.cpp \
    dlgnewrecord.cpp \
    main.cpp \
    mainwindow.cpp \
    qdialoggenre.cpp

HEADERS += \
    connection.h \
    dialogbuybook.h \
    dlgnewbook.h \
    dlgnewrecord.h \
    mainwindow.h \
    qdialoggenre.h

FORMS += \
    dialogbuybook.ui \
    dlgnewbook.ui \
    dlgnewrecord.ui \
    mainwindow.ui \
    qdialoggenre.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Icons/add.png \
    Icons/close.png

RESOURCES +=
