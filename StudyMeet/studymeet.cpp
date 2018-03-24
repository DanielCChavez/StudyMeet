#include "studymeet.h"
#include "Account.h"
#include "Session.h"
#include "DatabaseHandler.h"
#include "viewsessions.h"

StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

StudyMeet::~StudyMeet()
{

}

void StudyMeet::on_toVSWButton_clicked()
{
	ViewSessions *vs = ViewSessions::Instance();
	vs->show();
	this->close();
}

void StudyMeet::on_toDSWButton_clicked()
{
	DetailedStudySession *ds = DetailedStudySession::Instance();
	ds->show();
	this->close();
}

void StudyMeet::on_addToSessionsButton_clicked()
{
	DatabaseHandler *d = DatabaseHandler::get_instance();

	Session s("test5", 5, "test2", 5, "test2", "test2", "test2", 5, "test2");
	Account a("test2", "test1");

	if (d->get_connection_status() == 0)
		return;

	d->add_to_database(s);
	d->add_to_database(a);
}