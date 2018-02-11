/********************************************************************************
** Form generated from reading UI file 'createaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEACCOUNT_H
#define UI_CREATEACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateAccount
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *usernameLabel;
    QLineEdit *emailEdit;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *enterButton;

    void setupUi(QDialog *CreateAccount)
    {
        if (CreateAccount->objectName().isEmpty())
            CreateAccount->setObjectName(QStringLiteral("CreateAccount"));
        CreateAccount->resize(400, 300);
        widget = new QWidget(CreateAccount);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(90, 90, 201, 79));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        usernameLabel = new QLabel(widget);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));

        gridLayout->addWidget(usernameLabel, 0, 0, 1, 1);

        emailEdit = new QLineEdit(widget);
        emailEdit->setObjectName(QStringLiteral("emailEdit"));

        gridLayout->addWidget(emailEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(118, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        enterButton = new QPushButton(widget);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        gridLayout_2->addWidget(enterButton, 1, 1, 1, 1);


        retranslateUi(CreateAccount);

        QMetaObject::connectSlotsByName(CreateAccount);
    } // setupUi

    void retranslateUi(QDialog *CreateAccount)
    {
        CreateAccount->setWindowTitle(QApplication::translate("CreateAccount", "CreateAccount", 0));
        usernameLabel->setText(QApplication::translate("CreateAccount", "Username:", 0));
        label_2->setText(QApplication::translate("CreateAccount", "Password:", 0));
        enterButton->setText(QApplication::translate("CreateAccount", "Enter", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateAccount: public Ui_CreateAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEACCOUNT_H
