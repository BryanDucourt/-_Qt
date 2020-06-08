#include "dialog_change_done.h"
#include "ui_dialog_change_done.h"

dialog_change_done::dialog_change_done(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_change_done)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
}

dialog_change_done::~dialog_change_done()
{
    delete ui;
}

void dialog_change_done::on_pushButton_clicked()
{
    this->close();
}
