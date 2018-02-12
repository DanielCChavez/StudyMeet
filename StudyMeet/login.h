#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"
#include "createaccount.h"

class Login : public QDialog, public Ui::Login
{
	Q_OBJECT

public:
	Login(QWidget *parent = 0);
	~Login();

public slots:
	void on_createAccount_clicked();

};

#endif // LOGIN_H
