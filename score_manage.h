#ifndef SCORE_MANAGE_H
#define SCORE_MANAGE_H

#include <QMainWindow>
#include <QString>
#include <QtDebug>
#include <QMouseEvent>
#include <dialog_change_done.h>
namespace Ui {
class score_manage;
}

class score_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit score_manage(QWidget *parent = nullptr);
    ~score_manage();
    void send_signal();
    void setAreaMovable(const QRect rt);
    QString gradeRead;
    Ui::score_manage *ui;
    QString score_change_read;
private slots:
    void on_loadin_button_clicked();

    void on_writein_button_clicked();

    void on_back_button_clicked();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
private:


    dialog_change_done *dialog=new dialog_change_done;
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置

signals:
    void mySignal();
};

#endif // SCORE_MANAGE_H
