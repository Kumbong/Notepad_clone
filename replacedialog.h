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
    ~replaceDialog();

private:
    Ui::replaceDialog *ui;
};

#endif // REPLACEDIALOG_H
