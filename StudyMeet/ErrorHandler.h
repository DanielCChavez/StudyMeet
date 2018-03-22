#pragma once
#include <QMessageBox>
#include <QString>

class ErrorHandler
{

public:
	ErrorHandler();
	~ErrorHandler();
	void display_error(QString);
};

