#include "login.h"
#include "createaccountwindow.h"
#include "viewsessions.h"

Login* Login::instance = 0;

Login::Login(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	
	statusLabel->setText("Connecting to database...");
	db = DatabaseHandler::get_instance();
	if (db->get_connection_status() != 0) 
	{ 
		statusLabel->setText("Failed to connect to database"); 
		statusLabel->setStyleSheet("QLabel{color:red;}");
	}
	if (db->get_connection_status() == 0) 
	{
		statusLabel->setText("Connected"); 
		statusLabel->setStyleSheet("QLabel{color:green;}");
	}
	er = ErrorHandler::get_instance();
	ac = AccountSingleton::get_instance();


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
	QString username, password;
	int response;

	username = usernameEdit->text();
	password = passwordEdit->text();

	response = 0;
	response = db->validate_account(username.toStdString(), password.toStdString());
	ac->set_account(username.toStdString(), password.toStdString());
	
	ViewSessions *vs = ViewSessions::Instance();

	if (response == 0) {close(); vs->show();
	}
	if (response == 1) { er->display_error("Error with database"); return; }
	if (response == 2) { er->display_error("Wrong username or password"); return; }

}