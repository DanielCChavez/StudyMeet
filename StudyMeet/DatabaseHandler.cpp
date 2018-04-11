#include "DatabaseHandler.h"
#include "AccountSingleton.h"
#include <iterator>


DatabaseHandler* DatabaseHandler::inst = 0;

DatabaseHandler::DatabaseHandler()
{
	connection_status = 1;
	error_window = ErrorHandler::get_instance();
	connect();
	if (is_open() == 0)
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

// Return 0 if database connection is open
// 1 otherwise
int DatabaseHandler::is_open()
{
	if(!db.open())
	{
		error_window->display_error(db.lastError().text());
		return 1;
	}
	return 0;
}

// Return 0 on sucessfull insert into database
// 1 on error in execution of query
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
		return 1;
	}

	return 0;
}

// Return 0 on sucessfull insert into database
// 1 on error in execution of query
int DatabaseHandler::add_to_database(Session s)
{
	AccountSingleton *ac = AccountSingleton::get_instance();

	if (ac->get_sessionID() != "")
	{
		error_window->display_error("You cannot host more than one session.");
		return 1;
	}

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
		return 1;
	}

	ac->set_sessionID(s.get_sessionID());
	update_account(*ac);

	return 0;
}

// Return 0 if successfully updated sessions record
// 1 otherwise
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
		return 1;
	}

	return 0;
}

// Return 0 if successfull updated account
// 1 otherwise
int DatabaseHandler::update_account(Account acc)
{
	query.prepare("UPDATE users"
		"SET sessionID = :sessID, password = :password "
		"WHERE accountID = :accountID");


	query.bindValue(":accountID", acc.get_accountID());
	query.bindValue(":sessID", acc.get_sessionID().c_str());


	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
		return 1;
	}

	return 0;
}


// Return 1 if not the host of selected session
// Return 2 if error in query execution
// Return 0 if successfully removes record
int DatabaseHandler::remove_session(Session s)
{
	if (is_host(s) != 0)
		return 1;
	
	
	query.prepare("DELETE FROM sessions WHERE hostId = :hostId");
	query.bindValue(":hostId", s.get_hostId());

	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
		return 2;
	}

	return 0;
}


// Returns 0 if the logged in account is the host of the session
// 1 if not the host of session
int DatabaseHandler::is_host(Session s)
{
	AccountSingleton* logged_in = AccountSingleton::get_instance();
	if (logged_in->get_account().get_accountID() == s.get_hostId())
		return 0;

	return 1;

}

int DatabaseHandler::load_all_sessions(list<Session>& listS)
{
	string sessionID, timeStart, timeEnd, subject, location, description, date;
	int hostID, maximumCapacityOfPeople, currentNumberOfPeople;
	
	listS.clear();

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


// Return 0 if username and password match a record on database
// 1 if password and username do not match a record on database
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

// Return 0 if the accountID is being used on the database
// Return 1 if the accountID is not being used on database
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

// Return 0 if the username is taken
// Return 1 if the username is not taken
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

// Retrieves an account on the database
Account DatabaseHandler::get_account(std::string username, std::string pass)
{
	QString result;
	string user, password, firstName, lastName, dateCreated, gradeLevel, sessionID;
	int accountID;

	if (validate_account(username, pass) != 0)
		return Account("ERRORUSERNAME", "ERRORPASSWORD", "ERRORFIRSTNAME", "ERRORLASTNAME",
			"ERRORDATECREATED", "ERRORGRADELEVEL", "ERRORSESSIONID", -1);
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

// Return 0 if the sessID is a valid session
// Return 1 if sessID is not a valid session
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

int DatabaseHandler::join_session(int accID, std::string sessID)
{
	int currentNumberOfPeople;
	int maximum;
	AccountSingleton *ac = AccountSingleton::get_instance();
	
	if (ac->is_in_session() != 0)
	{
		error_window->display_error("You are already in a session");
		return 1;
	}


	query.prepare("UPDATE accounts "
		"SET sessionID = :sessID "
		"WHERE accountID = :accID");
	query.bindValue(":accID", accID);
	query.bindValue(":sessID", sessID.c_str());

	ac->set_sessionID(sessID);
	
	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
		return 1;
	}

	query.prepare("SELECT currentNumberOfPeople, maximumCapacityOfPeople "
		"FROM sessions WHERE sessionID = :sessID");
	query.bindValue(":sessID", sessID.c_str());
	//query.exec();
	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
		return 2;
	}

	while (query.next())
	{
		currentNumberOfPeople = query.value(0).toInt();
		maximum = query.value(1).toInt();

		if (currentNumberOfPeople >= maximum)
		{
			error_window->display_error("Session at maximum capacity");
			return 1;
		}
		currentNumberOfPeople += 1;
	}

	//currentNumberOfPeople = query.value(0).toInt();
	//error_window->display_error(QString::number(currentNumberOfPeople));
	//currentNumberOfPeople += 1;

	query.prepare("UPDATE sessions "
		"SET currentNumberOfPeople = :numPeople "
		"WHERE sessionID = :sessID");
	query.bindValue(":numPeople", currentNumberOfPeople);
	query.bindValue(":sessID", sessID.c_str());
	//query.exec();
	if (!query.exec())
	{
		error_window->display_error(query.lastError().text());
		return 3;
	}
	return 0;
}

int DatabaseHandler::leave_session(int accID, std::string sessID)
{
	std::string emptyString = "";
	int currentNumberOfPeople;
	AccountSingleton *ac = AccountSingleton::get_instance();

	if (ac->get_sessionID() != sessID)
	{
		error_window->display_error("You are not in this session");
		return 1;
	}

	query.prepare("UPDATE accounts "
		"SET sessionID = :emptyString "
		"WHERE accountID = :accID");
	query.bindValue(":accID", accID);
	query.bindValue(":emptyString", emptyString.c_str());

	ac->set_sessionID(emptyString);

	if (!query.exec())
	{
		error_window->display_error("1st leave");
		return 1;
	}
	query.prepare("SELECT currentNumberOfPeople FROM sessions WHERE sessionID = :sessID");
	query.bindValue(":sessID", sessID.c_str());
	
	if (!query.exec())
	{
		error_window->display_error("2nd leave");
		return 1;
	}
	while (query.next())
	{
		currentNumberOfPeople = query.value(0).toInt();
		currentNumberOfPeople -= 1;
	}


	query.prepare("UPDATE sessions "
		"SET currentNumberOfPeople = :numPeople "
		"WHERE sessionID = :sessID");
	query.bindValue(":numPeople", currentNumberOfPeople);
	query.bindValue(":sessID", sessID.c_str());
	if (!query.exec())
	{
		error_window->display_error("3rd leave");
		return 1;
	}
	
	return 0;
}

Account DatabaseHandler::get_account(int id)
{

	QString result;
	string user, password, firstName, lastName, dateCreated, gradeLevel, sessionID;
	int accountID;

	if (validate_account(id) != 0)
	{
		return Account("ERRORUSERNAME", "ERRORPASSWORD", "ERRORFIRSTNAME", "ERRORLASTNAME",
			"ERRORDATECREATED", "ERRORGRADELEVEL", "ERRORSESSIONID", -1);
	}

	query.prepare("select * from accounts where accountID = :accID");
	query.bindValue(":accID", id);
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