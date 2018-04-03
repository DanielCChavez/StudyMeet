 #pragma once

#include "DatabaseHandler.h"
#include <iterator>
#include <string>
#include "viewsessions.h"

class TableData
{
public:
	list<Session> listSessions;

	Session find_session(string);

	int fill_session_table(ViewSessions*, TableData*);

	TableData();
	~TableData();
};

