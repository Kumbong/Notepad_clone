#ifndef REPLACEDIALOG_H
#define REPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class replaceDialog;
}

class replaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit replaceDialog(QWidget *parent = 0);
    void getDialogOutput(bool &caseSensitve,QString &searchString, QString &replaceString);
    ~replaceDialog();

private:
    Ui::replaceDialog *ui;
private slots:
    void text_changed();
};

#endif // REPLACEDIALOG_H
