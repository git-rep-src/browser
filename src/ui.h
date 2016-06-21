#ifndef UI_H
#define UI_H

#include "minipagebutton.h"

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
        QBrush baseBrush(QColor(10, 10, 10, 255));
        QBrush whiteBrush(QColor(255, 255, 255, 255));
        QBrush blackBrush(QColor(0, 0, 0, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, baseBrush);
        p.setBrush(QPalette::Active, QPalette::Window, baseBrush);
        p.setBrush(QPalette::Active, QPalette::WindowText, whiteBrush);
        p.setBrush(QPalette::Active, QPalette::Text, whiteBrush);
        p.setBrush(QPalette::Active, QPalette::Highlight, blackBrush);
        p.setBrush(QPalette::Active, QPalette::Button, baseBrush);
        p.setBrush(QPalette::Active, QPalette::ButtonText, whiteBrush);
        p.setBrush(QPalette::Disabled, QPalette::Base, baseBrush);
        p.setBrush(QPalette::Disabled, QPalette::Window, baseBrush);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, blackBrush);
        p.setBrush(QPalette::Disabled, QPalette::Text, blackBrush);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, baseBrush);
        p.setBrush(QPalette::Disabled, QPalette::Button, baseBrush);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, blackBrush);

        QString progressBarStyle;
        progressBarStyle = "QProgressBar { background-color: rgb(10, 10, 10); \
                            border: 0px; }"
                           "QProgressBar::chunk { background-color: rgb(80, 80, 80); \
                            width: 1px; }";

        progressBar = new QProgressBar(Browser);
        progressBar->setStyleSheet(progressBarStyle);
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
    MiniPageButton *miniPageButton;

    void setupUi(QWebEngineView *View)
    {
        QBrush transparentBrush(QColor(0, 0, 0, 0));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, transparentBrush);
        p.setBrush(QPalette::Active, QPalette::Window, transparentBrush);

        miniPageButton = new MiniPageButton;
        miniPageButton->setPalette(p);
        miniPageButton->setFixedSize(400, 300); // TODO: %
        miniPageButton->setAutoFillBackground(true);
        miniPageButton->setHidden(true);

        View->page()->setBackgroundColor(QColor(10, 10, 10));
    }
};

class Ui_Layer
{
public:
    QWidget *tabWidget;
    QLineEdit *urlEdit;
    QVBoxLayout *layout;
    QGridLayout *gridLayout;

    void setupUi(QWidget *Layer)
    {
        QFont f("helvetica");
        f.setPointSize(14); // TODO: %
        f.setCapitalization(QFont::AllUppercase);
        f.setBold(true);

        QBrush baseBrush(QColor(0, 0, 0, 230));
        QBrush whiteBrush(QColor(255, 255, 255, 255));
        QBrush blackBrush(QColor(0, 0, 0, 255));
        QBrush transparentBrush(QColor(0, 0, 0, 0));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, transparentBrush);
        p.setBrush(QPalette::Active, QPalette::Window, transparentBrush);
        p.setBrush(QPalette::Active, QPalette::WindowText, whiteBrush);
        p.setBrush(QPalette::Active, QPalette::Text, whiteBrush);
        p.setBrush(QPalette::Active, QPalette::Highlight, blackBrush);
        p.setBrush(QPalette::Active, QPalette::Button, transparentBrush);
        p.setBrush(QPalette::Active, QPalette::ButtonText, whiteBrush);
        p.setBrush(QPalette::Disabled, QPalette::Base, transparentBrush);
        p.setBrush(QPalette::Disabled, QPalette::Window, transparentBrush);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, blackBrush);
        p.setBrush(QPalette::Disabled, QPalette::Text, blackBrush);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, transparentBrush);
        p.setBrush(QPalette::Disabled, QPalette::Button, transparentBrush);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, blackBrush);

        QPalette tabP;
        tabP.setBrush(QPalette::Active, QPalette::Base, baseBrush);
        tabP.setBrush(QPalette::Active, QPalette::Window, baseBrush);

        QString styleEditUrl;
        styleEditUrl = "QLineEdit { color: rgb(255, 255, 255); \
                        background: rgba(0, 0, 0, 50); \
                        selection-background-color: rgba(80, 80, 80, 100); \
                        border: 0px; }";

        tabWidget = new QWidget;
        tabWidget->setPalette(tabP);
        tabWidget->setFixedSize(1920, 1080); // TODO: %
        tabWidget->setAutoFillBackground(true);
        tabWidget->setParent(Layer);
        tabWidget->setHidden(true);

        urlEdit = new QLineEdit(Layer);
        urlEdit->setFont(f);
        urlEdit->setStyleSheet(styleEditUrl);
        urlEdit->setMinimumWidth(1920); // TODO: %
        urlEdit->setAlignment(Qt::AlignCenter);

        gridLayout = new QGridLayout;

        layout = new QVBoxLayout(Layer);
        layout->setMargin(0);
        layout->addSpacing(-1); // TODO: %
        layout->addWidget(urlEdit, Qt::AlignTop, Qt::AlignHCenter);
        layout->addSpacing(50); // TODO: %
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
