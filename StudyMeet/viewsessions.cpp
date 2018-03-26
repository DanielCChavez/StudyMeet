#include "viewsessions.h"

ViewSessions* ViewSessions::instance = NULL;

ViewSessions::ViewSessions(QWidget *parent)
	: QWidget(parent)
{
	QStringList titles;
	titles << "Host" << "Subject" << "Time" << "Location";
	ui.setupUi(this);
	ui.sessionTable->setHorizontalHeaderLabels(titles);
}


ViewSessions::~ViewSessions()
{
	
}

ViewSessions* ViewSessions::Instance()
{
	if (instance == NULL)
		instance = new ViewSessions();

		return instance; 
}

