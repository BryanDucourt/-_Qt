#ifndef ACCOUNT_MANAGE_H
#define ACCOUNT_MANAGE_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <dialog_change_done.h>
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
private slots:
    void on_old_password_editingFinished();

    void on_new_password_cofirm_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::account_manage *ui;
    dialog_change_done *dialog=new dialog_change_done;
signals:
    void mySignal();
};

#endif // ACCOUNT_MANAGE_H
