#pragma once

#include <QtSql>
#include <list>
#include "ErrorHandler.h"
#include "Account.h"
#include "Session.h"
#include "AccountSingleton.h"

class DatabaseHandler
{
private:
	QSqlDatabase db;
	ErrorHandler *error_window;
	QSqlQuery query;
	AccountSingleton *ac;
	QDateTime dt;
	int connection_status;

	DatabaseHandler();
	int connect();
	int is_open();
public:
	static DatabaseHandler* get_instance();
	~DatabaseHandler();
	int get_connection_status() const { return connection_status; }
	int add_to_database(Session);
	int add_to_database(Account);
	int update_session(Session);
	int update_account(AccountSingleton*);
	int remove_session(Session);
	int is_host(Session);
	int load_all_sessions(std::list<Session>&);
	int validate_account(std::string, std::string);
	int validate_account(int);
	int validate_account(std::string);
	int get_account(std::string username, std::string pass, Account&);
	int get_account(int, Account&);
	int validate_session(int);
	int join_session(int, std::string);
	int leave_session(int, std::string, int);
	int sync_account(AccountSingleton*);
	int log_on(AccountSingleton*);
	int log_off(AccountSingleton*);
	int date_updated_sessions();
	QDateTime get_date_updated_sessions();

	QString query_error();

protected:
	static DatabaseHandler *inst;
};

