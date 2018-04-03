#include "createaccountwindow.h"
#include <ctime>
#include "ErrorHandler.h"
#include "Account.h"
#include "DatabaseHandler.h"

using namespace std;


CreateAccountWindow::CreateAccountWindow(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

CreateAccountWindow::~CreateAccountWindow()
{

}


void CreateAccountWindow::on_createAccountButton_clicked()
{
	string username, password, confirmPassword, firstName, lastName, gradeLevel;
	time_t now;
	char *dt;
	ErrorHandler *er;
	DatabaseHandler *db;
	int id;

	er = ErrorHandler::get_instance();
	db = DatabaseHandler::get_instance();
	now = time(0);
	dt = ctime(&now);
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
		return;
	}

	srand(time(NULL));
	id = rand() % 10000;
	while (db->validate_account(id) == 0)
	{
		id = rand() % 10000;
	}

	Account account(username, password, firstName, lastName, dt,  gradeLevel, " ", id);
	if(db->add_to_database(account) == 0)
		close();
	return;
}
