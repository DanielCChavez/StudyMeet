#include "viewsessions.h"
#include "Session.h"
ViewSessions* ViewSessions::instance = NULL;

ViewSessions::ViewSessions(QWidget *parent)
	: QWidget(parent)
{
	QStringList titles;
	Session test("123", 21, "1AM", 8, "3AM", "Computer Science", "Anywhere", 10, "i need help understanding an algorithm.");
	titles << "Host" << "Subject" << "Time" << "Location";

	QString time;
	QString subject;
	QString id;
	QString location;
	int row;
	time = QString::fromStdString(test.get_timestart());
	subject = QString::fromStdString(test.get_subject());
	id = QString::number(test.get_hostId());
	location = QString::fromStdString(test.get_location());

	ui.setupUi(this);
	ui.sessionTable->setHorizontalHeaderLabels(titles);
	ui.sessionTable->insertRow(ui.sessionTable->rowCount());
	row = ui.sessionTable->rowCount() - 1;

	ui.sessionTable->setItem(row, 2, new QTableWidgetItem(time));

	ui.sessionTable->setItem(row, 1, new QTableWidgetItem(subject));

	ui.sessionTable->setItem(row, 0, new QTableWidgetItem(id));

	ui.sessionTable->setItem(row, 3, new QTableWidgetItem(location));
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

