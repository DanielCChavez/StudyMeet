#pragma once

#include "Account.h"
#include <list>
#include <string>

class Session
{

private:
	string sessionID;
	string timeEnd;
	string subject;
	string location;
	string sessionDate;
	string timeStart;
	string description;
	int hostID;
	int currentNumberOfPeople;
	int limitNumberOfPeople;
public:
	Session();
	Session(string sId, int hId, string tS, int nOP, string tE, 
		string date, string sub, string loc, int tNOP, string desc);
	~Session();
	
	void send_session_to_database(Session);
	string get_sessionID();
	string get_timeend();
	string get_subject();
	string get_location();
	string get_timestart();
	string get_description();
	string get_date();
	int get_hostId();
	int get_currentNumberOfPeople();
	int get_limitNumberOfPeople();
};

