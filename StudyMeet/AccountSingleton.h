#pragma once

#include "Account.h"


class AccountSingleton : public Account
{
public:
	~AccountSingleton();
	static AccountSingleton* get_instance();
	Account get_account() const { return logged_in; }
	void set_account(Account);
	void set_sessionID(std::string);
	std::string get_sessionID() { return logged_in.get_sessionID(); }
	int is_in_session();
private:
	AccountSingleton();
	Account logged_in;
protected:
	static AccountSingleton* instance;

};

