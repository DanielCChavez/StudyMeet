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
	DatabaseHandler *db = DatabaseHandler::get_instance();
	ErrorHandler *err = ErrorHandler::get_instance();
	AccountSingleton *acc_singleton = AccountSingleton::get_instance();
	QString username = usernameEdit->text();
	QString password = passwordEdit->text();
	int response = 0;

	response = db->validate_account(username.toStdString(), password.toStdString());
	acc_singleton->set_account(db->get_account(username.toStdString(), password.toStdString()));

	if (response == 0)
	{
		err->display_error("validated account!");
		close();
	}
	else
	{
		err->display_error("cannot validate");
	}

}