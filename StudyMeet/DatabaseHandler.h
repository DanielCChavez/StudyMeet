#pragma once

#include <QtSql>
#include "ErrorHandler.h"

class DatabaseHandler
{
private:
	QSqlDatabase db;
	DatabaseHandler();
public:
	static DatabaseHandler* get_instance();
	~DatabaseHandler();
	void connect();
	//QSqlDatabase get_db() const { return db; };
	bool open();
protected:
	static DatabaseHandler *inst;
};

