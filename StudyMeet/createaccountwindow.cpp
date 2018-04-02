#include "createaccountwindow.h"
#include <ctime>
#include "ErrorHandler.h"
#include "Account.h"
#include "DatabaseHandler.h"

using namespace std;

CreateAccountWindow* CreateAccountWindow::instance = NULL;

CreateAccountWindow::CreateAccountWindow(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

CreateAccountWindow::~CreateAccountWindow()
{

}

CreateAccountWindow * CreateAccountWindow::Instance()
{
	if (instance == NULL)
		instance = new CreateAccountWindow();

	return instance;
}

void CreateAccountWindow::on_createAccountButton_clicked()
{
	string username, password, confirmPassword, firstName, lastName, gradeLevel;
	ErrorHandler *er = ErrorHandler::get_instance();
	DatabaseHandler *db = DatabaseHandler::get_instance();

	username = usernameEdit->text().toStdString();
	password = passwordEdit->text().toStdString();
	confirmPassword = confirmpasswordEdit->text().toStdString();
	firstName = firstNameEdit->text().toStdString();
	lastName = lastNameEdit->text().toStdString();
	gradeLevel = gradeLevelEdit->text().toStdString();

	if (password != confirmPassword)
	{
		er->display_error("Passwords do not match");
		return;
	}

	if (db->validate_account(username) == 0)
	{
		er->display_error("Username already exists");
	}

	time_t now = time(0);
	char* dt = ctime(&now);

	srand(time(NULL));
	int number = rand() % 10000;
	while (db->validate_account(number) == 0)
	{
		number = rand() % 10000;
	}


	Account account(username, password, firstName, lastName, dt,  gradeLevel, " ", number);
	db->add_to_database(account);
	//close();
}
