#include "ErrorHandler.h"



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
