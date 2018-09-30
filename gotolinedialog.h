#ifndef GOTOLINEDIALOG_H
#define GOTOLINEDIALOG_H

#include <QDialog>

namespace Ui {
class goToLineDialog;
}

class goToLineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit goToLineDialog(QWidget *parent = 0);
    void setLineEditText(int);
    ~goToLineDialog();

private slots:
    void on_lineEdit_text_changed();
private:
    Ui::goToLineDialog *ui;

};

#endif // GOTOLINEDIALOG_H
