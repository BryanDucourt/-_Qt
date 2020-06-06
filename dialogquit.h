#ifndef DIALOGQUIT_H
#define DIALOGQUIT_H

#include <QDialog>

namespace Ui {
class DialogQuit;
}

class DialogQuit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogQuit(QWidget *parent = nullptr);
    ~DialogQuit();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogQuit *ui;
};

#endif // DIALOGQUIT_H
