TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += qt
QT += sql
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++1y -DMYSQL_LIBRARY=mysqlclient


LIBS += -L/usr/lib -lwt -lwthttp -lwtdbo -lwtdbosqlite3 -lwtdbomysql -lzdb -I/usr/local/include -I/usr/include/zdb
LIBS += -L/usr/local/lib -lwthttp -lwt -lboost_regex -lboost_signals
LIBS += -lboost_system -lboost_thread -lboost_filesystem -lboost_date_time -lpthread -lcrypt

INCLUDEPATH += ./Headers
CONFIG += no_keywords


unix|win32: LIBS += -lzdb
SOURCES += main.cpp \
    Router.cpp \
    FileManager.cpp \
    Track.cpp \
    Session.cpp \
    User.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    Router.h \
    FileManager.h \
    Track.h \
    User.h \
    Session.h
