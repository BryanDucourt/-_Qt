#include "dialogquit.h"
#include "ui_dialogquit.h"

DialogQuit::DialogQuit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogQuit)
{
    ui->setupUi(this);
}

DialogQuit::~DialogQuit()
{
    delete ui;
}

void DialogQuit::on_buttonBox_accepted()
{
    if(ui->buttonBox->button(QDialogButtonBox::Ok))
        QApplication::exit();
    else
        this->close();
}
