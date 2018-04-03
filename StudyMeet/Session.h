#pragma once

#include "Account.h"
#include <list>
#include <string>

class Session
{

private:
	string sessionID;
	int hostId;
	string timeStart; 
	int currentNumberOfPeople;
	string timeEnd;
	string subject;
	string location; 
	int maximumCapacityOfPeople;
	list<Account> listOfPeople;
	string description;

public:
	Session();
	Session(string sId, int hId, string tS, int nOP, string tE, string sub, string loc, int tNOP, string desc);
	~Session();
	
	void send_session_to_database(Session session);
	void add_account_to_sessionlist(Account account);
	void remove_account_from_sessionlist(Account account);


	string get_sessionID();
	int get_hostId();
	string get_timestart();
	int get_currentnumberofpeopleinsession();
	string get_timeend();
	string get_subject();
	string get_location();
	int get_maximumcapacityofpeopleinsession();
	list<Account> get_listofpeople();
	string get_description();
	
};

