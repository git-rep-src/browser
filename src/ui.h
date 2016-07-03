#ifndef UI_H
#define UI_H

#include "buttonminiature.h"

#include <QWebEngineView>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QScrollBar>
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
        QBrush brush_base(QColor(255, 255, 255, 255));
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

        QString style_progressbar = "QProgressBar { \
                                         background-color: rgb(10, 10, 10); \
                                         border: 0px; \
                                     }"
                                    "QProgressBar::chunk { \
                                         background-color: rgb(80, 80, 80); \
                                         width: 1px; \
                                     }";

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
        button_miniature->setAutoFillBackground(true);
        button_miniature->setHidden(true);

        button_miniature_close = new QPushButton(QIcon(":/icon-close"), NULL);
        button_miniature_close->setParent(button_miniature);
        //button_miniature_close->move(373, 0);
    }
};

class Ui_Layer
{
public:
    QTextEdit *text_url;
    QScrollBar *scrollbar_text_url;
    QPixmap pixmap_ssl;
    QPixmap pixmap_ssl_off;
    QLabel  *label_ssl;
    QWidget *widget_text_url;
    QWidget *widget_miniatures;
    QHBoxLayout *layout_text_url;
    QHBoxLayout *layout_miniatures;
    QVBoxLayout *layout;

    void setupUi(QWidget *Layer)
    {
        QFont font("helvetica");
        font.setPointSize(16); // TODO: %
        font.setCapitalization(QFont::AllUppercase);
        font.setBold(true);

        QBrush brush_base(QColor(150, 150, 150, 150));
        QBrush brush_base_widget(QColor(0, 0, 0, 230));
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

        QPalette palette_widget;
        palette_widget.setBrush(QPalette::Active, QPalette::Base, brush_base_widget);
        palette_widget.setBrush(QPalette::Active, QPalette::Window, brush_base_widget);
        palette_widget.setBrush(QPalette::Active, QPalette::WindowText, brush_white);
        palette_widget.setBrush(QPalette::Active, QPalette::Text, brush_white);
        palette_widget.setBrush(QPalette::Active, QPalette::Highlight, brush_black);
        palette_widget.setBrush(QPalette::Active, QPalette::Button, brush_base_widget);
        palette_widget.setBrush(QPalette::Active, QPalette::ButtonText, brush_white);
        palette_widget.setBrush(QPalette::Disabled, QPalette::Base, brush_base_widget);
        palette_widget.setBrush(QPalette::Disabled, QPalette::Window, brush_base_widget);
        palette_widget.setBrush(QPalette::Disabled, QPalette::WindowText, brush_black);
        palette_widget.setBrush(QPalette::Disabled, QPalette::Text, brush_black);
        palette_widget.setBrush(QPalette::Disabled, QPalette::Highlight, brush_black);
        palette_widget.setBrush(QPalette::Disabled, QPalette::Button, brush_base_widget);
        palette_widget.setBrush(QPalette::Disabled, QPalette::ButtonText, brush_black);

        QString style_text_url = "QTextEdit { \
                                      color: rgb(255, 255, 255); \
                                      background: rgba(40, 40, 40, 255); \
                                      selection-color: rgba(80, 80, 80, 255); \
                                      selection-background-color: rgba(0, 0, 0, 0); \
                                      padding-left: 50px; \
                                      padding-right: 50px; \
                                      border-radius: 12px; \
                                      border: 0px; \
                                  }";

        layout_text_url = new QHBoxLayout;
        layout_text_url->setMargin(0);
        layout_text_url->setContentsMargins(0, 20, 0, 20);
        layout_text_url->setAlignment(Qt::AlignCenter);

        widget_text_url = new QWidget(Layer);
        widget_text_url->setPalette(palette_widget);
        widget_text_url->setAutoFillBackground(true);
        widget_text_url->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        widget_text_url->setLayout(layout_text_url);

        scrollbar_text_url = new QScrollBar;

        text_url = new QTextEdit(widget_text_url);
        text_url->setFont(font);
        text_url->setStyleSheet(style_text_url);
        text_url->setMinimumWidth(500); // TODO: %
        text_url->setMaximumHeight(32); // TODO: %
        text_url->setLineWrapMode(QTextEdit::NoWrap);
        text_url->setVerticalScrollBar(scrollbar_text_url);
        text_url->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_url->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        text_url->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        text_url->setAlignment(Qt::AlignCenter);

        layout_text_url->addWidget(text_url);

        pixmap_ssl.load(":/icon-ssl");
        pixmap_ssl_off.load(":/icon-ssl-off");

        label_ssl = new QLabel(text_url);
        label_ssl->setPixmap(pixmap_ssl_off);
        label_ssl->move(8, 9.9); // TODO: %

        layout_miniatures = new QHBoxLayout;
        layout_miniatures->setMargin(0);
        layout_miniatures->setContentsMargins(15, 0, 15, 0);
        layout_miniatures->setAlignment(Qt::AlignLeft);

        widget_miniatures= new QWidget(Layer);
        widget_miniatures->setPalette(palette_widget);
        widget_miniatures->setAutoFillBackground(true);
        widget_miniatures->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        widget_miniatures->setLayout(layout_miniatures);

        layout = new QVBoxLayout(Layer);
        layout->setMargin(0);
        layout->addWidget(widget_text_url);
        layout->addStretch(1);
        layout->addWidget(widget_miniatures);

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
