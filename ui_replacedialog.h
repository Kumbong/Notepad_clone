/********************************************************************************
** Form generated from reading UI file 'replacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEDIALOG_H
#define UI_REPLACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replaceDialog
{
public:
    QCheckBox *checkBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *findNextButton;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;
    QPushButton *cancelButton;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *findLineEdit;
    QLabel *label_2;
    QLineEdit *replaceLineEdit;

    void setupUi(QDialog *replaceDialog)
    {
        if (replaceDialog->objectName().isEmpty())
            replaceDialog->setObjectName(QStringLiteral("replaceDialog"));
        replaceDialog->resize(388, 142);
        checkBox = new QCheckBox(replaceDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(30, 100, 91, 17));
        widget = new QWidget(replaceDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(300, 10, 77, 112));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        findNextButton = new QPushButton(widget);
        findNextButton->setObjectName(QStringLiteral("findNextButton"));

        verticalLayout->addWidget(findNextButton);

        replaceButton = new QPushButton(widget);
        replaceButton->setObjectName(QStringLiteral("replaceButton"));

        verticalLayout->addWidget(replaceButton);

        replaceAllButton = new QPushButton(widget);
        replaceAllButton->setObjectName(QStringLiteral("replaceAllButton"));

        verticalLayout->addWidget(replaceAllButton);

        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);

        widget1 = new QWidget(replaceDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 7, 271, 61));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        findLineEdit = new QLineEdit(widget1);
        findLineEdit->setObjectName(QStringLiteral("findLineEdit"));

        gridLayout->addWidget(findLineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        replaceLineEdit = new QLineEdit(widget1);
        replaceLineEdit->setObjectName(QStringLiteral("replaceLineEdit"));

        gridLayout->addWidget(replaceLineEdit, 1, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(findLineEdit);
        label_2->setBuddy(replaceLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(replaceDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), replaceDialog, SLOT(close()));
        QObject::connect(findNextButton, SIGNAL(clicked()), replaceDialog, SLOT(accept()));
        QObject::connect(replaceButton, SIGNAL(clicked()), replaceDialog, SLOT(accept()));
        QObject::connect(replaceAllButton, SIGNAL(clicked()), replaceDialog, SLOT(accept()));

        replaceAllButton->setDefault(false);
        cancelButton->setDefault(true);


        QMetaObject::connectSlotsByName(replaceDialog);
    } // setupUi

    void retranslateUi(QDialog *replaceDialog)
    {
        replaceDialog->setWindowTitle(QApplication::translate("replaceDialog", "Replace", Q_NULLPTR));
        checkBox->setText(QApplication::translate("replaceDialog", "Match &case", Q_NULLPTR));
        findNextButton->setText(QApplication::translate("replaceDialog", "&Find Next", Q_NULLPTR));
        replaceButton->setText(QApplication::translate("replaceDialog", "&Replace", Q_NULLPTR));
        replaceAllButton->setText(QApplication::translate("replaceDialog", "Replace &All", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("replaceDialog", "Cancel", Q_NULLPTR));
        label->setText(QApplication::translate("replaceDialog", "Fi&nd What:", Q_NULLPTR));
        label_2->setText(QApplication::translate("replaceDialog", "Re&place with:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class replaceDialog: public Ui_replaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEDIALOG_H
