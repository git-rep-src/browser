#ifndef UI_H
#define UI_H

#include "buttonminiature.h"

#include <QWebEngineView>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QGridLayout>

QT_BEGIN_NAMESPACE

class Ui_Browser
{
public:
    QProgressBar *progressbar;
    QVBoxLayout *layout_main;

    void setupUi(QWidget *Browser)
    {
        QBrush brush_base(QColor(10, 10, 10, 255));
        QBrush brush_white(QColor(255, 255, 255, 255));
        QBrush brush_black(QColor(0, 0, 0, 255));

        QPalette palette;
        palette.setBrush(QPalette::Active, QPalette::Base, brush_base);
        palette.setBrush(QPalette::Active, QPalette::Window, brush_base);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush_white);
        palette.setBrush(QPalette::Active, QPalette::Text, brush_white);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush_black);
        palette.setBrush(QPalette::Active, QPalette::Button, brush_base);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush_white);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush_black);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush_black);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush_black);

        QString style_progressbar;
        style_progressbar = "QProgressBar { background-color: rgb(10, 10, 10); \
                            border: 0px; }"
                           "QProgressBar::chunk { background-color: rgb(80, 80, 80); \
                            width: 1px; }";

        progressbar = new QProgressBar(Browser);
        progressbar->setStyleSheet(style_progressbar);
        progressbar->setFixedHeight(5);
        progressbar->setMinimum(0);
        progressbar->setMaximum(100);
        progressbar->setValue(0);
        progressbar->setTextVisible(false);
        progressbar->setHidden(true);

        layout_main = new QVBoxLayout(Browser);
        layout_main->setSpacing(0);
        layout_main->setMargin(0);
        layout_main->insertWidget(1, progressbar);

        Browser->setPalette(palette);
        Browser->setLayout(layout_main);
    }
};

class Ui_View
{
public:
    ButtonMiniature *button_miniature;
    QPushButton *button_miniature_close;

    void setupUi()
    {
        QBrush brush_transparent(QColor(0, 0, 0, 0));

        QPalette palette;
        palette.setBrush(QPalette::Active, QPalette::Base, brush_transparent);
        palette.setBrush(QPalette::Active, QPalette::Window, brush_transparent);

        button_miniature = new ButtonMiniature;
        button_miniature->setPalette(palette);
        button_miniature->setFixedSize(400, 300); // TODO: %
        button_miniature->setAutoFillBackground(true);
        button_miniature->setHidden(true);

        button_miniature_close = new QPushButton(QIcon(":/icon-close"), NULL);
        button_miniature_close->setParent(button_miniature);
        button_miniature_close->move(373, 0);
    }
};

class Ui_Layer
{
public:
    QLineEdit *lineedit_url;
    QPixmap pixmap_ssl;
    QPixmap pixmap_ssl_off;
    QLabel  *label_ssl;
    QGridLayout *layout_miniatures;
    QVBoxLayout *layout;

    void setupUi(QWidget *Layer)
    {
        QFont font("helvetica");
        font.setPointSize(16); // TODO: %
        font.setCapitalization(QFont::AllUppercase);
        font.setBold(true);

        QBrush brush_base(QColor(80, 80, 80, 220));
        QBrush brush_white(QColor(255, 255, 255, 255));
        QBrush brush_black(QColor(0, 0, 0, 255));

        QPalette palette;
        palette.setBrush(QPalette::Active, QPalette::Base, brush_base);
        palette.setBrush(QPalette::Active, QPalette::Window, brush_base);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush_white);
        palette.setBrush(QPalette::Active, QPalette::Text, brush_white);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush_black);
        palette.setBrush(QPalette::Active, QPalette::Button, brush_base);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush_white);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush_black);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush_black);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush_black);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush_base);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush_black);

        QString style_lineedit_url;
        style_lineedit_url = "QLineEdit { color: rgb(255, 255, 255); \
                              background: rgba(40, 40, 40, 255); \
                              selection-color: rgba(80, 80, 80, 255); \
                              selection-background-color: rgba(0, 0, 0, 0); \
                              border-radius: 12px; \
                              border: 0px; }";

        lineedit_url = new QLineEdit(Layer);
        lineedit_url->setFont(font);
        lineedit_url->setStyleSheet(style_lineedit_url);
        lineedit_url->setMinimumWidth(500);
        lineedit_url->setAlignment(Qt::AlignCenter);

        pixmap_ssl.load(":/icon-ssl");
        pixmap_ssl_off.load(":/icon-ssl-off");
        label_ssl = new QLabel(lineedit_url);
        label_ssl->setPixmap(pixmap_ssl_off);
        label_ssl->move(8, 9);

        layout_miniatures = new QGridLayout;

        layout = new QVBoxLayout(Layer);
        layout->setMargin(10);
        layout->addSpacing(10); // TODO: %
        layout->addWidget(lineedit_url, Qt::AlignTop, Qt::AlignHCenter);
        layout->addStretch(1);
        layout->addLayout(layout_miniatures);
        layout->addStretch(1);

        Layer->setPalette(palette);
        Layer->setFixedSize(1920, 1080); // TODO: %
        Layer->setAutoFillBackground(true);
        Layer->setLayout(layout);
    }
};

namespace Ui {
    class Browser: public Ui_Browser {};
    class View: public Ui_View {};
    class Layer: public Ui_Layer {};
}

QT_END_NAMESPACE

#endif // UI_H
