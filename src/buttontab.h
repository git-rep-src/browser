#ifndef BUTTONTAB_H
#define BUTTONTAB_H

#include <QWidget>
#include <QMouseEvent>

class ButtonTab : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonTab(QWidget *parent = 0);
    ~ButtonTab();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // BUTTONTAB_H
