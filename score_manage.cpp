#include "score_manage.h"
#include "ui_score_manage.h"
#include <QFile>
#include <QTextStream>
score_manage::score_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::score_manage)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    m_areaMovable.setRect(0,0,this->width(),30);
    QFile fileRead("E:\\Qt workshop\\homework\\grade.txt");
    if (!fileRead.exists())
        ui->tip->setText("读取成绩单失败！");
    if(!fileRead.open(QIODevice::ReadOnly | QIODevice::Text))
        ui->tip->setText("打开成绩单失败");
    QTextStream readStream(&fileRead);
    readStream.setCodec("UTF-8");
    while(!readStream.atEnd())
    {
        QString temp;
        temp=readStream.readLine();
        score_change_read+=temp;
    }
    fileRead.close();
}

score_manage::~score_manage()
{
    delete ui;
}

void score_manage::on_loadin_button_clicked()
{
    QString textFind,textSet;
    QStringList temp;
    temp=score_change_read.split("--",QString::SkipEmptyParts);
    int i=0;
    for (i=0;i<temp.size();i++)
    {
        textFind=temp[i];
        int nStart=textFind.indexOf(QRegExp("[\u4e00-\u9fa5]")),nEnd=textFind.indexOf(" ",nStart);
        textSet=textFind.mid(nStart,nEnd-nStart);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(textSet));
        nStart=textFind.indexOf(QRegExp("[0-9]{8,10}"));
        nEnd=textFind.indexOf(" ",nStart);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(textFind.mid(nStart,nEnd-nStart)));
        for(int j=1;j<=3;j++)
        {
            QString locate=" ";
            locate+=QString::number(j);
            locate+=" ";
            nStart=textFind.indexOf(locate,0);
            nEnd=textFind.indexOf(" ",nStart+3);
            ui->tableWidget->setItem(i,j+1,new QTableWidgetItem(textFind.mid(nStart+3,nEnd-nStart-3)));
            QString str=textFind.mid(nStart+3,nEnd-nStart-3);
        }
    }
}

void score_manage::on_writein_button_clicked()
{
    QString text_write,temp;
    int n=ui->tableWidget->rowCount(),j=2;
    text_write+="-";
    for (int i=0;i<n;i++)
    {
        if(ui->tableWidget->item(i,0)!=NULL)
        {
            text_write+="-";
            temp=ui->tableWidget->item(i,0)->text();
            text_write+=temp;
            text_write+=" ";
            temp=ui->tableWidget->item(i,1)->text();
            text_write+=temp;
            text_write+=" ";
            for (j=2;j<5;j++)
            {
                text_write+=QString::number(j-1);
                text_write+=" ";
                temp=ui->tableWidget->item(i,j)->text();
                text_write+=temp;
                text_write+=" ";
            }
            text_write+="-";
        }
        else
            break;
    }
    text_write+="-";
    QFile file_write("E:\\Qt workshop\\homework\\grade.txt");
    file_write.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream writeStream(&file_write);
    writeStream.setCodec("UTF-8");
    writeStream<<text_write;
    file_write.close();
    dialog->show();
}

void score_manage::on_back_button_clicked()
{
    emit mySignal();

}
void score_manage::mousePressEvent(QMouseEvent *e)
{
  //鼠标左键
  if(e->button() == Qt::LeftButton)
  {
  m_ptPress = e->pos();
  qDebug() << pos() << e->pos() << m_ptPress;
  m_bPressed = m_areaMovable.contains(m_ptPress);
  }
}

void score_manage::mouseMoveEvent(QMouseEvent *e)
{
  if(m_bPressed)
  {
  qDebug() << pos() << e->pos() << m_ptPress;
  move(pos() + e->pos() - m_ptPress);
  }
}

void score_manage::mouseReleaseEvent(QMouseEvent *)
{
  m_bPressed = false;
}

//设置鼠标按下的区域
void score_manage::setAreaMovable(const QRect rt)
{
  if(m_areaMovable != rt)
  {
  m_areaMovable = rt;
  }
}
