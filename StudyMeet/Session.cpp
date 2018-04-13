#include "Session.h"
#include "DatabaseHandler.h"


Session::Session()
{
	sessionID = "DEFAULTSESSIONID";
	timeStart = "DEFAULTTIMESTART";
	timeEnd = "DEFAULTTIMEEND";
	sessionDate = "DEFAULTSESSIONDATE";
	subject = "DEFAULTSUBJECT";
	location = "DEFAULTLOCATION";
	description = "DEFAULTDESCRIPTION";
	hostID = -1;
	currentNumberOfPeople = -1;
	limitNumberOfPeople = -1;
}

Session::Session(string sessID, int hID , string timeS, int numOfPeople, 
	string timeE, string date, string subj, string loc, int limit, string desc)
{
	sessionID = sessID;
	hostID = hID; 
	sessionDate = date;
	timeStart = timeS;
	timeEnd = timeE; 
	subject = subj; 
	location = loc; 
	currentNumberOfPeople = numOfPeople;
	limitNumberOfPeople = limit; 
	description = desc; 
}


Session::~Session()
{

}

void Session::send_session_to_database(Session session)
{
	DatabaseHandler* handler = DatabaseHandler::get_instance();
	handler->add_to_database(session);
}

void Session::add_account_to_sessionlist(Account account)
{
	listOfPeople.push_back(account);
}



string Session::get_sessionID()
{
	return sessionID;
}

int Session::get_hostId()
{
	return hostID;
}

string Session::get_timestart()
{
	return timeStart;
}

int Session::get_currentNumberOfPeople()
{
	return currentNumberOfPeople;
}

string Session::get_timeend()
{
	return timeEnd;
}

string Session::get_subject()
{
	return subject;
}

string Session::get_location()
{
	return location;
}

int Session::get_limitNumberOfPeople()
{
	return limitNumberOfPeople;
}

list<Account> Session::get_listofpeople()
{
	return listOfPeople;
}

string Session::get_description()
{
	return description;
}

string Session::get_date()
{
	return sessionDate;
}
