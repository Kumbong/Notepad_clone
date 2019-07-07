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

    connect(ui->findLineEdit,&QLineEdit::textChanged,this,&replaceDialog::text_changed);
    connect(ui->replaceLineEdit,&QLineEdit::textChanged,this,&replaceDialog::text_changed);
}

replaceDialog::~replaceDialog()
{
    delete ui;
}
void replaceDialog::text_changed(){

    //enable find button
    if(!ui->findLineEdit->text().isEmpty())
      ui->findNextButton->setEnabled(true);
    else
       ui->findNextButton->setEnabled(false);

    //enable replace and replace all button
    if(!ui->replaceLineEdit->text().isEmpty()){
      ui->replaceButton->setEnabled(true);
      ui->replaceAllButton->setEnabled(true);
    }
    else{
       ui->replaceButton->setEnabled(false);
       ui->replaceAllButton->setEnabled(false);
    }
}
void replaceDialog::getDialogOutput(bool &caseSensitve,QString &searchString,QString &replaceString)
{
    caseSensitve = ui->caseCheckBox->isChecked();
    searchString = ui->findLineEdit->text();
    replaceString = ui->replaceLineEdit->text();
}
