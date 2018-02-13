#include "DatabaseHandler.h"

DatabaseHandler::DatabaseHandler()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("studymeet.cswura1xfuzk.us-west-1.rds.amazonaws.com");
	db.setDatabaseName("users");
	db.setUserName("studymeet");
	db.setPassword("studymeet");
}


DatabaseHandler::~DatabaseHandler()
{
	db.close();
	db.removeDatabase("QMYSQL");
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
