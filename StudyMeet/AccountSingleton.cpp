#include "AccountSingleton.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h"



AccountSingleton* AccountSingleton::instance = 0;

AccountSingleton::AccountSingleton()
{

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
	db->log_on(this);
}

void AccountSingleton::set_sessionID(std::string id)
{
	logged_in.set_sessionID(id);
}


// Returns 0 if not in session
// returns 1 otherwise
int AccountSingleton::is_in_session()
{
	if (get_sessionID() == "")
		return 0;

	return 1;
}

int AccountSingleton::log_off()
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->log_off(this);
	return 0;
}