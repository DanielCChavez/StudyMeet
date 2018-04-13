#include "viewsessions.h"
#include "Session.h"
#include "detailedstudysession.h"
#include "createnewsession.h"
#include "ErrorHandler.h"
#include <iterator>
#include "TableData.h"
#include <QTimer>

ViewSessions* ViewSessions::instance = NULL;

ViewSessions::ViewSessions(QWidget *parent)
	: QWidget(parent)
{
	//TableData object
	td = TableData::get_instance();
	hid = 0;
	row_selected = -1;

	QStringList titles;

	titles << "Host" << "Subject" << "Start time" <<"End time" << "Date" << "Location";

	QString timeStart, timeEnd, date, subject, id, location;
	int row;
	list<Session>::iterator it; 

	ui.setupUi(this);
	ui.sessionTable->setHorizontalHeaderLabels(titles);
	ui.sessionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	
	

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(on_refreshButton_clicked()));
	timer->start(3000);
}


ViewSessions::~ViewSessions()
{
	
}

ViewSessions* ViewSessions::Instance()
{
	if (instance == NULL)
		instance = new ViewSessions();

	instance->populate_table();

	return instance; 
}

int ViewSessions::populate_table()
{
	QString timeStart, timeEnd, date, subject, id, location, name;
	int row;
	list<Session>::iterator it;
	DatabaseHandler *db;
	QStringList titles;

	td = TableData::get_instance();
	db = DatabaseHandler::get_instance();

	titles << "Host" << "Subject" << "Start time" << "End time" << "Date" << "Location";
	
	ui.sessionTable->setHorizontalHeaderLabels(titles);
	ui.sessionTable->clearContents();
	ui.sessionTable->setRowCount(0);

	for (it = td->listSessions.begin(); it != td->listSessions.end(); it++)
	{
		ui.sessionTable->insertRow(ui.sessionTable->rowCount());
		timeStart = QString::fromStdString(it->get_timestart());
		timeEnd = QString::fromStdString(it->get_timeend());
		date = QString::fromStdString(it->get_date());
		subject = QString::fromStdString(it->get_subject());
		id = QString::number(it->get_hostId());
		name = QString::fromStdString((db->get_account(it->get_hostId())).get_fullName());
		location = QString::fromStdString(it->get_location());

		row = ui.sessionTable->rowCount() - 1;
		ui.sessionTable->setItem(row, 2, new QTableWidgetItem(timeStart));
		ui.sessionTable->setItem(row, 1, new QTableWidgetItem(subject));
		ui.sessionTable->setItem(row, 0, new QTableWidgetItem(name));
		ui.sessionTable->setItem(row, 3, new QTableWidgetItem(timeEnd));
		ui.sessionTable->setItem(row, 4, new QTableWidgetItem(date));
		ui.sessionTable->setItem(row, 5, new QTableWidgetItem(location));
		ui.sessionTable->setItem(row, 6, new QTableWidgetItem(id));
	}

	ui.sessionTable->setColumnHidden(6, true);

	return 0;
}

Session ViewSessions::get_selected_session()
{
	return selected_session;
}

void ViewSessions::set_selected_session(int r)
{
	TableData *td = TableData::get_instance();
	QTableWidgetItem *t = ui.sessionTable->item(r, 6);

    selected_session = td->find_session(t->text().toStdString());
}

void ViewSessions::on_detailsButton_clicked()
{
	QTableWidgetItem *t;
	ErrorHandler *er = ErrorHandler::get_instance();
	
	if (get_row_selected() == -1 || get_row_selected() > ui.sessionTable->rowCount())
	{
		return;
	}

	if ((t = ui.sessionTable->item(get_row_selected(), 6)) == 0)
	{
		er->display_error("No session selected");
		return;
	}
	
	set_selected_session(get_row_selected());
	
	DetailedStudySession *ds = new DetailedStudySession;
	ds->show();
	set_row_selected(-1);
}

void ViewSessions::on_createSessionButton_clicked()
{
	CreateNewSession *cs = CreateNewSession::Instance();
	cs->show();
	set_row_selected(-1);
}

void ViewSessions::on_sessionTable_itemClicked()
{
	set_row_selected(ui.sessionTable->currentRow());
}

void ViewSessions::on_refreshButton_clicked()
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	AccountSingleton *ac = AccountSingleton::get_instance();
	int row;

	row = get_row_selected();
	td->get_data();
	populate_table();

	if (row > -1 && row <= ui.sessionTable->rowCount())
	{
		ui.sessionTable->selectRow(row);
	}
	else
	{
		ui.sessionTable->clearSelection();
	}
	
}

void ViewSessions::set_row_selected(int r)
{
	row_selected = r;
}