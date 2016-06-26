#include "layer.h"

Layer::Layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Layer)
{
    ui->setupUi(this);
    connect(ui->text_url, SIGNAL(textChanged()), this, SLOT(resize_text_url()));
}

Layer::~Layer()
{
    delete ui;
}

void Layer::set_url(QUrl &url)
{
    if (url.scheme() == "http")
        ui->label_ssl->setPixmap(ui->pixmap_ssl_off);
    else
        ui->label_ssl->setPixmap(ui->pixmap_ssl);

    QString host = url.host();
    host.replace("www.", "", Qt::CaseInsensitive);
    ui->text_url->setText("<font color=\"white\">"+host+"</font>"+"<font color=\"gray\">"+url.path()+url.fragment()+"</font>");
    ui->text_url->setAlignment(Qt::AlignCenter);
    ui->text_url->moveCursor(QTextCursor::End);
}

void Layer::set_visible(QWidget *widget_browser)
{
    if (this->isHidden()) {
        this->setParent(NULL);
        this->setParent(widget_browser);
        this->setVisible(true);
        ui->text_url->setFocus();
    } else {
        this->setHidden(true);
        widget_browser->setFocus();
    }
}

void Layer::resize_text_url()
{
    if ((ui->text_url->document()->size().width()) > 400)
        if (ui->text_url->document()->toPlainText().simplified().isEmpty())
            ui->text_url->setMinimumWidth(500);
        else
            ui->text_url->setMinimumWidth(ui->text_url->document()->idealWidth() + 100);
    else
        ui->text_url->setMinimumWidth(500);
}
