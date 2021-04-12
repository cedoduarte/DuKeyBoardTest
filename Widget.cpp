#include "Widget.h"
#include "ui_Widget.h"
#include "DuKeyBoard.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mKeyBoard = new DuKeyBoard(false);
}

Widget::~Widget()
{
    delete ui;
    delete mKeyBoard;
}

void Widget::closeEvent(QCloseEvent *e)
{
    mKeyBoard->hide(true);
    QWidget::closeEvent(e);
}

void Widget::on_tecladoPushButton_clicked()
{
    mKeyBoard->show(this);
}
