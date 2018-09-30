/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findDialog
{
public:
    QGroupBox *directionGroupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *upRadioButton;
    QRadioButton *downRadioButton;
    QCheckBox *caseCheckBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QPushButton *findNextButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *findDialog)
    {
        if (findDialog->objectName().isEmpty())
            findDialog->setObjectName(QStringLiteral("findDialog"));
        findDialog->resize(350, 99);
        directionGroupBox = new QGroupBox(findDialog);
        directionGroupBox->setObjectName(QStringLiteral("directionGroupBox"));
        directionGroupBox->setGeometry(QRect(120, 40, 131, 51));
        widget = new QWidget(directionGroupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(18, 18, 94, 21));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        upRadioButton = new QRadioButton(widget);
        upRadioButton->setObjectName(QStringLiteral("upRadioButton"));

        horizontalLayout_2->addWidget(upRadioButton);

        downRadioButton = new QRadioButton(widget);
        downRadioButton->setObjectName(QStringLiteral("downRadioButton"));

        horizontalLayout_2->addWidget(downRadioButton);

        caseCheckBox = new QCheckBox(findDialog);
        caseCheckBox->setObjectName(QStringLiteral("caseCheckBox"));
        caseCheckBox->setGeometry(QRect(10, 70, 81, 17));
        widget1 = new QWidget(findDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 10, 241, 22));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget1);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        widget2 = new QWidget(findDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(260, 10, 77, 54));
        verticalLayout = new QVBoxLayout(widget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        findNextButton = new QPushButton(widget2);
        findNextButton->setObjectName(QStringLiteral("findNextButton"));

        verticalLayout->addWidget(findNextButton);

        cancelButton = new QPushButton(widget2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        retranslateUi(findDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), findDialog, SLOT(close()));
        QObject::connect(findNextButton, SIGNAL(clicked()), findDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(findDialog);
    } // setupUi

    void retranslateUi(QDialog *findDialog)
    {
        findDialog->setWindowTitle(QApplication::translate("findDialog", "Find", Q_NULLPTR));
        directionGroupBox->setTitle(QApplication::translate("findDialog", "Direction", Q_NULLPTR));
        upRadioButton->setText(QApplication::translate("findDialog", "Up", Q_NULLPTR));
        downRadioButton->setText(QApplication::translate("findDialog", "Down", Q_NULLPTR));
        caseCheckBox->setText(QApplication::translate("findDialog", "Match Case", Q_NULLPTR));
        label->setText(QApplication::translate("findDialog", "Find what:", Q_NULLPTR));
        findNextButton->setText(QApplication::translate("findDialog", "Find Next", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("findDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class findDialog: public Ui_findDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
