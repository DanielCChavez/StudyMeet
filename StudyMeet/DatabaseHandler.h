#pragma once

#include <QtSql>
#include <list>

#include "ErrorHandler.h"
#include "Account.h"

#include "Session.h"

class DatabaseHandler
{
private:
	QSqlDatabase db;
	DatabaseHandler();

	//On startup
	int load_all_data(std::list<Session*>);
public:
	static DatabaseHandler* get_instance();
	~DatabaseHandler();
	int connect();
	int is_open();

	//Query
	int add_to_database(Session);
	int add_to_database(Account);

	int update_session(Session);
	//int update_account(Account);

	int remove_session(Session);
protected:
	static DatabaseHandler *inst;
};

