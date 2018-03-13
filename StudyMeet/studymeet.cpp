#include "studymeet.h"
#include "Account.h"
#include "viewsessions.h"

StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->connect();
	db->is_open();

	Account a;
	DatabaseHandler *d = DatabaseHandler::get_instance();
	d->add_to_database(a);
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
	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->is_open();


	DetailedStudySession *ds = DetailedStudySession::Instance();
	ds->show();
	this->close();
}