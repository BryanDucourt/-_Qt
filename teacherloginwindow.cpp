#include "teacherloginwindow.h"
#include "ui_teacherloginwindow.h"

teacherLoginWindow::teacherLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacherLoginWindow)
{
    ui->setupUi(this);
}

teacherLoginWindow::~teacherLoginWindow()
{
    delete ui;
}
