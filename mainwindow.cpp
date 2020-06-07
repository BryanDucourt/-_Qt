#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    QFile fileRead("E:\\Qt workshop\\homework\\userProfile.txt");
    if (!fileRead.exists())
        ui->label_3->setText("文件不存在");
    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text))
        ui->label_3->setText("打开文件失败");
    QTextStream readStream(&fileRead);
    readStream.setCodec("UTF-8");
    while(!readStream.atEnd())
    {
        QString temp=readStream.readLine();
        userProfile+=temp;

    }
    fileRead.close();
    ui->input2->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString temp1,temp2,idChoose;
    account=ui->idInput->text();
    passWord=ui->input2->text();
    temp1=account+" "+passWord;
    if(userProfile.indexOf(account)!=-1)
       {
            int n=userProfile.indexOf(account);
            temp2=userProfile.mid(n,temp1.size());
            idChoose=userProfile.mid(n-1,1);
            if(temp2==temp1 && idChoose==identity)
            {
                int id=identity.toInt();
                this->hide();
                loginwindow->id=id;
                loginwindow->userName=account;
                loginwindow->passWord=passWord;
                loginwindow->userProfile=userProfile;
                loginwindow->show();
            }
            else
            {
                ui->label_3->setText("用户名或密码错误！");
            }
       }
     else
        {
            ui->label_3->setText("用户名或密码错误！");
        }
}

void MainWindow::on_radioButton_2_clicked()
{
    identity="0";
}

void MainWindow::on_radioButton_clicked()
{
    identity="1";
}
