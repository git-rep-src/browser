#include "minipagebutton.h"

MiniPageButton::MiniPageButton(QWidget *parent) : QWidget(parent)
{
}

MiniPageButton::~MiniPageButton()
{
}

void MiniPageButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        emit clicked();
}
