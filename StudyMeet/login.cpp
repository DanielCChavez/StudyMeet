#include "login.h"


Login::Login(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

Login::~Login()
{

}

void Login::on_createAccount_clicked()
{
	CreateAccount acc(this);
	acc.exec();
}