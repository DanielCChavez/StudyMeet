#include "AccountSingleton.h"


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

void AccountSingleton::set_account(Account acc)
{
	logged_in = acc;
}

void AccountSingleton::set_sessionID(std::string id)
{
	logged_in.set_sessionID(id);
}


// Returns 0 if not in session
// returns 1 otherwise
int AccountSingleton::is_in_session()
{
	if (logged_in.get_sessionID() == "")
		return 0;

	return 1;
}