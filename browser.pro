QT += core gui webenginewidgets

TARGET = browser
TEMPLATE = app

SOURCES += src/main.cpp \
           src/browser.cpp \
           src/view.cpp \
           src/layer.cpp \
           src/minipagebutton.cpp

HEADERS  += src/browser.h \
            src/view.h \
            src/layer.h \
            src/ui.h \
            src/minipagebutton.h

RESOURCES = resources.qrc

RC_FILE = resources/images/global/icon.rc
