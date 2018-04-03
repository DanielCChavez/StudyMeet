#pragma once

#include <string>

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
	Account(string name, string pword, string fname, string lname, string dCreated, string grlevel, string sessID, int accID);
	string get_username();
	string get_password();
	string get_firstName();
	string get_lastName();
	string get_dateCreated();
	string get_gradeLevel();
	void createAccount(string name, string pword);
	void send_account_to_database(Account account);
	string get_sessionID();
	int get_accountID();
	~Account();
	

};