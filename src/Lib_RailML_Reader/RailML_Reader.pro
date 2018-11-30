QT += xml core

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    common3.cpp \
    infrastructure.cpp \
    rtm4railml3.cpp \
    railml.cpp \
    railml_export.cpp \
    railmllibrary.cpp

HEADERS += \
    common3.h \
    infrastructure.h \
    rtm4railml3.h \
    railml.h \
    railmllibrary.h

TEMPLATE = lib

TARGET = RailMLReader

win32:LIBS += -L../../../bin -lfunctions

DESTDIR = ..\\..\\..\\bin
