#ifndef QUERYWINDOW_H
#define QUERYWINDOW_H
#include <QMainWindow>
#include <QString>
#include <QtDebug>
#include <QMouseEvent>
namespace Ui {
class queryWindow;
}

class queryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit queryWindow(QWidget *parent = nullptr);
    ~queryWindow();
    bool isOpened=0;
    void sendSignal();
    Ui::queryWindow *ui;
    QString userName;
    QString gradeRead;
    int id;
    void setAreaMovable(const QRect rt);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);

private slots:
    void on_student_button_clicked();

    void on_back_button_clicked();

    void on_teacher_button_clicked();

private:
    QRect m_areaMovable;//可移动窗口的区域，鼠标只有在该区域按下才能移动窗口
    bool m_bPressed;//鼠标按下标志（不分左右键）
    QPoint m_ptPress;//鼠标按下的初始位置

signals:
    void mySignal();
};

#endif // QUERYWINDOW_H
