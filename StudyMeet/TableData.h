 #pragma once

#include "DatabaseHandler.h"
#include <iterator>
#include <string>

class TableData
{
public:
	list<Session> listSessions;

	Session find_session(string);
	TableData();
	~TableData();
};

