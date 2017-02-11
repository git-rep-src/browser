#ifndef UI_H
#define UI_H

#include "tabbutton.h"

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
    QProgressBar *page_progressbar;
    QVBoxLayout *main_layout;

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

        QString page_progressbar_stylesheet =
            "QProgressBar { \
             background-color: rgb(10, 10, 10); \
             border: 0px; \
            }"
            "QProgressBar::chunk { \
             background-color: rgb(100, 100, 100); \
             width: 1px; \
            }";

        page_progressbar = new QProgressBar(Browser);
        page_progressbar->setStyleSheet(page_progressbar_stylesheet);
        page_progressbar->setFixedHeight(5);
        page_progressbar->setMinimum(0);
        page_progressbar->setMaximum(100);
        page_progressbar->setValue(0);
        page_progressbar->setTextVisible(false);
        page_progressbar->setHidden(true);

        main_layout = new QVBoxLayout(Browser);
        main_layout->setSpacing(0);
        main_layout->setMargin(0);
        main_layout->insertWidget(1, page_progressbar);

        Browser->setPalette(palette);
        Browser->setLayout(main_layout);
    }
};

class Ui_View
{
public:
    ButtonTab *tab_button;
    QPushButton *tab_delete_button;

    void setupUi()
    {
        QBrush brush(QColor(0, 0, 0, 0));

        QPalette palette;
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);

        tab_button = new ButtonTab;
        tab_button->setPalette(palette);
        tab_button->setAutoFillBackground(true);
        tab_button->setHidden(true);

        tab_delete_button = new QPushButton(QIcon(":/icon-delete"), NULL);
        tab_delete_button->setParent(tab_button);
        //tab_delete_button->setHidden(true);
    }
};

class Ui_Layer
{
public:
    QTextEdit *url_textedit;
    QScrollBar *url_scrollbar;
    QPixmap ssl_pixmap;
    QPixmap no_ssl_pixmap;
    QLabel  *ssl_label;
    QWidget *url_widget;
    QWidget *tabs_widget;
    QHBoxLayout *url_hlayout;
    QHBoxLayout *tabs_hlayout;
    QVBoxLayout *layout;

    void setupUi(QWidget *Layer)
    {
        QFont font("helvetica");
        font.setPointSize(14); // TODO: %
        font.setCapitalization(QFont::AllUppercase);
        font.setBold(true);

        QBrush brush_base(QColor(255, 255, 255, 180));
        QBrush url_widget_brush(QColor(0, 0, 0, 255));
        QBrush tab_widget_brush(QColor(0, 0, 0, 255));
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

        QPalette url_widget_palette;
        url_widget_palette.setBrush(QPalette::Active, QPalette::Base, url_widget_brush);
        url_widget_palette.setBrush(QPalette::Active, QPalette::Window, url_widget_brush);
        url_widget_palette.setBrush(QPalette::Active, QPalette::WindowText, brush_white);
        url_widget_palette.setBrush(QPalette::Active, QPalette::Text, brush_white);
        url_widget_palette.setBrush(QPalette::Active, QPalette::Highlight, brush_black);
        url_widget_palette.setBrush(QPalette::Active, QPalette::Button, url_widget_brush);
        url_widget_palette.setBrush(QPalette::Active, QPalette::ButtonText, brush_white);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::Base, url_widget_brush);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::Window, url_widget_brush);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush_black);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::Text, brush_black);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush_black);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::Button, url_widget_brush);
        url_widget_palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush_black);

        QPalette tab_widget_palette;
        tab_widget_palette.setBrush(QPalette::Active, QPalette::Base, tab_widget_brush);
        tab_widget_palette.setBrush(QPalette::Active, QPalette::Window, tab_widget_brush);
        tab_widget_palette.setBrush(QPalette::Active, QPalette::WindowText, brush_white);
        tab_widget_palette.setBrush(QPalette::Active, QPalette::Text, brush_white);
        tab_widget_palette.setBrush(QPalette::Active, QPalette::Highlight, brush_black);
        tab_widget_palette.setBrush(QPalette::Active, QPalette::Button, tab_widget_brush);
        tab_widget_palette.setBrush(QPalette::Active, QPalette::ButtonText, brush_white);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::Base, tab_widget_brush);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::Window, tab_widget_brush);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush_black);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::Text, brush_black);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush_black);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::Button, tab_widget_brush);
        tab_widget_palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush_black);

        QString url_stylesheet =
            "QTextEdit { \
             color: rgb(255, 255, 255); \
             background: rgba(20, 20, 20, 100); \
             selection-color: rgba(80, 80, 80, 255); \
             selection-background-color: rgba(0, 0, 0, 0); \
             padding-left: 50px; \
             padding-right: 50px; \
             border-radius: 12px; \
             border: 0px; \
            }";

        url_hlayout = new QHBoxLayout;
        url_hlayout->setMargin(0);
        url_hlayout->setContentsMargins(0, 10, 0, 10); // TODO: %
        url_hlayout->setAlignment(Qt::AlignCenter);


        url_widget = new QWidget(Layer);
        url_widget->setPalette(url_widget_palette);
        url_widget->setAutoFillBackground(true);
        url_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        url_widget->setLayout(url_hlayout);

        url_scrollbar = new QScrollBar;

        url_textedit = new QTextEdit(url_widget);
        url_textedit->setFont(font);
        url_textedit->setStyleSheet(url_stylesheet);
        url_textedit->setMinimumWidth(500); // TODO: %
        url_textedit->setMaximumHeight(32); // TODO: %
        url_textedit->setLineWrapMode(QTextEdit::NoWrap);
        url_textedit->setVerticalScrollBar(url_scrollbar);
        url_textedit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        url_textedit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        url_textedit->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        url_textedit->setAlignment(Qt::AlignCenter);

        url_hlayout->addWidget(url_textedit);

        ssl_pixmap.load(":/icon-ssl");
        no_ssl_pixmap.load(":/icon-ssl-off");

        ssl_label = new QLabel(url_textedit);
        ssl_label->setPixmap(no_ssl_pixmap);
        ssl_label->move(8, 10); // TODO: %

        tabs_hlayout = new QHBoxLayout;
        tabs_hlayout->setMargin(0);
        tabs_hlayout->setSpacing(10);
        tabs_hlayout->setContentsMargins(10, 10, 10, 10);
        tabs_hlayout->setAlignment(Qt::AlignLeft);

        tabs_widget= new QWidget(Layer);
        tabs_widget->setPalette(tab_widget_palette);
        tabs_widget->setAutoFillBackground(true);
        tabs_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        tabs_widget->setVisible(false);
        tabs_widget->setLayout(tabs_hlayout);

        layout = new QVBoxLayout(Layer);
        layout->setMargin(0);
        layout->addWidget(url_widget);
        layout->addStretch(1);
        layout->addWidget(tabs_widget);

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
