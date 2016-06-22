#ifndef UI_H
#define UI_H

#include "buttonminiature.h"

#include <QWebEngineView>
#include <QLineEdit>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QProgressBar *progressBar;
    QVBoxLayout *mainLayout;

    void setupUi(QWidget *Browser)
    {
        QBrush brushBase(QColor(10, 10, 10, 255));
        QBrush brushWhite(QColor(255, 255, 255, 255));
        QBrush brushBlack(QColor(0, 0, 0, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, brushBase);
        p.setBrush(QPalette::Active, QPalette::Window, brushBase);
        p.setBrush(QPalette::Active, QPalette::WindowText, brushWhite);
        p.setBrush(QPalette::Active, QPalette::Text, brushWhite);
        p.setBrush(QPalette::Active, QPalette::Highlight, brushBlack);
        p.setBrush(QPalette::Active, QPalette::Button, brushBase);
        p.setBrush(QPalette::Active, QPalette::ButtonText, brushWhite);
        p.setBrush(QPalette::Disabled, QPalette::Base, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::Window, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, brushBlack);
        p.setBrush(QPalette::Disabled, QPalette::Text, brushBlack);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::Button, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, brushBlack);

        QString styleProgressBar;
        styleProgressBar = "QProgressBar { background-color: rgb(10, 10, 10); \
                            border: 0px; }"
                           "QProgressBar::chunk { background-color: rgb(80, 80, 80); \
                            width: 1px; }";

        progressBar = new QProgressBar(Browser);
        progressBar->setStyleSheet(styleProgressBar);
        progressBar->setFixedHeight(5);
        progressBar->setMinimum(0);
        progressBar->setMaximum(100);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setHidden(true);

        mainLayout = new QVBoxLayout(Browser);
        mainLayout->setSpacing(0);
        mainLayout->setMargin(0);

        Browser->setPalette(p);
        Browser->setLayout(mainLayout);
    }
};

class Ui_View
{
public:
    ButtonMiniature *buttonMiniature;

    void setupUi(QWebEngineView *View)
    {
        QBrush brushTransparent(QColor(0, 0, 0, 0));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, brushTransparent);
        p.setBrush(QPalette::Active, QPalette::Window, brushTransparent);

        buttonMiniature = new ButtonMiniature;
        buttonMiniature->setPalette(p);
        buttonMiniature->setFixedSize(400, 300); // TODO: %
        buttonMiniature->setAutoFillBackground(true);
        buttonMiniature->setHidden(true);

        View->page()->setBackgroundColor(QColor(10, 10, 10));
    }
};

class Ui_Layer
{
public:
    QLineEdit *lineEditUrl;
    QGridLayout *layoutMiniatures;
    QVBoxLayout *layout;

    void setupUi(QWidget *Layer)
    {
        QFont f("helvetica");
        f.setPointSize(18); // TODO: %
        f.setCapitalization(QFont::AllUppercase);
        f.setBold(true);

        QBrush brushBase(QColor(0, 0, 0, 240));
        QBrush brushWhite(QColor(255, 255, 255, 255));
        QBrush brushBlack(QColor(0, 0, 0, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, brushBase);
        p.setBrush(QPalette::Active, QPalette::Window, brushBase);
        p.setBrush(QPalette::Active, QPalette::WindowText, brushWhite);
        p.setBrush(QPalette::Active, QPalette::Text, brushWhite);
        p.setBrush(QPalette::Active, QPalette::Highlight, brushBlack);
        p.setBrush(QPalette::Active, QPalette::Button, brushBase);
        p.setBrush(QPalette::Active, QPalette::ButtonText, brushWhite);
        p.setBrush(QPalette::Disabled, QPalette::Base, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::Window, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, brushBlack);
        p.setBrush(QPalette::Disabled, QPalette::Text, brushBlack);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, brushBlack);
        p.setBrush(QPalette::Disabled, QPalette::Button, brushBase);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, brushBlack);

        QString styleLineEditUrl;
        styleLineEditUrl = "QLineEdit { color: rgb(255, 255, 255); \
                            background: rgba(0, 0, 0, 0); \
                            selection-background-color: rgba(80, 80, 80, 100); \
                            border-radius: 20px; \
                            border: 0px; }";

        lineEditUrl = new QLineEdit(Layer);
        lineEditUrl->setFont(f);
        lineEditUrl->setStyleSheet(styleLineEditUrl);
        lineEditUrl->setAlignment(Qt::AlignCenter);

        layoutMiniatures = new QGridLayout;

        layout = new QVBoxLayout(Layer);
        layout->setMargin(10);
        layout->addSpacing(10); // TODO: %
        layout->addWidget(lineEditUrl, Qt::AlignTop, Qt::AlignHCenter);
        layout->addSpacing(25); // TODO: %
        layout->addLayout(layoutMiniatures);
        layout->addStretch(1);

        Layer->setPalette(p);
        Layer->setFixedSize(1920, 1080); // TODO: %
        Layer->setAutoFillBackground(true);
        Layer->setLayout(layout);
        Layer->setHidden(true);
    }
};

namespace Ui {
    class Browser: public Ui_Browser {};
    class View: public Ui_View {};
    class Layer: public Ui_Layer {};
}

QT_END_NAMESPACE

#endif // UI_H
