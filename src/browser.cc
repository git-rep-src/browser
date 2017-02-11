#include "browser.h"

Browser::Browser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Browser),
    view(NULL),
    layer(NULL),
    current(0),
    is_link_to_tab(false)
{
    ui->setupUi(this);

    layer = new Layer(this);
    layer->get_ui()->url_textedit->installEventFilter(this);

    this->installEventFilter(this);
}

Browser::~Browser()
{
    for (uint i = 1; i <= views.size(); i++)
        if (views[i - 1] != NULL)
            delete views[i - 1];
    delete layer;
    delete ui;
}

void Browser::create_view(QUrl url, bool is_link)
{
    view = new View(ui, layer);
    connect(view, &View::link_clicked, [=] (QUrl url) {
        if (is_link_to_tab)
            create_view(url, true);
        else
   // TODO: if (mouse-click)
               views[current]->load_url(url);
    });
    view->load_url(url, !is_link);

    views.push_back(view);
    if (views.size() > 1)
        add_tab((views.size() - 1), false, is_link);

    if (!is_link) {
        ui->main_layout->insertWidget(0, views.back());
        current = (views.size() - 1);
    }
}

void Browser::add_tab(int index, bool rotate, bool is_link)
{
    int tab;
    int self;

    if (is_link) {
        tab = current;
        self = index;
    } else {
        tab = index;
        self = current;
        ui->main_layout->removeWidget(views[self]);
    }

    qDebug() << "ADD:" << "TAB" << tab << "SELF" << self;
    layer->get_ui()->tabs_hlayout->addWidget(views[self]);
    views[self]->setMaximumSize(300, 250); // TODO: %
    views[self]->setZoomFactor(0.35);
    views[self]->get_ui()->tab_button->setParent(views[self]);
    views[self]->get_ui()->tab_button->show();
    views[self]->get_ui()->tab_button->disconnect();
    views[self]->get_ui()->tab_delete_button->disconnect();
    connect(views[self]->get_ui()->tab_button, &ButtonTab::clicked, [=] {
        views[self]->get_ui()->tab_button->disconnect();
        add_tab(self, true);
    });
    connect(views[self]->get_ui()->tab_delete_button, &QPushButton::released, [=] {
        delete_tab(self);
    });

    if (rotate)
        open_tab(tab);

    if (layer->get_ui()->tabs_widget->isHidden())
        layer->get_ui()->tabs_widget->show();
}

void Browser::open_tab(int tab)
{
    layer->get_ui()->tabs_hlayout->removeWidget(views[tab]);
    views[tab]->get_ui()->tab_button->hide();
    views[tab]->get_ui()->tab_button->setParent(NULL);
    views[tab]->setMaximumSize(1920, 1080); // TODO: %
    views[tab]->setZoomFactor(1.0);
    ui->main_layout->insertWidget(0, views[tab]);

    QUrl url = views[tab]->url();
    layer->set_url(url);

    current = tab;
    layer->set_visible(this);
}

void Browser::delete_tab(int tab)
{
    layer->get_ui()->tabs_hlayout->removeWidget(views[tab]);
    delete views[tab];
    views.erase(views.begin() + tab);
    if (current != 0)
        --current;

    qDebug() << "DEL:" << "TAB" << tab << "VIEWSSIZE" << views.size();

    for (uint i = tab; i < (views.size() - 1); i++) {
        views[i]->get_ui()->tab_button->disconnect();
        views[i]->get_ui()->tab_delete_button->disconnect();
        connect(views[i]->get_ui()->tab_button, &ButtonTab::clicked, [=] {
            views[i]->get_ui()->tab_button->disconnect();
            add_tab(i, true);
        });
        connect(views[i]->get_ui()->tab_delete_button, &QPushButton::released, [=] {
            delete_tab(i);
        });
    }

    if (views.size() <= 1)
        layer->get_ui()->tabs_widget->hide();
}

bool Browser::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent *key = static_cast<QKeyEvent *>(e);
        if (o == this) {
            switch(key->key()) {
                case Qt::Key_Left:
                    views[current]->back();
                    break;
                case Qt::Key_Right:
                    views[current]->forward();
                    break;
                case Qt::Key_Plus:
                    if (key->modifiers() == Qt::ControlModifier)
                        views[current]->setZoomFactor((views[current]->zoomFactor()) + 0.10);
                    break;
                case Qt::Key_Minus:
                    if (key->modifiers() == Qt::ControlModifier)
                        views[current]->setZoomFactor((views[current]->zoomFactor()) - 0.10);
                    break;
                case Qt::Key_0:
                    if (key->modifiers() == Qt::ControlModifier)
                        views[current]->setZoomFactor(1.0);
                    break;
                case Qt::Key_Return:
                    views[current]->reload();
                    break;
                case Qt::Key_Escape:
                    if (views.size() != 0) {
                       delete views[current];
                       views[current] = NULL; // FIX
                    }
                    break;
                case Qt::Key_Q:
                    if (key->modifiers() == Qt::ControlModifier)
                        close();
                    break;
                default:
                    break;
            }
            if (key->modifiers() == Qt::MetaModifier)
                layer->set_visible(this);
            else if (key->modifiers() == Qt::ControlModifier)
                is_link_to_tab = true;
        } else if (o == layer->get_ui()->url_textedit) {
            switch(key->key()) {
                case Qt::Key_Return:
                    if (!layer->get_ui()->url_textedit->document()->toPlainText().simplified().isEmpty()) {
                        url.setUrl(layer->get_ui()->url_textedit->document()->toPlainText().simplified());
                        if ((key->modifiers() == Qt::ControlModifier) || (views.size() == 0)) {
                            create_view(url);
                        } else {
                            if (views.size() != 0) { // FIX
                                if (views[current] == NULL)
                                    create_view(url);
                                else
                                    views[current]->load_url(url);
                            }
                        }
                        layer->set_visible(this);
                    }
                    break;
                default:
                    break;
            }
        }
    } else if (e->type() == QEvent::KeyRelease) {
        if ((o == this) && (Qt::ControlModifier == QApplication::keyboardModifiers()))
            is_link_to_tab = false;
    }
    return QObject::eventFilter(o, e);
}
