#include "AccountSingleton.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h" //delete me

AccountSingleton* AccountSingleton::instance = 0;

AccountSingleton::AccountSingleton()
{
	//DatabaseHandler *db = DatabaseHandler:;get_instance();
	//logged_in = db->get_account();
}


AccountSingleton::~AccountSingleton()
{
}

AccountSingleton* AccountSingleton::get_instance()
{
	if (instance == 0)
		instance = new AccountSingleton();
	return instance;
}

void AccountSingleton::set_account(std::string uname, std::string pword)
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->get_account(uname, pword, logged_in);
}

void AccountSingleton::set_sessionID(std::string id)
{
	ErrorHandler *er = ErrorHandler::get_instance();

	er->display_error("Setting account " + QString::fromStdString(logged_in.get_firstName()) +
		" sessionID to: " + QString::fromStdString(id));
	logged_in.set_sessionID(id);
}


// Returns 0 if not in session
// returns 1 otherwise
int AccountSingleton::is_in_session()
{
	ErrorHandler *er = ErrorHandler::get_instance();
	er->display_error("Result of get_sessionID(): " +
		QString::fromStdString(logged_in.get_sessionID()));

	if (logged_in.get_sessionID() == "")
		return 0;

	return 1;
}