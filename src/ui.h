#ifndef UI_H
#define UI_H

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
    QVBoxLayout *layoutMain;

    void setupUi(QWidget *Browser)
    {
        QBrush brBase(QColor(10, 10, 10, 255));
        QBrush brWhite(QColor(255, 255, 255, 255));
        QBrush brBlack(QColor(0, 0, 0, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, brBase);
        p.setBrush(QPalette::Active, QPalette::Window, brBase);
        p.setBrush(QPalette::Active, QPalette::WindowText, brWhite);
        p.setBrush(QPalette::Active, QPalette::Text, brWhite);
        p.setBrush(QPalette::Active, QPalette::Highlight, brBlack);
        p.setBrush(QPalette::Active, QPalette::Button, brBase);
        p.setBrush(QPalette::Active, QPalette::ButtonText, brWhite);
        p.setBrush(QPalette::Disabled, QPalette::Base, brBase);
        p.setBrush(QPalette::Disabled, QPalette::Window, brBase);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, brBlack);
        p.setBrush(QPalette::Disabled, QPalette::Text, brBlack);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, brBase);
        p.setBrush(QPalette::Disabled, QPalette::Button, brBase);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, brBlack);

        QString styleProgressBar = "QProgressBar { background-color: rgb(10, 10, 10); \
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

        layoutMain = new QVBoxLayout(Browser);
        layoutMain->setSpacing(0);
        layoutMain->setMargin(0);

        Browser->setPalette(p);
        Browser->setLayout(layoutMain);
    }
};

class Ui_View
{
public:
    QWidget *widgetLayer;

    void setupUi(QWebEngineView *View)
    {
        QBrush brTransparent(QColor(45, 0, 80, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, brTransparent);
        p.setBrush(QPalette::Active, QPalette::Window, brTransparent);

        widgetLayer = new QWidget;
        widgetLayer->setPalette(p);
        widgetLayer->setFixedSize(300, 300); // TODO: %
        widgetLayer->setAutoFillBackground(true);
        //widgetLayer->setParent(View);
        //widgetLayer->setHidden(true);
        //widgetLayer->show();

        View->page()->setBackgroundColor(QColor(10, 10, 10));
    }
};

class Ui_Layer
{
public:
    QWidget *widgetDarkLayer;
    QLineEdit *lineEditUrl;
    QVBoxLayout *layout;
    QGridLayout *gridLayout;

    void setupUi(QWidget *Layer)
    {
        QFont f(":/font-global");
        f.setPointSize(12); // TODO: %
        f.setCapitalization(QFont::AllUppercase);
        f.setBold(true);

        QBrush brBase(QColor(0, 0, 0, 180));
        QBrush brBaseLineEditUrl(QColor(0, 0, 0, 50));
        QBrush brWhite(QColor(255, 255, 255, 255));
        QBrush brBlack(QColor(0, 0, 0, 255));
        QBrush brTransparent(QColor(0, 0, 0, 0));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, brTransparent);
        p.setBrush(QPalette::Active, QPalette::Window, brTransparent);
        p.setBrush(QPalette::Active, QPalette::WindowText, brWhite);
        p.setBrush(QPalette::Active, QPalette::Text, brWhite);
        p.setBrush(QPalette::Active, QPalette::Highlight, brBlack);
        p.setBrush(QPalette::Active, QPalette::Button, brTransparent);
        p.setBrush(QPalette::Active, QPalette::ButtonText, brWhite);
        p.setBrush(QPalette::Disabled, QPalette::Base, brTransparent);
        p.setBrush(QPalette::Disabled, QPalette::Window, brTransparent);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, brBlack);
        p.setBrush(QPalette::Disabled, QPalette::Text, brBlack);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, brTransparent);
        p.setBrush(QPalette::Disabled, QPalette::Button, brTransparent);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, brBlack);

        QPalette pDark;
        pDark.setBrush(QPalette::Active, QPalette::Base, brBase);
        pDark.setBrush(QPalette::Active, QPalette::Window, brBase);

        QPalette pLineEditUrl;
        pLineEditUrl.setBrush(QPalette::Active, QPalette::Base, brBaseLineEditUrl);
        pLineEditUrl.setBrush(QPalette::Active, QPalette::Window, brBaseLineEditUrl);
        pLineEditUrl.setBrush(QPalette::Active, QPalette::Text, brWhite);
        pLineEditUrl.setBrush(QPalette::Active, QPalette::Highlight, brTransparent);
        pLineEditUrl.setBrush(QPalette::Disabled, QPalette::Base, brBaseLineEditUrl);
        pLineEditUrl.setBrush(QPalette::Disabled, QPalette::Window, brBaseLineEditUrl);
        pLineEditUrl.setBrush(QPalette::Disabled, QPalette::Text, brBlack);
        pLineEditUrl.setBrush(QPalette::Disabled, QPalette::Highlight, brBaseLineEditUrl);

        widgetDarkLayer = new QWidget;
        widgetDarkLayer->setPalette(pDark);
        widgetDarkLayer->setFixedSize(1920, 1080); // TODO: %
        widgetDarkLayer->setAutoFillBackground(true);
        widgetDarkLayer->setParent(Layer);
        widgetDarkLayer->setHidden(true);

        lineEditUrl = new QLineEdit(Layer);
        lineEditUrl->setFont(f);
        lineEditUrl->setPalette(pLineEditUrl);
        lineEditUrl->setMinimumWidth(1920); // TODO: %
        lineEditUrl->setAlignment(Qt::AlignCenter);

        gridLayout = new QGridLayout;

        layout = new QVBoxLayout(Layer);
        layout->setMargin(0);
        layout->addSpacing(-1); // TODO: %
        layout->addWidget(lineEditUrl, Qt::AlignTop, Qt::AlignHCenter);
        layout->addLayout(gridLayout);
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
