#include "login.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h"
#include "AccountSingleton.h"
#include "createaccountwindow.h"

Login* Login::instance = 0;

Login::Login(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

void Login::on_createAccountButton_clicked()
{
	CreateAccountWindow *createAccount_window = new CreateAccountWindow();
	createAccount_window->setWindowModality(Qt::WindowModality::ApplicationModal);
	createAccount_window->show();
}

Login::~Login()
{

}

Login* Login::get_instance()
{
	if (instance == NULL)
		instance = new Login();
	return instance;
}

void Login::on_loginButton_clicked()
{
	DatabaseHandler *db;
	ErrorHandler *err;
	AccountSingleton *acc;
	QString username, password;
	int response;

	db = DatabaseHandler::get_instance();
	err = ErrorHandler::get_instance();
	acc = AccountSingleton::get_instance();
	username = usernameEdit->text();
	password = passwordEdit->text();

	response = 0;
	response = db->validate_account(username.toStdString(), password.toStdString());
	acc->set_account(username.toStdString(), password.toStdString());

	
	if (response == 0)
	{
		close();
	}
	else
	{
		err->display_error("cannot validate");
	}

}