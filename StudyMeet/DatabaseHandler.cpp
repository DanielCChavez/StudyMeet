#include "DatabaseHandler.h"
#include <iterator>

DatabaseHandler* DatabaseHandler::inst = 0;

DatabaseHandler::DatabaseHandler()
{
	connection_status = 1;
	error_window = ErrorHandler::get_instance();
	ac = AccountSingleton::get_instance();
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
		return 1;
	}

	return 0;
}

// Return 0 on sucessfull insert into database
// 1 on error in execution of query
// 2 if already in a session
// 3 if could not update account database
int DatabaseHandler::add_to_database(Session s)
{
	int result;

	//Check local sessID, must be empty
	//First, sync local account with DB account
	result = sync_account(ac);
	if (result == 1)
		return 3;

	// Check if account is in a session
	if (ac->is_in_session() != 0)
	{
		return 2;
	}

	query.prepare("INSERT INTO sessions (sessionID, hostId, timeStart, timeEnd, "
		"maximumCapacityOfPeople, subject, location, description, currentNumberOfPeople, sessionDate, expiration_date) "
		"VALUES (:sessionID, :hostID, :timeStart, :timeEnd, :maximumCapacityOfPeople, "
		":topic, :location, :description, :currentNumberOfPeople, :date, :expiration)");

	query.bindValue(":sessionID", s.get_sessionID().c_str());
	query.bindValue(":hostID", s.get_hostId());
	query.bindValue(":timeStart", s.get_timestart().c_str());
	query.bindValue(":timeEnd", s.get_timeend().c_str());
	query.bindValue(":currentNumberOfPeople", s.get_currentNumberOfPeople());
	query.bindValue(":maximumCapacityOfPeople", s.get_limitNumberOfPeople());
	query.bindValue(":topic", s.get_subject().c_str());
	query.bindValue(":location", s.get_location().c_str());
	query.bindValue(":description", s.get_description().c_str());
	//query.bindValue(":date", s.get_date().c_str());
	std::string dt = s.get_date();
	QDate d(stoi(dt.substr(6, 4)), stoi(dt.substr(0, 2)), stoi(dt.substr(3, 2)));
	query.bindValue(":date", d);

	std::string dtime = "";
	QTime mn(23, 59, 59, 59);

	QDateTime tm(d.addDays(1), mn);
	query.bindValue(":expiration", tm);


	if (!query.exec())
	{
		return 1;
	}

	//Session Database updated, now update local account
	//update local sessionID
	ac->set_sessionID(s.get_sessionID());

	//update account database 
	if (update_account(ac) != 0)
		return 3;

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
	query.bindValue(":maximumcapacityofpeopleinsession", s.get_limitNumberOfPeople());
	query.bindValue(":date", s.get_date().c_str());
	
	if (!query.exec())
	{
		return 1;
	}

	return 0;
}

// Return 0 if successfull updated account
// 1 otherwise
int DatabaseHandler::update_account(AccountSingleton *acc)
{
	query.prepare("UPDATE accounts "
		"SET sessionID = :sessID "
		"WHERE accountID = :accID");

	query.bindValue(":accID", acc->get_accountID());
	query.bindValue(":sessID", acc->get_sessionID().c_str());

	if (!query.exec())
	{
		return 1;
	}

	return 0;
}


// Return 2 if not the host of selected session
// Return 1 if error in query execution
// Return 0 if successfully removes record
int DatabaseHandler::remove_session(Session s)
{
	std:string estring = "";

	if (is_host(s) != 0)
		return 2;
	
	// Remove from database
	query.prepare("DELETE FROM sessions "
		"WHERE hostId = :hostId");
	query.bindValue(":hostId", s.get_hostId());
	if (!query.exec())
	{
		return 1;
	}

	// Update all accounts that were apart of the session
	query.prepare("UPDATE accounts "
		"SET sessionID = :estr "
		"WHERE sessionID = :sessID");
	query.bindValue(":estr", estring.c_str());
	query.bindValue(":sessID", s.get_sessionID().c_str());

	if (!query.exec())
	{
		return 1;
	}

	return 0;
}


// Returns 0 if the logged in account is the host of the session
// 1 if not the host of session
int DatabaseHandler::is_host(Session s)
{
	if (ac->get_accountID() == s.get_hostId())
		return 0;

	return 1;

}

// Return 1 on error in query execution
// Return 0 on successful grabbing all session from database
int DatabaseHandler::load_all_sessions(list<Session>& listS)
{
	string sessionID, timeStart, timeEnd, subject, location, description, date;
	int hostID, maximumCapacityOfPeople, currentNumberOfPeople;
	
	listS.clear();

	if (!query.exec("SELECT * FROM sessions"))
		return 1;

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
		Session session(sessionID, hostID, timeStart, currentNumberOfPeople, 
			timeEnd, date, subject, location, maximumCapacityOfPeople, description);
		listS.push_back(session);
	}

	return 0;
}


// Return 0 if username and password match a record on database
// 2 if password and username do not match a record on database
// 1 if error in query execution
int DatabaseHandler::validate_account(std::string username, std::string pass)
{
	QString result;

	query.prepare("SELECT EXISTS (SELECT 1 FROM accounts WHERE username = :uname AND "
		"password = :pw LIMIT 1)");
	query.bindValue(":uname", username.c_str());
	query.bindValue(":pw", pass.c_str());
	
	if (!query.exec())
	{
		return 1;
	}

	while (query.next())
	{
		result = query.value(0).toString();
	}
	
	if (result == "1")
		return 0;

	return 2;
}

// Return 0 if the accountID is being used on the database
// Return 1 if the accountID is not being used on database
// Return 2 if error in query execution
int DatabaseHandler::validate_account(int accID)
{
	QString result;
	
	query.prepare("SELECT EXISTS (SELECT 1 FROM accounts WHERE accountID = :accID LIMIT 1)");
	query.bindValue(":accID", accID);
	
	if (!query.exec())
	{
		return 2;
	}

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
// Return 2 if error in query execution
int DatabaseHandler::validate_account(std::string username)
{

	QString result;
	query.prepare("SELECT EXISTS (SELECT 1 FROM accounts WHERE username = :user LIMIT 1)");
	query.bindValue(":user", username.c_str());
	
	if (!query.exec())
	{
		return 2;
	}

	while (query.next())
	{
		result = query.value(0).toString();
	}

	if (result == "1")
		return 0;

	return 1;
}

// Retrieves an account on the database
// Return 1 if account exists
// Return 2 if error in query execution
// Return 0 on success
int DatabaseHandler::get_account(std::string username, std::string pass, Account &a)
{
	QString result;
	string user, password, firstName, lastName, dateCreated, gradeLevel, sessionID;
	int accountID;

	if (validate_account(username, pass) != 0)
		return 1;
		
	query.prepare("select * from accounts where username = :username and password = :pass");
	query.bindValue(":username", username.c_str());
	query.bindValue(":pass", pass.c_str());
	
	if (!query.exec())
	{
		return 2;
	}

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


	a =  Account(user, password, firstName, lastName, dateCreated, gradeLevel, sessionID, accountID);
	return 0;
}

// Return 0 if the sessID is a valid session
// Return 1 if sessID is not a valid session
// Return 2 if error in query execution
int DatabaseHandler::validate_session(int sessID)
{
	QString result;
	
	query.prepare("SELECT EXISTS (SELECT 1 FROM sessions WHERE sessionID = :sessID LIMIT 1)");
	query.bindValue(":sessID", sessID);
	
	if (!query.exec())
	{
		return 2;
	}

	while (query.next())
	{
		result = query.value(0).toString();
	}

	if (result == "1")
		return 0;

	return 1;
}


// Return 0 on successful joining of session
// Return 1 if already in a session.
// Return 2 if could not update account database
// Return 3 on error in query execution
// Return 4 on limit of session
// Return 5 if session does not exist
int DatabaseHandler::join_session(int accID, std::string sessID)
{
	int currentNumberOfPeople, maximum;

	// Sync local
	sync_account(ac);


	if (validate_session(stoi(sessID)) == 1) 
	{
		return 5;
	}

	if (ac->is_in_session() != 0)
	{
		return 1;
	}

	//update local
	ac->set_sessionID(sessID);
	
	//update database
	if (update_account(ac) != 0)
	{
		return 2;
	}

	query.prepare("SELECT currentNumberOfPeople, maximumCapacityOfPeople "
		"FROM sessions "
		"WHERE sessionID = :sessID");
	query.bindValue(":sessID", sessID.c_str());

	if (!query.exec())
	{
		return 3;
	}

	while (query.next())
	{
		currentNumberOfPeople = query.value(0).toInt();
		maximum = query.value(1).toInt();

		if (currentNumberOfPeople >= maximum)
		{
			return 4;
		}
		currentNumberOfPeople += 1;
	}

	query.prepare("UPDATE sessions "
		"SET currentNumberOfPeople = :numPeople "
		"WHERE sessionID = :sessID");
	query.bindValue(":numPeople", currentNumberOfPeople);
	query.bindValue(":sessID", sessID.c_str());

	if (!query.exec())
	{
		return 3;
	}

	return 0;
}


// Return 1 if error in query execution
// Return 2 if not in the session
// Return 3 if trying to leave session you host
// Return 0 on success
int DatabaseHandler::leave_session(int accID, std::string sessID, int hid)
{
	std::string emptyString = "";
	int currentNumberOfPeople;

	if (sync_account(ac) == 1)
		return 1;

	if (ac->get_sessionID() != sessID)
	{
		return 2;
	}

	if (ac->get_accountID() == hid)
	{
		return 3;
	}
	
	// update accounts table
	query.prepare("UPDATE accounts "
		"SET sessionID = :emptyString "
		"WHERE accountID = :accID");
	query.bindValue(":accID", accID);
	query.bindValue(":emptyString", emptyString.c_str());

	ac->set_sessionID(emptyString);

	if (update_account(ac) != 0)
	{
		return 1;
	}

	if (!query.exec())
	{
		return 1;
	}

	// update sessions table number of people
	query.prepare("SELECT currentNumberOfPeople "
		"FROM sessions "
		"WHERE sessionID = :sessID");
	query.bindValue(":sessID", sessID.c_str());

	if (!query.exec())
	{
		return 1;
	}
	while (query.next())
	{
		currentNumberOfPeople = query.value(0).toInt();
		currentNumberOfPeople -= 1;
	}

	// Updating session table
	query.prepare("UPDATE sessions "
		"SET currentNumberOfPeople = :numPeople "
		"WHERE sessionID = :sessID");
	query.bindValue(":numPeople", currentNumberOfPeople);
	query.bindValue(":sessID", sessID.c_str());

	if (!query.exec())
	{
		return 1;
	}

	return 0;
}

int DatabaseHandler::get_account(int id, Account &a)
{
	QString result;
	string user, password, firstName, lastName, dateCreated, gradeLevel, sessionID;
	int accountID;

	if (validate_account(id) != 0)
	{
		a = Account("ERRORUSERNAME", "ERRORPASSWORD", "ERRORFIRSTNAME", "ERRORLASTNAME",
			"ERRORDATECREATED", "ERRORGRADELEVEL", "ERRORSESSIONID", -1);
		return 1;
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

	a = Account(user, password, firstName, lastName, dateCreated, gradeLevel, sessionID, accountID);
	return 0;
}


// Return 1 on query execution error
int DatabaseHandler::sync_account(AccountSingleton *acc)
{
	QString sessID = "";
	int accID = 0;

	accID = acc->get_accountID();

	query.prepare("SELECT sessionID "
		"FROM accounts "
		"WHERE accountID = :accID");
	query.bindValue(":accID", accID);


	if (!query.exec())
	{
		return 1;
	}

	while (query.next())
	{
		sessID = query.value(0).toString();
	}

	acc->set_sessionID(sessID.toStdString());
	if (update_account(acc) != 0)
	{
		return 1;
	}

	return 0;
}

QString DatabaseHandler::query_error()
{
	return query.lastError().text();
}

int DatabaseHandler::log_on(AccountSingleton *a)
{
	int aid;
	aid = a->get_accountID();

	query.prepare("UPDATE accounts "
		"SET logged_in_flag = 1 "
		"WHERE accountID = :aid");
	query.bindValue(":aid", aid);

	if (!query.exec()) { return 1; }
	return 0;
}

int DatabaseHandler::log_off(AccountSingleton *a)
{
	int aid;
	aid = a->get_accountID();

	query.prepare("UPDATE accounts "
		"SET logged_in_flag = 0 "
		"WHERE accountID = :aid");
	query.bindValue(":aid", aid);

	if (!query.exec()) { return 1; }
	return 0;
}