#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_login.h"

class Login : public QDialog, public Ui::Login
{
	Q_OBJECT

public:
	Login(QWidget *parent = 0);
	~Login();
};

#endif // LOGIN_H
