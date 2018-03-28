#include "TableData.h"


Session TableData::find_session(string s)
{
	for (list<Session>::iterator it = listSessions.begin(); it != listSessions.end(); it++)
	{
		if (s == to_string(it->get_hostId()))
		{
			ErrorHandler * err = ErrorHandler::get_instance();
			err->display_error(QString::fromStdString((*it).get_location()));
			return *it;
		}
	}
	Session se("asdf", 4, "jk;", 1, "ffff", "bus", "col", 3, "mewo");
	return se;
}

TableData::TableData()
{
	DatabaseHandler* handler = DatabaseHandler::get_instance();
	handler->load_all_sessions(listSessions);
}


TableData::~TableData()
{
}

