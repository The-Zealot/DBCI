QT -= gui
QT += network

TEMPLATE = lib
DEFINES += DBCI_LIB_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    armorydata.cpp \
    dbci_lib.cpp \
    htmlparser.cpp

HEADERS += \
    DBCI_lib_global.h \
    armorydata.h \
    dbci_lib.h \
    htmlparser.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
