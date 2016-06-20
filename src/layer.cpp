#include "layer.h"

Layer::Layer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Layer)
{
    ui->setupUi(this);
//    connect(ui->lineEditUrl, SIGNAL(textChanged(QString)), this, SLOT(resizeLineEditUrl()));
}

Layer::~Layer()
{
    delete ui;
}

//void Layer::resizeLineEditUrl()
//{
//    QFont f("", 0);
//    QFontMetrics fm(f);
//    int pixelsWide = fm.width(ui->lineEditUrl->text());

//    ui->lineEditUrl->setMinimumWidth(pixelsWide*2.3);

//    this->adjustSize();
//}
