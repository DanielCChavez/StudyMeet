#include "createaccountwindow.h"
#include <ctime>
#include "Account.h"

using namespace std;

CreateAccountWindow* CreateAccountWindow::instance = NULL;

CreateAccountWindow::CreateAccountWindow(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	er = ErrorHandler::get_instance();
	db = DatabaseHandler::get_instance();
}

CreateAccountWindow* CreateAccountWindow::get_instance()
{
	if (instance == NULL)
		instance = new CreateAccountWindow();

	instance->clear_fields();

	return instance;
}

CreateAccountWindow::~CreateAccountWindow()
{

}

void CreateAccountWindow::clear_fields()
{
	usernameEdit->clear();
	passwordEdit->clear();
	confirmpasswordEdit->clear();
	firstNameEdit->clear();
	lastNameEdit->clear();
	gradeLevelEdit->clear();
	// Move cursor back to 'username' field
	QTimer::singleShot(0, usernameEdit, SLOT(setFocus()));
}

void CreateAccountWindow::on_createAccountButton_clicked()
{
	string username, password, confirmPassword, firstName, lastName, gradeLevel;
	time_t now;
	char *dt;
	int id;
	int result;

	now = time(0);
	dt = ctime(&now);
	
	// Grab GUI text fields
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

	result = db->validate_account(username);
	if (result == 0)
	{
		er->display_error("Username already exists");
		return;
	}

	// Creating an ID
	srand(time(NULL));
	id = rand() % 10000;
	
	result = db->validate_account(id);
	while (result == 0)
	{
		id = rand() % 10000;
		result = db->validate_account(id);
	}
	
	Account account(username, password, firstName, lastName, dt,  gradeLevel, "", id);
	
	result = db->add_to_database(account);
	if (result == 1)
	{
		er->display_error("Error creating account.");
	}
	else if (result == 0)
	{
		close();
	}
	
	return;
}
