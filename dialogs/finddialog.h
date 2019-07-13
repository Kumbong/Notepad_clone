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
    enum Direction {Up, Down};//represents the direction in which the user wants to search
    explicit findDialog(QWidget *parent = 0);
    void getDialogOutput(bool &caseSensitve, findDialog::Direction &searchDirection, QString &searchString);
    ~findDialog();
private slots:
    void text_changed();


private:
    Ui::findDialog *ui;

};

#endif // FINDDIALOG_H
