/********************************************************************************
** Form generated from reading UI file 'gotolinedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOLINEDIALOG_H
#define UI_GOTOLINEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_goToLineDialog
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *goToButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *goToLineDialog)
    {
        if (goToLineDialog->objectName().isEmpty())
            goToLineDialog->setObjectName(QStringLiteral("goToLineDialog"));
        goToLineDialog->resize(280, 96);
        lineEdit = new QLineEdit(goToLineDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 30, 261, 20));
        label = new QLabel(goToLineDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        widget = new QWidget(goToLineDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(110, 60, 158, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        goToButton = new QPushButton(widget);
        goToButton->setObjectName(QStringLiteral("goToButton"));

        horizontalLayout->addWidget(goToButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(goToLineDialog);
        QObject::connect(goToButton, SIGNAL(clicked()), goToLineDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), goToLineDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(goToLineDialog);
    } // setupUi

    void retranslateUi(QDialog *goToLineDialog)
    {
        goToLineDialog->setWindowTitle(QApplication::translate("goToLineDialog", "Go To Line", Q_NULLPTR));
        label->setText(QApplication::translate("goToLineDialog", "&Line Number:", Q_NULLPTR));
        goToButton->setText(QApplication::translate("goToLineDialog", "Go To", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("goToLineDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class goToLineDialog: public Ui_goToLineDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOLINEDIALOG_H
