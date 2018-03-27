#include "DatabaseHandler.h"


DatabaseHandler* DatabaseHandler::inst = 0;

DatabaseHandler::DatabaseHandler()
{
	connection_status = 1;
	error_window = ErrorHandler::get_instance();
	connect();
	if (is_open())
	{
		connection_status = 0;
		query = QSqlQuery(db);
	}
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
		error_window->display_error(db.lastError().text());
		return 0;
	}
	return 1;
}

int DatabaseHandler::add_to_database(Account acc)
{	
	query.prepare("INSERT INTO users (username, password_hash) "
		"VALUES (:username, :password_hash)");
	query.bindValue(":username", acc.get_username().c_str());
	query.bindValue(":password_hash", acc.get_password().c_str());
	
	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
	}
	else // testing purposes, remove later
	{
		error_window->display_error("INSERT OK");
	}

	return 0;
}

int DatabaseHandler::add_to_database(Session s)
{
	query.prepare("INSERT INTO sessions (sessionID, hostID, timeStart, timeEnd, "
		"currentNumberOfPeople, subject, location, description, maximumCapacityOfPeople) "
		"VALUES (:sessionID, :hostID, :timeStart, :timeEnd, :currentNumberoOfPeople, "
		":topic, :location, :description, :maximumCapacityOfPeople)");
	query.bindValue(":sessionID", s.get_sessionID().c_str());
	query.bindValue(":hostID", s.get_hostId());
	query.bindValue(":timeStart", s.get_timestart().c_str());
	query.bindValue(":timeEnd", s.get_timeend().c_str());
	query.bindValue(":currentNumberOfPeople", s.get_currentnumberofpeopleinsession());
	query.bindValue(":maximumcapacityofpeopleinsession", s.get_maximumcapacityofpeopleinsession());
	query.bindValue(":subject", s.get_subject().c_str());
	query.bindValue(":location", s.get_location().c_str());
	query.bindValue(":description", s.get_description().c_str());

	
	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
	}
	else //remove later
		error_window->display_error("insert into sessions OK");


	return 0;
}

int DatabaseHandler::update_session(Session s)
{
	query.prepare("UPDATE sessions"
		"SET timeStart = :newTimeStart, timeEnd = :newTimeEnd, description = :newDescription, "
		"maximumCapacityOfPeople = :newCapacity, subject = :subject, location = :location "
		"WHERE sessionID = :sessionID");

	query.bindValue(":sessionID", s.get_sessionID().c_str());
	query.bindValue(":timeStart", s.get_timestart().c_str());
	query.bindValue(":timeEnd", s.get_timeend().c_str());
	query.bindValue(":subject", s.get_subject().c_str());
	query.bindValue(":location", s.get_location().c_str());
	query.bindValue(":description", s.get_description().c_str());
	query.bindValue(":maximumcapacityofpeopleinsession", s.get_maximumcapacityofpeopleinsession());
	
	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
	}
	else
		error_window->display_error("session updated");

	return 0;
}

int DatabaseHandler::update_account(Account acc)
{
	query.prepare("UPDATE users"
		"SET username = :username, password = :password "
		"WHERE accountID = :accountID");


	query.bindValue(":accountID", acc.get_accountID());
	query.bindValue(":username", acc.get_username().c_str());


	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
	}
	else
		error_window->display_error("account updated");

	return 0;

}

int DatabaseHandler::remove_session(Session s, Account a)
{
	//Need to implement Account::get_id() before this will compile

	/*
	if (s.get_hostId() != a.get_id)
	{
		error_window->display_error("Only the host can delete a session");
		return 1;
	}
	
	query.prepare("DELETE FROM sessions WHERE hostId = :hostId");
	query.bindValue(":hostId", s.get_hostId());

	if (!query.exec())
		error_window->display_error(query.lastError().text());
	else
		error_window->display_error("delete, OK");
		*/
	return 0;
}