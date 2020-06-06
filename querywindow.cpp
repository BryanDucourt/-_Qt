#include "querywindow.h"
#include "ui_querywindow.h"
#include <QFile>
#include <QTextStream>
queryWindow::queryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::queryWindow)
{
    //connect(ui->back_button,SIGNAL(clicked()),this,SLOT(sendSignal()));
    isOpened=1;
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    m_areaMovable.setRect(0,0,this->width(),30);
    QFile fileRead("E:\\Qt workshop\\homework\\grade.txt");
    if (!fileRead.exists())
        ui->tip->setText("未找到文件！");
    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text))
    ui->tip->setText("打开文件失败");
    QTextStream readStream(&fileRead);
    readStream.setCodec("UTF-8");
    while(!readStream.atEnd())
    {
        QString temp;
        temp=readStream.readLine();
        gradeRead+=temp;
    }
    fileRead.close();
    switch (id)
    {
        case 0:
            ui->teacher_button->hide();
        break;
    }
}

queryWindow::~queryWindow()
{
    delete ui;
}

void queryWindow::on_student_button_clicked()
{
    QString search,temp,locate;
    switch (id)
    {
        case 0:
            ui->search_input->setText(userName);
            ui->search_input->setReadOnly(true);
            ui->tip->setText("只能查询自己的成绩！");
        break;
    }
    search=ui->search_input->text();
    if(gradeRead.indexOf(search)!=-1)
    {
        int j=0;
        int n=gradeRead.indexOf((search)),pos_beg,pos_end;
        pos_beg=gradeRead.lastIndexOf("-",n);
        pos_end=gradeRead.indexOf("-",n);
        temp=gradeRead.mid(pos_beg+1,pos_end-1);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(temp.section(" ",0,0)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(temp.section(" ",1,1)));
        for(int i=1;i<=3;i++)
        {
            locate=" ";
            locate+=QString::number(i);
            locate+=" ";
            pos_beg=temp.indexOf(locate,0);
            pos_end=temp.indexOf(" ",pos_beg+3);
            ui->tableWidget->setItem(0,i+1,new QTableWidgetItem(temp.mid(pos_beg+3,pos_end-pos_beg-3)));
            QString str=temp.mid(pos_beg+3,pos_end-pos_beg-3);
            ;
            j+=str.toInt();

        }
        ui->tableWidget->setItem(0,5,new QTableWidgetItem(QString::number(j/3)));

    }
}

void queryWindow::on_back_button_clicked()
{
    emit mySignal();

    isOpened=0;

}
void queryWindow::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
  qDebug() << pos() << e->pos() << m_ptPress;
  m_bPressed = m_areaMovable.contains(m_ptPress);
  }
}

void queryWindow::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
  qDebug() << pos() << e->pos() << m_ptPress;
  move(pos() + e->pos() - m_ptPress);
  }
}

void queryWindow::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void queryWindow::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
  m_areaMovable = rt;
  }
}

void queryWindow::on_teacher_button_clicked()
{
    QString temp;
    int i=0,j=0;

}