#ifndef VIEW_H
#define VIEW_H

#include "ui.h"
#include "layer.h"

#include <QWebEngineView>

namespace Ui {
class View;
}

class View : public QWebEngineView
{
    Q_OBJECT

public:
    explicit View(Ui::Browser *ui_browser, Layer *layer, QWebEngineView *parent = 0);
    ~View();

signals:
    void link_clicked(QUrl url);

public slots:
    void load_url(QUrl &url, bool update = true);
    Ui::View *get_ui() { return ui; }

private:
    Ui::View *ui;
    
    bool update_layer_url;
};

#endif // VIEW_H
