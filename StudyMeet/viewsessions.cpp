#include "viewsessions.h"
#include "Session.h"
#include "detailedstudysession.h"
#include "createnewsession.h"

#include <iterator>;
#include "TableData.h"

ViewSessions* ViewSessions::instance = NULL;

ViewSessions::ViewSessions(QWidget *parent)
	: QWidget(parent)
{
	//TableData object
	TableData TD;

	QStringList titles;
	Session test("123", 21, "1AM", 8, "3AM", "Computer Science", "Anywhere", 10, "i need help understanding an algorithm.");
	Session tester("123", 22, "5PM", 4, "6PM", "Math", "Kellog Library", 5, "I need help working through some problems");

	titles << "Host" << "Subject" << "Time" << "Location";

	list<Session> testList;
	testList.push_back(test);
	testList.push_back(tester);
	QString time;
	QString subject;
	QString id;
	QString location;
	int row;
	list<Session>::iterator it; 

	ui.setupUi(this);
	ui.sessionTable->setHorizontalHeaderLabels(titles);

	/*
	for (it = testList.begin(); it != testList.end(); it++)
	{
		ui.sessionTable->insertRow(ui.sessionTable->rowCount());
		time = QString::fromStdString(it->get_timestart());
		subject = QString::fromStdString(it->get_subject());
		id = QString::number(it->get_hostId());
		location = QString::fromStdString(it->get_location());


		row = ui.sessionTable->rowCount() - 1;

		ui.sessionTable->setItem(row, 2, new QTableWidgetItem(time));

		ui.sessionTable->setItem(row, 1, new QTableWidgetItem(subject));

		ui.sessionTable->setItem(row, 0, new QTableWidgetItem(id));

		ui.sessionTable->setItem(row, 3, new QTableWidgetItem(location));
	}*/

	//Testing the listSession from Table Data
	for (it = TD.listSessions.begin(); it != TD.listSessions.end(); it++)
	{
	ui.sessionTable->insertRow(ui.sessionTable->rowCount());
	time = QString::fromStdString(it->get_timestart());
	subject = QString::fromStdString(it->get_subject());
	id = QString::number(it->get_hostId());
	location = QString::fromStdString(it->get_location());


	row = ui.sessionTable->rowCount() - 1;

	ui.sessionTable->setItem(row, 2, new QTableWidgetItem(time));

	ui.sessionTable->setItem(row, 1, new QTableWidgetItem(subject));

	ui.sessionTable->setItem(row, 0, new QTableWidgetItem(id));

	ui.sessionTable->setItem(row, 3, new QTableWidgetItem(location));
	}
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

void ViewSessions::on_createSessionButton_clicked()
{
	CreateNewSession *cs = CreateNewSession::Instance();
	cs->show();
}

void ViewSessions::on_detailsButton_clicked()
{
	DetailedStudySession *ds = DetailedStudySession::Instance();
	ds->show();
}
