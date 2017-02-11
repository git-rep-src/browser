#include "layer.h"

Layer::Layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Layer)
{
    ui->setupUi(this);

    connect(ui->url_textedit, SIGNAL(textChanged()), this, SLOT(resize_url()));
    connect(ui->url_textedit->document(), SIGNAL(contentsChange(int, int, int)),
            this, SLOT(cleanup_color_url(int , int, int)));
}

Layer::~Layer()
{
    delete ui;
}

void Layer::set_url(QUrl &url)
{
    if (url.scheme() == "http")
        ui->ssl_label->setPixmap(ui->no_ssl_pixmap);
    else
        ui->ssl_label->setPixmap(ui->ssl_pixmap);

    QString host = url.host();
    host.replace("www.", "", Qt::CaseInsensitive);
    ui->url_textedit->setHtml("<font color=\"white\">"+host+"</font>"+"<font color=\"gray\">"+url.path()+url.fragment()+"</font>");
    ui->url_textedit->setAlignment(Qt::AlignCenter);
    ui->url_textedit->moveCursor(QTextCursor::End);
}

void Layer::set_visible(QWidget *w_browser)
{
    if (this->isHidden()) {
        this->setParent(NULL);
        this->setParent(w_browser);
        this->setVisible(true);
        ui->url_textedit->verticalScrollBar()->setValue(3);
        ui->url_textedit->setFocus();
    } else {
        this->setHidden(true);
        w_browser->setFocus();
    }
}

void Layer::cleanup_color_url(int p, int cr, int ca)
{
    Q_UNUSED(p);
    if (cr > 1 && ca == 1) {
        ui->url_textedit->selectAll();
        ui->url_textedit->setTextColor(QColor(255, 255, 255));
        ui->url_textedit->moveCursor(QTextCursor::End);
        ui->url_textedit->document()->setTextWidth(399);
    }
}

void Layer::resize_url()
{
    if ((ui->url_textedit->document()->size().width()) > 400)
        if (ui->url_textedit->document()->toPlainText().simplified().isEmpty())
            ui->url_textedit->setMinimumWidth(500);
        else
            ui->url_textedit->setMinimumWidth(ui->url_textedit->document()->idealWidth() + 100);
    else
        ui->url_textedit->setMinimumWidth(500);
}
