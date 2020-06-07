#include "account_manage.h"
#include "ui_account_manage.h"

account_manage::account_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::account_manage)
{
    ui->setupUi(this);
    ui->Wrong1->hide();
    ui->Wrong2->hide();
}

account_manage::~account_manage()
{
    delete ui;
}

void account_manage::on_old_password_editingFinished()
{
    QString passWord_temp=ui->old_password->text();
    if (passWord_temp!=passWord)
    {
        ui->Wrong1->show();
        ui->pushButton->setEnabled(false);
    }
    else
    {
        ui->Wrong1->hide();
        ui->pushButton->setEnabled(true);
    }
}

void account_manage::on_new_password_cofirm_editingFinished()
{
    QString passWord_new_temp=ui->new_password_cofirm->text();
    if (passWord_new_temp!=ui->new_password->text())
    {
        ui->Wrong2->show();
        ui->pushButton->setEnabled(false);
    }
    else
    {
        ui->Wrong1->hide();
        ui->pushButton->setEnabled(true);
    }
}

void account_manage::on_pushButton_clicked()
{
    QString passWord_chenged=ui->new_password_cofirm->text();
    int n=userProfile.indexOf(passWord);
    userProfile.replace(n,passWord_chenged.size(),passWord_chenged);
    QFile change_read("E:\\Qt workshop\\homework\\userProfile.txt");
    change_read.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream writeStream(&change_read);
    writeStream<<userProfile;
    change_read.close();
    dialog->show();
}

void account_manage::on_pushButton_2_clicked()
{
    emit mySignal();

}
