#include "viewsessions.h"
#include "Session.h"
#include "detailedstudysession.h"
#include "createnewsession.h"
#include <iterator>
#include <QTimer>

ViewSessions* ViewSessions::instance = NULL;

ViewSessions::ViewSessions(QWidget *parent)
	: QWidget(parent)
{
	er = ErrorHandler::get_instance();
	db = DatabaseHandler::get_instance();
	ac = AccountSingleton::get_instance();
	td = TableData::get_instance();
	hid = 0;
	row_selected = -1;

	QStringList titles;
	titles << "Host" << "Subject" << "Start time" <<"End time" << "Date" << "Location";

	QString timeStart, timeEnd, date, subject, id, location;
	int row;
	list<Session>::iterator it; 


	ui.filterByComboBox->addItem(tr("All"));
	ui.filterByComboBox->addItem(tr("History"));
	ui.filterByComboBox->addItem(tr("Chemistry"));
	ui.filterByComboBox->addItem(tr("Math"));
	ui.filterByComboBox->addItem(tr("Computer Science"));
	ui.filterByComboBox->addItem(tr("English"));

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
	QString timeStart, timeEnd, date, subject, id, location, name, filter;
	int row;
	list<Session>::iterator it;
	QStringList titles;
	Account temp;
	int result;

	td = TableData::get_instance();
	db = DatabaseHandler::get_instance();

	titles << "Host" << "Subject" << "Start time" << "End time" << "Date" << "Location";
	
	ui.sessionTable->setHorizontalHeaderLabels(titles);
	ui.sessionTable->clearContents();
	ui.sessionTable->setRowCount(0);
	

	for (it = td->listSessions.begin(); it != td->listSessions.end(); it++)
	{
		filter = ui.filterByComboBox->currentText();
		
		if (filter != "All" && it->get_subject() != filter.toStdString())
		{
			continue;
		}

		result = db->get_account(it->get_hostId(), temp);
		
		ui.sessionTable->insertRow(ui.sessionTable->rowCount());
		timeStart = QString::fromStdString(it->get_timestart());
		timeEnd = QString::fromStdString(it->get_timeend());
		date = QString::fromStdString(it->get_date());
		subject = QString::fromStdString(it->get_subject());
		id = QString::number(it->get_hostId());
		name = QString::fromStdString((temp.get_fullName()));
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
	QTableWidgetItem *t = ui.sessionTable->item(r, 6);

    selected_session = td->find_session(t->text().toStdString());
}

void ViewSessions::on_detailsButton_clicked()
{
	QTableWidgetItem *t;
	
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
	int row, amt_before, amt_after, difference;

	amt_before = td->amount_of_sessions();
	td->get_data();
	populate_table();
	amt_after = td->amount_of_sessions();

	difference = amt_after - amt_before;

	// A session was deleted
	if (difference < 0)
	{
		// Dont decrement if first row is selected
		if (row_selected > 0)
			--row_selected;
	}
	// A session was added
	else if (difference > 0)
	{
		// Dont increment if last row is selected
		if (row_selected != ui.sessionTable->rowCount())
			++row_selected;
	}
	
	if (row_selected > -1 && row_selected <= ui.sessionTable->rowCount())
	{
		ui.sessionTable->selectRow(row_selected);
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