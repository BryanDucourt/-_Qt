#include "loginwindow.h"
#include "ui_loginwindow.h"
void LoginWindow::dealSelfSlot()
{
    querywindow->close();
    this->show();
}

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    m_areaMovable.setRect(0,0,this->width(),30);
    connect(querywindow,SIGNAL(mySignal()),this,SLOT(dealSelfSlot()));
    connect(account_manage_window,SIGNAL(mySignal()),this,SLOT(dealSelfSlot_1()));
    if (id==0)
        ui->pushButton_4->hide();

}
void LoginWindow::dealSelfSlot_1()
{
    account_manage_window->close();
    this->show();
}
void LoginWindow::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
  qDebug() << pos() << e->pos() << m_ptPress;
  m_bPressed = m_areaMovable.contains(m_ptPress);
  }
}

void LoginWindow::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
  qDebug() << pos() << e->pos() << m_ptPress;
  move(pos() + e->pos() - m_ptPress);
  }
}

void LoginWindow::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void LoginWindow::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
  m_areaMovable = rt;
  }
}
LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_close_button_clicked()
{
    dialogquit->show();

}

void LoginWindow::on_pushButton_clicked()
{

    this->hide();
    querywindow->id=id;
    querywindow->userName=userName;
    querywindow->show();



}


void LoginWindow::on_pushButton_3_clicked()
{
    this->hide();
    account_manage_window->passWord=passWord;
    account_manage_window->userProfile=userProfile;
    account_manage_window->show();
}
