#include "Session.h"



Session::Session()
{
}

Session::Session(string sId, int hId , string tS, int nOP, string tE, string sub, string loc, int tNOP, list<Account> lOP, string desc)
{
	sessionID = sId;
	hostId = hId; 
	timeStart = tS; 
	currentNumberOfPeople = nOP; 
	timeEnd = tE; 
	subject = sub; 
	location = loc; 
	maximumCapacityOfPeople = tNOP; 
	listOfPeople = lOP; 
	description = desc; 
}


Session::~Session()
{
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
