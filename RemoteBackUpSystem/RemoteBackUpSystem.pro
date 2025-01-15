QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

LIBS += -lws2_32

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FileTransmission.cpp \
    FolderItem.cpp \
    LibListItem.cpp \
    PlaneConfig.cpp \
    PlaneItem.cpp \
    PlaneList.cpp \
    RemoteFolder.cpp \
    TaskItem.cpp \
    TaskList.cpp \
    main.cpp \
    LibraryList.cpp \

HEADERS += \
    FileTransmission.h \
    FolderItem.h \
    LibListItem.h \
    LibraryList.h \
    PlaneConfig.h \
    PlaneItem.h \
    PlaneList.h \
    RemoteFolder.h \
    TaskItem.h \
    TaskList.h \

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
