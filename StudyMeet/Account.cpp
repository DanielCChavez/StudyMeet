#include "Account.h"


Account::Account()
{
	username = password = " ";
}

Account::Account(string name, string pword)
{
	username = name;
	password = pword;
}

string Account::get_username()
{
	return username;
}

string Account::get_password()
{
	return password;
}

int Account::isUsernameAvailable(string name)
{
	//check DB for username I assume
	return 0;
}

void Account::createAccount(string name, string pword)
{
	username = name;
	password = pword;
}


Account::~Account()
{
}

