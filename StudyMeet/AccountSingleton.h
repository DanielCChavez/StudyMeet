#pragma once

#include "Account.h"

class AccountSingleton : public Account
{
public:
	~AccountSingleton();
	static AccountSingleton* get_instance();
	Account get_account() const { return logged_in; }
	void set_account(Account);
private:
	AccountSingleton();
	Account logged_in;
protected:
	static AccountSingleton* instance;

};

