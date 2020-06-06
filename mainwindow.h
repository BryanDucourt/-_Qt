#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <loginwindow.h>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <cstdlib>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

private:
    Ui::MainWindow *ui;
    QString userProfile,account,passWord;
    LoginWindow *loginwindow=new LoginWindow;
    QString identity;
};
#endif // MAINWINDOW_H
