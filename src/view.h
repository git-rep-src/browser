#ifndef VIEW_H
#define VIEW_H

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

public slots:
    void load_url(QUrl &url);
    Ui::View *get_ui() { return ui; }

private:
    Ui::View *ui;
};

#endif // VIEW_H
