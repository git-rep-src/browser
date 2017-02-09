QT += core gui webenginewidgets

TARGET = browser
TEMPLATE = app

SOURCES += src/main.cpp \
           src/browser.cpp \
           src/view.cpp \
           src/layer.cpp \
           src/buttontab.cpp

HEADERS  += src/browser.h \
            src/view.h \
            src/layer.h \
            src/ui.h \
            src/buttontab.h

RESOURCES = resources.qrc

RC_FILE = resources/images/global/icon.rc

OBJECTS_DIR = .build/.obj
MOC_DIR = .build/.moc
RCC_DIR = .build/.rcc
