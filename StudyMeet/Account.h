#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;

class Account
{
private:
	string username;
	string password;
	string firstName; //not sure
	string lastName; //how to
	string dateCreated; //collect
	string gradeLevel; //this data
public:
	Account();
	Account(string name, string pword);
	string get_username();
	string get_password();
	int isUsernameAvailable(string name);
	void createAccount(string name, string pword);
	~Account();


};

#endif