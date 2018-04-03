#include "TableData.h"


Session TableData::find_session(string s)
{
	for (list<Session>::iterator it = listSessions.begin(); it != listSessions.end(); it++)
	{
		if (s == to_string(it->get_hostId()))
		{
			ErrorHandler * err = ErrorHandler::get_instance();
			err->display_error(QString::fromStdString((*it).get_location()));
			return *it;
		}
	}
	Session se("ERRORID", -1, "ERRORTIMESTART", -1, "ERRORTIMEEND","ERRORDATE", "ERRORSUBJECT", "ERRORLOCATION", 
		-1, "ERROR DESCRIPTION");
	return se;
}

TableData::TableData()
{
	DatabaseHandler* handler = DatabaseHandler::get_instance();
	handler->load_all_sessions(listSessions);
}


/*
int TableData::fill_session_table(ViewSessions* vs, TableData* t)
{
	list<Session>::iterator it;
	DatabaseHandler *db;
	QString timeStart;
	QString timeEnd;
	QString date;
	QString subject;
	QString id;
	QString location;
	int row;

	//listSessions.clear();

	db->DatabaseHandler::get_instance();

	db->load_all_sessions(listSessions);

	for (it = listSessions.begin(); it != listSessions.end(); it++)
	{
		vs->get_ui().sessionTable->insertRow(vs->get_ui().sessionTable->rowCount());
		timeStart = QString::fromStdString(it->get_timestart());
		timeEnd = QString::fromStdString(it->get_timeend());
		date = QString::fromStdString(it->get_date());
		subject = QString::fromStdString(it->get_subject());
		id = QString::number(it->get_hostId());
		location = QString::fromStdString(it->get_location());

		row = vs->get_ui().sessionTable->rowCount() - 1;
		vs->get_ui().sessionTable->setItem(row, 2, new QTableWidgetItem(timeStart));
		vs->get_ui().sessionTable->setItem(row, 1, new QTableWidgetItem(subject));
		vs->get_ui().sessionTable->setItem(row, 0, new QTableWidgetItem(id));
		vs->get_ui().sessionTable->setItem(row, 3, new QTableWidgetItem(timeEnd));
		vs->get_ui().sessionTable->setItem(row, 4, new QTableWidgetItem(date));
		vs->get_ui().sessionTable->setItem(row, 5, new QTableWidgetItem(location));
	}
	return 0;
}

*/
TableData::~TableData()
{
}

