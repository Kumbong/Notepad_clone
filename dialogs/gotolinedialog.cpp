#include "gotolinedialog.h"
#include "ui_gotolinedialog.h"

goToLineDialog::goToLineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::goToLineDialog)
{
    ui->setupUi(this);
    connect(ui->lineEdit,&QLineEdit::textChanged,this,&goToLineDialog::on_lineEdit_text_changed);
}

void goToLineDialog::setLineEditText(int LineNumber)
{
    ui->lineEdit->setText(QString::number(LineNumber));
}

goToLineDialog::~goToLineDialog()
{
    delete ui;
}

void goToLineDialog::on_lineEdit_text_changed()
{
    if(ui->lineEdit->text()==QString())
        ui->goToButton->setEnabled(false);
    else if(!ui->goToButton->isEnabled())
        ui->goToButton->setEnabled(true);
}
