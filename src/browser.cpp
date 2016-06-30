#include "browser.h"

Browser::Browser(QWidget *parent)
    : QWidget(parent)
    , view(NULL)
    , layer(NULL)
    , row(0)
    , col(0)
    , current_view(0)
    , is_link_to_miniature(false)
    , ui(new Ui::Browser)
{
    ui->setupUi(this);

    layer = new Layer(this);
    layer->get_ui()->text_url->installEventFilter(this);

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
        if (is_link_to_miniature)
            create_view(url, true);
        else
            views[current_view]->load_url(url);
    });
    view->load_url(url, !is_link);

    views.push_back(view);
    if (views.size() > 1)
        handler_view((views.size() - 1), false, is_link);

    if (!is_link) {
        ui->layout_main->insertWidget(0, views.back());
        current_view = (views.size() - 1);
    }
}

void Browser::handler_view(int view_to, bool rotate, bool is_link)
{
    int view_to_open;
    int view_to_miniature;

    if (is_link) {
        view_to_open = current_view;
        view_to_miniature = view_to;
    } else {
        view_to_open = view_to;
        view_to_miniature = current_view;
        ui->layout_main->removeWidget(views[view_to_miniature]);
    }

    if ((col == 4) && (!rotate)) {
        col = 0;
        ++row;
    }

    if (rotate) {
        int i = layer->get_ui()->layout_miniatures->indexOf(views[view_to_open]);
        int r, c, rs, cs;
        layer->get_ui()->layout_miniatures->getItemPosition(i, &r, &c, &rs, &cs);
        layer->get_ui()->layout_miniatures->addWidget(views[view_to_miniature], r, c);
    } else {
        layer->get_ui()->layout_miniatures->addWidget(views[view_to_miniature], row, col);
    }
    //views[view_to_miniature]->setMaximumSize(400, 250); // TODO: %
    views[view_to_miniature]->setZoomFactor(0.40);
    views[view_to_miniature]->get_ui()->button_miniature->setParent(views[view_to_miniature]);
    views[view_to_miniature]->get_ui()->button_miniature->show();
    connect(views[view_to_miniature]->get_ui()->button_miniature, &ButtonMiniature::clicked, [=] {
        views[view_to_miniature]->get_ui()->button_miniature->disconnect();
        handler_view(view_to_miniature, true);
    });
    connect(views[view_to_miniature]->get_ui()->button_miniature_close, &QPushButton::released, [=] {
        layer->get_ui()->layout_miniatures->removeWidget(views[view_to_miniature]);
        delete views[view_to_miniature];
        views[view_to_miniature] = NULL;
    });

    if (rotate) {
        layer->get_ui()->layout_miniatures->removeWidget(views[view_to_open]);
        views[view_to_open]->get_ui()->button_miniature->hide();
        views[view_to_open]->get_ui()->button_miniature->setParent(NULL);
        //views[view_to_open]->setMaximumSize(1920, 1080); // TODO: %
        views[view_to_open]->setZoomFactor(1.0);
        ui->layout_main->insertWidget(0, views[view_to_open]);

        QUrl url = views[view_to_open]->url();
        layer->set_url(url);

        current_view = view_to_open;
        layer->set_visible(this);
    }

    ++col;
}

bool Browser::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        QKeyEvent *key = static_cast<QKeyEvent *>(e);
        if (o == this) {
            switch(key->key()) {
                case Qt::Key_Left:
                    views[current_view]->back();
                    break;
                case Qt::Key_Right:
                    views[current_view]->forward();
                    break;
                case Qt::Key_Return:
                    views[current_view]->reload();
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
                is_link_to_miniature = true;
        } else if (o == layer->get_ui()->text_url) {
            switch(key->key()) {
                case Qt::Key_Return:
                    if (!layer->get_ui()->text_url->document()->toPlainText().simplified().isEmpty()) {
                        url.setUrl(layer->get_ui()->text_url->document()->toPlainText().simplified());
                        if ((key->modifiers() == Qt::ShiftModifier) || (view == NULL))
                            create_view(url);
                        else
                            views[current_view]->load_url(url);
                        layer->set_visible(this);
                    }
                    break;
                default:
                    break;
            }
        }
    } else if (e->type() == QEvent::KeyRelease) {
        if ((o == this) && (Qt::ControlModifier == QApplication::keyboardModifiers()))
            is_link_to_miniature = false;
    }
    return QObject::eventFilter(o, e);
}
