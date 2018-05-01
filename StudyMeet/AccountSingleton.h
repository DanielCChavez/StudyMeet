#pragma once

#include "Account.h"



class AccountSingleton : public Account
{
public:
	~AccountSingleton();
	static AccountSingleton* get_instance();
	void set_account(std::string, std::string);
	void set_sessionID(std::string);
	int get_accountID() { return logged_in.get_accountID(); }
	std::string get_fullname() { return logged_in.get_fullName(); }
	std::string get_sessionID() { return logged_in.get_sessionID(); }
	int is_in_session();
	int log_off();
private:
	AccountSingleton();
	Account logged_in;
protected:
	static AccountSingleton* instance;

};

