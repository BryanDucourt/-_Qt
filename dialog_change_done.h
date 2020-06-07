#ifndef DIALOG_CHANGE_DONE_H
#define DIALOG_CHANGE_DONE_H

#include <QDialog>

namespace Ui {
class dialog_change_done;
}

class dialog_change_done : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_change_done(QWidget *parent = nullptr);
    ~dialog_change_done();

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialog_change_done *ui;
};

#endif // DIALOG_CHANGE_DONE_H
