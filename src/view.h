#ifndef VIEW_H
#define VIEW_H

#include "webpage.h"
#include "layer.h"
#include "ui.h"

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
    bool update_layer_url;
    Ui::View *ui;
    WebPage webpage;
};

#endif // VIEW_H
