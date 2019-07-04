#include "replacedialog.h"
#include "ui_replacedialog.h"

replaceDialog::replaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::replaceDialog)
{
    ui->setupUi(this);
    ui->findNextButton->setEnabled(false);
    ui->replaceButton->setEnabled(false);
    ui->replaceAllButton->setEnabled(false);
}

replaceDialog::~replaceDialog()
{
    delete ui;
}
