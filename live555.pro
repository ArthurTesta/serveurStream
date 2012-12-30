#-------------------------------------------------
#
# Project created by QtCreator 2012-12-08T16:11:20
#
#-------------------------------------------------

QT       += core gui

TARGET = live555
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    DynamicRTSPServer.cpp \
    streaming.cpp

HEADERS  += mainwindow.h \
    DynamicRTSPServer.hh \
    version.hh \
    streaming.h

FORMS    += mainwindow.ui

LIBS += /usr/local/lib/live/liveMedia/libliveMedia.a \
            /usr/local/lib/live/BasicUsageEnvironment/libBasicUsageEnvironment.a \
            /usr/local/lib/live/UsageEnvironment/libUsageEnvironment.a \
            /usr/local/lib/live/groupsock/libgroupsock.a


#LIBS += -L "/usr/local/lib/live/UsageEnvironment/" -libUsageEnvironment.a
#LIBS += -L "/usr/local/lib/live/liveMedia/" -libliveMedia.a
#LIBS += -L "/usr/local/lib/live/BasicUsageEnvironment/" -libBasicUsageEnvironment.a
#LIBS += -L "/usr/local/lib/live/groupsock/" -libgroupsock.a

INCLUDEPATH += /usr/local/lib/live/UsageEnvironment/include
INCLUDEPATH += /usr/local/lib/live/liveMedia/include
INCLUDEPATH += /usr/local/lib/live/BasicUsageEnvironment/include
INCLUDEPATH += /usr/local/lib/live/groupsock/include
