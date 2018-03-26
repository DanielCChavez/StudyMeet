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

void Account::createAccount(string name, string pword)
{
	username = name;
	password = pword;
}

string Account::get_sessionID()
{
	return sessionID;
}

int Account::get_accountID()
{
	return accountID;
}


Account::~Account()
{

}

