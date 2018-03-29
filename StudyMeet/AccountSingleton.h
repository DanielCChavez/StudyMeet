#pragma once

#include "Account.h"

class AccountSingleton : public Account
{
public:
	static AccountSingleton* get_instance();
	~AccountSingleton();
private:
	AccountSingleton();
protected:
	static AccountSingleton* instance;

};

