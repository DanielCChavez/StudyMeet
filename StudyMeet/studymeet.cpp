#include "studymeet.h"
#include "Account.h"
#include "Session.h"
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
	std::list<Account> alist;

	Session s("test3", "5", "test2", 5, "test2", "test2", "test2", 5, alist, "test2");
	DatabaseHandler *d = DatabaseHandler::get_instance();
	ErrorHandler e;

	d->connect();


	if (!d->is_open())
		return;
	
	d->add_to_database(s);
}