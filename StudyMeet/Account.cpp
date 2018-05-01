#include "Account.h"
#include "DatabaseHandler.h"

Account::Account()
{
	username = "DEFAULTUSERNAME";
	password = "DEFAULTPASSWORD";
	firstName = "DEFAULTFIRSTNAME";
	lastName = "DEFAULTLASTNAME";
	dateCreated = "DEFAULTDATECREATED";
	gradeLevel = "DEFAULTGRADELEVEL";
	sessionID = "DEFAULTSESSIONID";
	accountID = 0;
}

Account::Account(string name, string pword, string fname, 
	string lname, string dCreated, string glevel, string sessID, int accID)
{
	username = name;
	password = pword;
	firstName = fname;
	lastName = lname;
	dateCreated = dCreated;
	gradeLevel = glevel;
	sessionID = "";
	accountID = accID;
}

string Account::get_username()
{
	return username;
}

string Account::get_password()
{
	return password;
}

string Account::get_firstName()
{
	return firstName;
}

string Account::get_lastName()
{
	return lastName;
}

string Account::get_dateCreated()
{
	return dateCreated;
}

string Account::get_gradeLevel()
{
	return gradeLevel;
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

void Account::send_account_to_database(Account account)
{
	DatabaseHandler* handler = DatabaseHandler::get_instance();
	handler->add_to_database(account);
}

string Account::get_fullName()
{
	return firstName + " " + lastName;
}

void Account::set_sessionID(string id)
{
	sessionID = id;
}