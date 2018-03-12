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

int DatabaseHandler::connect()
{
	db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("studymeet.cswura1xfuzk.us-west-1.rds.amazonaws.com");
	db.setDatabaseName("users");
	db.setUserName("studymeet");
	db.setPassword("studymeet");

	return 0;
}

int DatabaseHandler::is_open()
{
	if(!db.open())
	{
		ErrorHandler err;
		err.display_error(db.lastError().text());
		return false;
	}
	return true;
}

int DatabaseHandler::add_to_database(Account acc)
{
	DatabaseHandler *d = DatabaseHandler::get_instance();
	QSqlQuery query(db);
	QString name = "name500";//acc.get_username();
	QString pass = "pass";//acc.get_password();

	QString query_string = "INSERT INTO users VALUES ('" + name + "', '" + pass + "')";
	
	ErrorHandler err;
	if (!query.exec(query_string))
	{
		err.display_error(query.lastError().text());
	}
	else // testing purposes, remove later
	{
		err.display_error("INSERT OK");
	}

	return 0;
}