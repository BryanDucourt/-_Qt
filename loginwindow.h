#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H


#include <dialogquit.h>
#include <querywindow.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void setAreaMovable(const QRect rt);
    void mySlot();
    QString userName;
    int id;
private:
    Ui::LoginWindow *ui;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_close_button_clicked();

    void on_pushButton_clicked();
    void dealSelfSlot();

private:
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置
    DialogQuit *dialogquit=new DialogQuit;
    queryWindow *querywindow=new queryWindow;
};

#endif // LOGINWINDOW_H
