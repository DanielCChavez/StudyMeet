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

int DatabaseHandler::add_to_database(Session s)
{
	QSqlQuery query(db);
	query.prepare("INSERT INTO sessions (sessionID, hostID, timeStart, timeEnd, "
		"currentNumberOfPeople, subject, location, description, maximumCapacityOfPeople) "
		"VALUES (:sessionID, :hostID, :timeStart, :timeEnd, :currentNumberoOfPeople, "
		":topic, :location, :description, :maximumCapacityOfPeople)");
	query.bindValue(":sessionID", s.get_sessionID().c_str());
	query.bindValue(":hostID", 0);	//hard-code an int because of discrepencies in Session class
									//and Session table
									//data member is hostName in Session class
									//and hostID in Session table
	query.bindValue(":timeStart", s.get_timestart().c_str());
	query.bindValue(":timeEnd", s.get_timeend().c_str());
	query.bindValue(":currentNumberOfPeople", s.get_currentnumberofpeopleinsession());	//not sure whether to use this
																		//or get_numberofpeople()
																		//names are confusing.
	query.bindValue(":maximumcapacityofpeopleinsession", s.get_maximumcapacityofpeopleinsession());
	query.bindValue(":subject", s.get_subject().c_str());
	query.bindValue(":location", s.get_location().c_str());
	query.bindValue(":description", s.get_description().c_str());

	//currently no way to get the current list of people inside a session
	//also mission current number of people. We could calculation this if we figure out how to get a
	//list of people

	ErrorHandler e;
	if (!query.exec())
	{
		e.display_error(query.lastError().text());
	}
	else
		e.display_error("insert into sessions OK");


	return 0;
}

int DatabaseHandler::update_session(Session s)
{
	QSqlQuery query(db);

	return 0;
}
