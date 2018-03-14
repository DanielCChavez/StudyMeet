#pragma once

#include "Account.h"
#include <list>

class Session
{

private:
	string sessionID;
	string hostName;
	string timeStart; 
	int numberOfPeople;
	string timeEnd;
	string subject;
	string location; 
	int totalNumberOfPeople;
	list<Account> listOfPeople;
	string description;

public:
	Session();
	~Session();

	string get_sessionID();
	string get_hostname();
	string get_timestart();
	int get_numberofpeople();
	string get_timeend();
	string get_subject();
	string get_location();
	int get_totalnumberofpeople();
	list<Account> get_listofpeople();
	string get_description();

};

