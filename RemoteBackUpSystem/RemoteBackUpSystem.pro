QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FolderItem.cpp \
    LibListItem.cpp \
    PlaneConfig.cpp \
    PlaneItem.cpp \
    PlaneList.cpp \
    RemoteFolder.cpp \
    TaskItem.cpp \
    TaskList.cpp \
    main.cpp \
    LibraryList.cpp

HEADERS += \
    FolderItem.h \
    LibListItem.h \
    LibraryList.h \
    PlaneConfig.h \
    PlaneItem.h \
    PlaneList.h \
    RemoteFolder.h \
    TaskItem.h \
    TaskList.h

FORMS += \
    FolderItem.ui \
    LibListItem.ui \
    LibraryList.ui \
    PlaneConfig.ui \
    PlaneItem.ui \
    PlaneList.ui \
    RemoteFolder.ui \
    TaskItem.ui \
    TaskList.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
