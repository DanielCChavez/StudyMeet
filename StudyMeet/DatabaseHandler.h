#pragma once

#include <QtSql>
#include "ErrorHandler.h"

class DatabaseHandler
{
private:
	QSqlDatabase db;
public:
	DatabaseHandler();
	~DatabaseHandler();
	QSqlDatabase get_db() const { return db; };
	bool open();

};

