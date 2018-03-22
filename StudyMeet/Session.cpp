#include "Session.h"



Session::Session()
{
}

Session::Session(string sId, string hN, string tS, int nOP, string tE, string sub, string loc, int tNOP, list<Account> lOP, string desc)
{
	sessionID = sId;
	hostName = hN; 
	timeStart = tS; 
	numberOfPeople = nOP; 
	timeEnd = tE; 
	subject = sub; 
	location = loc; 
	totalNumberOfPeople = tNOP; 
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

string Session::get_hostname()
{
	return hostName;
}

string Session::get_timestart()
{
	return timeStart;
}

int Session::get_numberofpeople()
{
	return numberOfPeople;
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

int Session::get_totalnumberofpeople()
{
	return totalNumberOfPeople;
}

list<Account> Session::get_listofpeople()
{
	return listOfPeople;
}

string Session::get_description()
{
	return description;
}
