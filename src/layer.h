#ifndef LAYER_H
#define LAYER_H

#include "ui.h"

namespace Ui {
class Layer;
}

class Layer : public QWidget
{
    Q_OBJECT

public:
    explicit Layer(QWidget *parent = 0);
    ~Layer();

public slots:
    Ui::Layer *get_ui_object() { return ui; }

private:
    Ui::Layer *ui;

private slots:
    void resizeLineEditUrl();
};

#endif // LAYER_H
