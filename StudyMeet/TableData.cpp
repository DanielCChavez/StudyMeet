#include "TableData.h"


TableData::TableData()
{
	DatabaseHandler* handler = DatabaseHandler::get_instance();
	handler->load_all_sessions(listSessions);
}


TableData::~TableData()
{
}

