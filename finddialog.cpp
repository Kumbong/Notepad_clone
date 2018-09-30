#include "finddialog.h"
#include "ui_finddialog.h"

findDialog::findDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findDialog)
{
    ui->setupUi(this);
    ui->findNextButton->setEnabled(false);
    ui->downRadioButton->setChecked(true);

    connect(ui->lineEdit,&QLineEdit::textChanged,this,&findDialog::on_lineEdit_text_changed);
}

findDialog::~findDialog()
{
    delete ui;
}
void findDialog::on_lineEdit_text_changed(){

    if(!ui->lineEdit->text().isEmpty())
      ui->findNextButton->setEnabled(true);
    else
       ui->findNextButton->setEnabled(false);
}

void findDialog::getDialogOutput(bool &caseSensitve, findDialog::Direction &searchDirection, QString &searchString)
{
    caseSensitve = ui->caseCheckBox->isChecked();
    searchDirection = ui->downRadioButton->isChecked()? Down: Up;
    searchString = ui->lineEdit->text();
}
