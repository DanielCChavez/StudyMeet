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
	ErrorHandler *error_window;
	QSqlQuery query;
	int connection_status;

	DatabaseHandler();
	int connect();
	int is_open();
	int load_all_data(std::list<Session>);
public:
	static DatabaseHandler* get_instance();
	~DatabaseHandler();
	int get_connection_status() const { return connection_status; }
	int add_to_database(Session);
	int add_to_database(Account);
	int update_session(Session);
	int remove_session(Session, Account);
protected:
	static DatabaseHandler *inst;
};

