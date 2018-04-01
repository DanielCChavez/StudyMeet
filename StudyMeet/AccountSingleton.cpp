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