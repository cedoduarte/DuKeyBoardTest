#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class DuKeyBoard;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void closeEvent(QCloseEvent *e);
private slots:
    void on_tecladoPushButton_clicked();
private:
    Ui::Widget *ui;
    DuKeyBoard *mKeyBoard;
};

#endif // WIDGET_H
