#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "ui_login.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h"
#include "AccountSingleton.h"

class Login : public QWidget, public Ui::Login
{
	Q_OBJECT

public:
	~Login();
	static Login* get_instance();

protected:
	static Login* instance;

private:
	Login(QWidget *parent = 0);
	DatabaseHandler *db;
	ErrorHandler *er;
	AccountSingleton *ac;

public slots:
	void on_loginButton_clicked();
	void on_createAccountButton_clicked();


};

#endif // LOGIN_H
