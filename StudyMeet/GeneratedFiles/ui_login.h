/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *createAccount;
    QPushButton *loginButton;
    QPushButton *forgotPassword;
    QGraphicsView *appLogo;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *emailEntry;
    QLineEdit *passwordEntry;
    QLabel *emailLabel;
    QLabel *passwordLabel;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(647, 339);
        createAccount = new QPushButton(Login);
        createAccount->setObjectName(QStringLiteral("createAccount"));
        createAccount->setGeometry(QRect(150, 270, 93, 28));
        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(370, 270, 93, 28));
        forgotPassword = new QPushButton(Login);
        forgotPassword->setObjectName(QStringLiteral("forgotPassword"));
        forgotPassword->setGeometry(QRect(250, 230, 111, 28));
        appLogo = new QGraphicsView(Login);
        appLogo->setObjectName(QStringLiteral("appLogo"));
        appLogo->setGeometry(QRect(155, 10, 301, 141));
        widget = new QWidget(Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 160, 311, 53));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        emailEntry = new QLineEdit(widget);
        emailEntry->setObjectName(QStringLiteral("emailEntry"));

        gridLayout->addWidget(emailEntry, 0, 1, 1, 1);

        passwordEntry = new QLineEdit(widget);
        passwordEntry->setObjectName(QStringLiteral("passwordEntry"));

        gridLayout->addWidget(passwordEntry, 1, 1, 1, 1);

        emailLabel = new QLabel(widget);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        gridLayout->addWidget(emailLabel, 0, 0, 1, 1);

        passwordLabel = new QLabel(widget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));

        gridLayout->addWidget(passwordLabel, 1, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        createAccount->setText(QApplication::translate("Login", "Create Account", 0));
        loginButton->setText(QApplication::translate("Login", "Login", 0));
        forgotPassword->setText(QApplication::translate("Login", "Forgot Password?", 0));
        emailLabel->setText(QApplication::translate("Login", "Email:", 0));
        passwordLabel->setText(QApplication::translate("Login", "Password:", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
