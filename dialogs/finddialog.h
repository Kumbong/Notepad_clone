#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class findDialog;
}

class findDialog : public QDialog
{
    Q_OBJECT


public:
    enum Direction {Up, Down};
    explicit findDialog(QWidget *parent = 0);
    void getDialogOutput(bool &caseSensitve, findDialog::Direction &searchDirection, QString &searchString);
    ~findDialog();
private slots:
    void on_lineEdit_text_changed();

private:
    Ui::findDialog *ui;

};

#endif // FINDDIALOG_H
