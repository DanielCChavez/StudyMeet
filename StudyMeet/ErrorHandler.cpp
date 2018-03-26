#include "ErrorHandler.h"

ErrorHandler* ErrorHandler::inst = 0;

ErrorHandler::ErrorHandler()
{
}


ErrorHandler::~ErrorHandler()
{
}

void ErrorHandler::display_error(QString message)
{
	QMessageBox box;
	box.setWindowTitle("Error Message");
	box.setText(message);
	box.setStandardButtons(QMessageBox::Ok);
	box.exec();
}

ErrorHandler* ErrorHandler::get_instance()
{
	if (inst == 0)
		inst = new ErrorHandler();
	return inst;
}