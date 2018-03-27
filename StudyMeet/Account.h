#pragma once

#include <string>
#include "DatabaseHandler.h"

using namespace std;

class Account
{
private:
	string username;
	string password;
	string firstName;
	string lastName;
	string dateCreated;
	string gradeLevel;
	string sessionID;
	int accountID;

public:
	Account();
	Account(string name, string pword);
	string get_username();
	string get_password();
	void createAccount(string name, string pword);
	void send_account_to_database(Account account);
	string get_sessionID();
	int get_accountID();
	~Account();
	

};