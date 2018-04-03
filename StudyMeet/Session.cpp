#include "Session.h"
#include "DatabaseHandler.h"


Session::Session()
{
}

Session::Session(string sId, int hId , string tS, int nOP, string tE, string date, string sub, string loc, int tNOP, string desc)
{
	sessionID = sId;
	hostId = hId; 
	timeStart = tS; 
	currentNumberOfPeople = nOP; 
	sessiondate = date;
	timeEnd = tE; 
	subject = sub; 
	location = loc; 
	maximumCapacityOfPeople = tNOP; 
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
	return hostId;
}

string Session::get_timestart()
{
	return timeStart;
}

int Session::get_currentnumberofpeopleinsession()
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

int Session::get_maximumcapacityofpeopleinsession()
{
	return maximumCapacityOfPeople;
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
	return sessiondate;
}
