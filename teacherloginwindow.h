#ifndef TEACHERLOGINWINDOW_H
#define TEACHERLOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class teacherLoginWindow;
}

class teacherLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacherLoginWindow(QWidget *parent = nullptr);
    ~teacherLoginWindow();

private:
    Ui::teacherLoginWindow *ui;
};

#endif // TEACHERLOGINWINDOW_H
