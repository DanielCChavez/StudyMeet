#pragma once
#include <QMessageBox>
#include <QString>

class ErrorHandler
{
private:
	ErrorHandler();
public:
	~ErrorHandler();
	static ErrorHandler* get_instance();
	void display_error(QString);
protected:
	static ErrorHandler *inst;
};

