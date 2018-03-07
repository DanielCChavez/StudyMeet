#include "DatabaseHandler.h"

DatabaseHandler* DatabaseHandler::inst = 0;

DatabaseHandler::DatabaseHandler()
{
	
}


DatabaseHandler::~DatabaseHandler()
{
	db.close();
	db.removeDatabase("QMYSQL");
}

DatabaseHandler* DatabaseHandler::get_instance()
{
	if (!inst)
		inst = new DatabaseHandler();

	return inst;
}

void DatabaseHandler::connect()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("studymeet.cswura1xfuzk.us-west-1.rds.amazonaws.com");
	db.setDatabaseName("users");
	db.setUserName("studymeet");
	db.setPassword("studymeet");
}

bool DatabaseHandler::open()
{
	if(!db.open())
	{
		ErrorHandler err;
		err.display_error(db.lastError().text());
		return false;
	}
	return true;
}
