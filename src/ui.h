#ifndef UI_H
#define UI_H

#include "buttontab.h"

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
    QProgressBar *pb_page;
    QVBoxLayout *l_main;

    void setupUi(QWidget *Browser)
    {
        QBrush br_base(QColor(255, 255, 255, 255));
        QBrush br_white(QColor(255, 255, 255, 255));
        QBrush br_black(QColor(0, 0, 0, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, br_base);
        p.setBrush(QPalette::Active, QPalette::Window, br_base);
        p.setBrush(QPalette::Active, QPalette::WindowText, br_white);
        p.setBrush(QPalette::Active, QPalette::Text, br_white);
        p.setBrush(QPalette::Active, QPalette::Highlight, br_black);
        p.setBrush(QPalette::Active, QPalette::Button, br_base);
        p.setBrush(QPalette::Active, QPalette::ButtonText, br_white);
        p.setBrush(QPalette::Disabled, QPalette::Base, br_base);
        p.setBrush(QPalette::Disabled, QPalette::Window, br_base);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, br_black);
        p.setBrush(QPalette::Disabled, QPalette::Text, br_black);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, br_base);
        p.setBrush(QPalette::Disabled, QPalette::Button, br_base);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, br_black);

        QString ss_pb_page = "QProgressBar { \
                                  background-color: rgb(10, 10, 10); \
                                  border: 0px; \
                             }"
                             "QProgressBar::chunk { \
                                  background-color: rgb(80, 80, 80); \
                                  width: 1px; \
                             }";

        pb_page = new QProgressBar(Browser);
        pb_page->setStyleSheet(ss_pb_page);
        pb_page->setFixedHeight(5);
        pb_page->setMinimum(0);
        pb_page->setMaximum(100);
        pb_page->setValue(0);
        pb_page->setTextVisible(false);
        pb_page->setHidden(true);

        l_main = new QVBoxLayout(Browser);
        l_main->setSpacing(0);
        l_main->setMargin(0);
        l_main->insertWidget(1, pb_page);

        Browser->setPalette(p);
        Browser->setLayout(l_main);
    }
};

class Ui_View
{
public:
    ButtonMiniature *b_tab;
    QPushButton *b_tab_delete;

    void setupUi()
    {
        QBrush br_yellow(QColor(0, 0, 0, 70));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, br_yellow);
        p.setBrush(QPalette::Active, QPalette::Window, br_yellow);

        b_tab = new ButtonMiniature;
        b_tab->setPalette(p);
        b_tab->setAutoFillBackground(true);
        b_tab->setHidden(true);

        b_tab_delete = new QPushButton(QIcon(":/icon-delete"), NULL);
        b_tab_delete->setParent(b_tab);
        b_tab_delete->setHidden(true);
    }
};

class Ui_Layer
{
public:
    QTextEdit *te_url;
    QScrollBar *sb_url;
    QPixmap pm_ssl;
    QPixmap pm_ssl_off;
    QLabel  *lb_ssl;
    QWidget *w_url;
    QWidget *w_tabs;
    QHBoxLayout *l_url;
    QHBoxLayout *l_tabs;
    QVBoxLayout *l;

    void setupUi(QWidget *Layer)
    {
        QFont f("helvetica");
        f.setPointSize(16); // TODO: %
        f.setCapitalization(QFont::AllUppercase);
        f.setBold(true);

        QBrush br_base(QColor(255, 255, 255, 180));
        QBrush br_widget_url(QColor(15, 15, 15, 255));
        QBrush br_widget_tab(QColor(15, 15, 15, 255));
        QBrush br_white(QColor(255, 255, 255, 255));
        QBrush br_black(QColor(0, 0, 0, 255));

        QPalette p;
        p.setBrush(QPalette::Active, QPalette::Base, br_base);
        p.setBrush(QPalette::Active, QPalette::Window, br_base);
        p.setBrush(QPalette::Active, QPalette::WindowText, br_white);
        p.setBrush(QPalette::Active, QPalette::Text, br_white);
        p.setBrush(QPalette::Active, QPalette::Highlight, br_black);
        p.setBrush(QPalette::Active, QPalette::Button, br_base);
        p.setBrush(QPalette::Active, QPalette::ButtonText, br_white);
        p.setBrush(QPalette::Disabled, QPalette::Base, br_base);
        p.setBrush(QPalette::Disabled, QPalette::Window, br_base);
        p.setBrush(QPalette::Disabled, QPalette::WindowText, br_black);
        p.setBrush(QPalette::Disabled, QPalette::Text, br_black);
        p.setBrush(QPalette::Disabled, QPalette::Highlight, br_black);
        p.setBrush(QPalette::Disabled, QPalette::Button, br_base);
        p.setBrush(QPalette::Disabled, QPalette::ButtonText, br_black);

        QPalette p_widget_url;
        p_widget_url.setBrush(QPalette::Active, QPalette::Base, br_widget_url);
        p_widget_url.setBrush(QPalette::Active, QPalette::Window, br_widget_url);
        p_widget_url.setBrush(QPalette::Active, QPalette::WindowText, br_white);
        p_widget_url.setBrush(QPalette::Active, QPalette::Text, br_white);
        p_widget_url.setBrush(QPalette::Active, QPalette::Highlight, br_black);
        p_widget_url.setBrush(QPalette::Active, QPalette::Button, br_widget_url);
        p_widget_url.setBrush(QPalette::Active, QPalette::ButtonText, br_white);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::Base, br_widget_url);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::Window, br_widget_url);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::WindowText, br_black);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::Text, br_black);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::Highlight, br_black);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::Button, br_widget_url);
        p_widget_url.setBrush(QPalette::Disabled, QPalette::ButtonText, br_black);

        QPalette p_widget_tab;
        p_widget_tab.setBrush(QPalette::Active, QPalette::Base, br_widget_tab);
        p_widget_tab.setBrush(QPalette::Active, QPalette::Window, br_widget_tab);
        p_widget_tab.setBrush(QPalette::Active, QPalette::WindowText, br_white);
        p_widget_tab.setBrush(QPalette::Active, QPalette::Text, br_white);
        p_widget_tab.setBrush(QPalette::Active, QPalette::Highlight, br_black);
        p_widget_tab.setBrush(QPalette::Active, QPalette::Button, br_widget_tab);
        p_widget_tab.setBrush(QPalette::Active, QPalette::ButtonText, br_white);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::Base, br_widget_tab);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::Window, br_widget_tab);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::WindowText, br_black);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::Text, br_black);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::Highlight, br_black);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::Button, br_widget_tab);
        p_widget_tab.setBrush(QPalette::Disabled, QPalette::ButtonText, br_black);

        QString ss_url = "QTextEdit { \
                              color: rgb(255, 255, 255); \
                              background: rgba(40, 40, 40, 255); \
                              selection-color: rgba(80, 80, 80, 255); \
                              selection-background-color: rgba(0, 0, 0, 0); \
                              padding-left: 50px; \
                              padding-right: 50px; \
                              border-radius: 12px; \
                              border: 0px; \
                         }";

        l_url = new QHBoxLayout;
        l_url->setMargin(0);
        l_url->setContentsMargins(0, 10, 0, 10);
        l_url->setAlignment(Qt::AlignCenter);

        w_url = new QWidget(Layer);
        w_url->setPalette(p_widget_url);
        w_url->setAutoFillBackground(true);
        w_url->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        w_url->setLayout(l_url);

        sb_url = new QScrollBar;

        te_url = new QTextEdit(w_url);
        te_url->setFont(f);
        te_url->setStyleSheet(ss_url);
        te_url->setMinimumWidth(500); // TODO: %
        te_url->setMaximumHeight(32); // TODO: %
        te_url->setLineWrapMode(QTextEdit::NoWrap);
        te_url->setVerticalScrollBar(sb_url);
        te_url->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        te_url->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        te_url->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        te_url->setAlignment(Qt::AlignCenter);

        l_url->addWidget(te_url);

        pm_ssl.load(":/icon-ssl");
        pm_ssl_off.load(":/icon-ssl-off");

        lb_ssl = new QLabel(te_url);
        lb_ssl->setPixmap(pm_ssl_off);
        lb_ssl->move(8, 9.9); // TODO: %

        l_tabs = new QHBoxLayout;
        l_tabs->setMargin(0);
        l_tabs->setSpacing(10);
        l_tabs->setContentsMargins(10, 10, 10, 10);
        l_tabs->setAlignment(Qt::AlignLeft);

        w_tabs= new QWidget(Layer);
        w_tabs->setPalette(p_widget_tab);
        w_tabs->setAutoFillBackground(true);
        w_tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        w_tabs->setVisible(false);
        w_tabs->setLayout(l_tabs);

        l = new QVBoxLayout(Layer);
        l->setMargin(0);
        l->addWidget(w_url);
        l->addStretch(1);
        l->addWidget(w_tabs);

        Layer->setPalette(p);
        Layer->setFixedSize(1920, 1080); // TODO: %
        Layer->setAutoFillBackground(true);
        Layer->setLayout(l);
    }
};

namespace Ui {
    class Browser: public Ui_Browser {};
    class View: public Ui_View {};
    class Layer: public Ui_Layer {};
}

QT_END_NAMESPACE

#endif // UI_H
