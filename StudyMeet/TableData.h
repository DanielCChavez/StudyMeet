 #pragma once

#include "DatabaseHandler.h"
#include <iterator>
#include <string>

class TableData
{
public:
	list<Session> listSessions;

	Session find_session(string);

	int add_to_list(Session);

	~TableData();
	static TableData* get_instance();
private:
	TableData();
protected:
	static TableData *instance;
};

