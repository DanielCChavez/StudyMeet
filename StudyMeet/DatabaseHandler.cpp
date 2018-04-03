#include "DatabaseHandler.h"
#include <iterator>


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
	query.prepare("INSERT INTO accounts (accountID, username, password, firstName, lastName, dateCreated, "
		"gradeLevel, sessionID)"
		"VALUES (:accountID, :username, :password, :firstName, :lastName, :dateCreated, "
		":gradeLevel, :sessionID)");
	query.bindValue(":accountID", acc.get_accountID());
	query.bindValue(":username", acc.get_username().c_str());
	query.bindValue(":password", acc.get_password().c_str());
	query.bindValue(":firstName", acc.get_firstName().c_str());
	query.bindValue(":lastName", acc.get_lastName().c_str());
	query.bindValue(":dateCreated", acc.get_dateCreated().c_str());
	query.bindValue(":gradeLevel", acc.get_gradeLevel().c_str());
	query.bindValue(":sessionID", acc.get_sessionID().c_str());
	
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
	query.prepare("INSERT INTO sessions (sessionID, hostId, timeStart, timeEnd, "
		"maximumCapacityOfPeople, subject, location, description, currentNumberOfPeople, sessionDate) "
		"VALUES (:sessionID, :hostID, :timeStart, :timeEnd, :maximumCapacityOfPeople, "
		":topic, :location, :description, :currentNumberOfPeople, :date)");
	query.bindValue(":sessionID", s.get_sessionID().c_str());
	query.bindValue(":hostID", s.get_hostId());
	query.bindValue(":timeStart", s.get_timestart().c_str());
	query.bindValue(":timeEnd", s.get_timeend().c_str());
	query.bindValue(":currentNumberOfPeople", s.get_currentnumberofpeopleinsession());
	query.bindValue(":maximumCapacityOfPeople", s.get_maximumcapacityofpeopleinsession());
	query.bindValue(":topic", s.get_subject().c_str());
	query.bindValue(":location", s.get_location().c_str());
	query.bindValue(":description", s.get_description().c_str());
	query.bindValue(":date", s.get_date().c_str());
	
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
		"maximumCapacityOfPeople = :newCapacity, subject = :subject, location = :location, sessionDate = :date"
		"WHERE sessionID = :sessionID");

	query.bindValue(":sessionID", s.get_sessionID().c_str());
	query.bindValue(":timeStart", s.get_timestart().c_str());
	query.bindValue(":timeEnd", s.get_timeend().c_str());
	query.bindValue(":subject", s.get_subject().c_str());
	query.bindValue(":location", s.get_location().c_str());
	query.bindValue(":description", s.get_description().c_str());
	query.bindValue(":maximumcapacityofpeopleinsession", s.get_maximumcapacityofpeopleinsession());
	query.bindValue(":date", s.get_date().c_str());
	
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
	if (s.get_hostId() != a.get_accountID())
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
	return 0;
}

int DatabaseHandler::load_all_sessions(list<Session>& listS)
{
	string sessionID, timeStart, timeEnd, subject, location, description, date;
	int hostID, maximumCapacityOfPeople, currentNumberOfPeople;


	query.exec("SELECT * FROM sessions");

	//do while there are records(rows)
	while (query.next())
	{
		//assign each value of the record to a variable, depending on the record value index
		sessionID = query.value(0).toString().toStdString();
		hostID = query.value(1).toInt();
		timeStart = query.value(2).toString().toStdString();
		timeEnd = query.value(3).toString().toStdString();
		maximumCapacityOfPeople = query.value(4).toInt();
		subject = query.value(5).toString().toStdString();
		location = query.value(6).toString().toStdString();
		description = query.value(7).toString().toStdString();
		currentNumberOfPeople = query.value(8).toInt();
		date = query.value(9).toString().toStdString();

		//create a session to push it to the listSession
		Session session(sessionID, hostID, timeStart, currentNumberOfPeople, timeEnd, date, subject, location, maximumCapacityOfPeople, description);
		listS.push_back(session);
	}

	return 0;
}

int DatabaseHandler::validate_account(std::string username, std::string pass)
{
	QString result;
	query.prepare("SELECT EXISTS (SELECT 1 FROM accounts WHERE username = :uname AND "
		"password = :pw LIMIT 1)");
	query.bindValue(":uname", username.c_str());
	query.bindValue(":pw", pass.c_str());
	
	query.exec();
	while (query.next())
	{
		result = query.value(0).toString();
	}
	
	if (result == "1")
		return 0;

	return 1;
}

int DatabaseHandler::validate_account(int accID)
{
	QString result;
	query.prepare("SELECT EXISTS (SELECT 1 FROM accounts WHERE accountID = :accID LIMIT 1)");
	query.bindValue(":accID", accID);
	query.exec();

	while (query.next())
	{
		result = query.value(0).toString();
	}

	if (result == "1")
		return 0;

	return 1;
}

int DatabaseHandler::validate_account(std::string username)
{
	QString result;
	query.prepare("SELECT EXISTS (SELECT 1 FROM accounts WHERE username = :user LIMIT 1)");
	query.bindValue(":user", username.c_str());
	query.exec();

	while (query.next())
	{
		result = query.value(0).toString();
	}

	if (result == "1")
		return 0;

	return 1;
}

Account DatabaseHandler::get_account(std::string username, std::string pass)
{
	QString result;
	string user, password, firstName, lastName, dateCreated, gradeLevel, sessionID;
	int accountID;

	if (validate_account(username, pass) != 0)
		return Account("ERRORUSERNAME", "ERRORPASSWORD", "ERRORFIRSTNAME", "ERRORLASTNAME", "ERRORDATECREATED", "ERRORGRADELEVEL", "ERRORSESSIONID", -1);
	query.prepare("select * from accounts where username = :username and password = :pass");
	query.bindValue(":username", username.c_str());
	query.bindValue(":pass", pass.c_str());
	query.exec();
	while (query.next())
	{
		user = query.value(1).toString().toStdString();
		password = query.value(2).toString().toStdString();
		firstName = query.value(3).toString().toStdString();
		lastName = query.value(4).toString().toStdString();
		dateCreated = query.value(5).toString().toStdString();
		gradeLevel = query.value(6).toString().toStdString();
		sessionID = query.value(7).toString().toStdString();
		accountID = query.value(0).toInt();
	}

	return Account(user, password, firstName, lastName, dateCreated, gradeLevel, sessionID, accountID);
}

int DatabaseHandler::validate_session(int sessID)
{

	QString result;
	query.prepare("SELECT EXISTS (SELECT 1 FROM sessions WHERE sessionID = :sessID LIMIT 1)");
	query.bindValue(":sessID", sessID);
	query.exec();

	while (query.next())
	{
		result = query.value(0).toString();
	}

	if (result == "1")
		return 0;

	return 1;
}
