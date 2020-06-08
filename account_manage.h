#ifndef ACCOUNT_MANAGE_H
#define ACCOUNT_MANAGE_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <dialog_change_done.h>
#include <QtDebug>
#include <QMouseEvent>
namespace Ui {
class account_manage;
}

class account_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit account_manage(QWidget *parent = nullptr);
    ~account_manage();
    QString passWord;
    QString userProfile;
    void send_signal();
    void setAreaMovable(const QRect rt);
private slots:
    void on_old_password_editingFinished();

    void on_new_password_cofirm_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::account_manage *ui;
    dialog_change_done *dialog=new dialog_change_done;
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
signals:
    void mySignal();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);

};

#endif // ACCOUNT_MANAGE_H
