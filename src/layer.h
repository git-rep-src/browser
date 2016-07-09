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
    void set_url(QUrl &url);
    void set_visible(QWidget *w_browser);

    Ui::Layer *get_ui() { return ui; }

private:
    Ui::Layer *ui;

private slots:
    void cleanup_color_url(int p, int cr, int ca);
    void resize_url();
};

#endif // LAYER_H
