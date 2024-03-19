QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    importform.cpp \
    main.cpp \
    mainwindow.cpp \
    viewform.cpp

HEADERS += \
    importform.h \
    mainwindow.h \
    viewform.h

FORMS += \
    importform.ui \
    mainwindow.ui \
    viewform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DBCI_lib/release/ -lDBCI_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DBCI_lib/debug/ -lDBCI_lib
else:unix: LIBS += -L$$OUT_PWD/../DBCI_lib/ -lDBCI_lib

INCLUDEPATH += $$PWD/../DBCI_lib
DEPENDPATH += $$PWD/../DBCI_lib

RESOURCES += \
    resource.qrc
