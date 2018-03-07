#include "studymeet.h"


StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->connect();
	db->open();
}

StudyMeet::~StudyMeet()
{
	
}

void StudyMeet::on_toDSWButton_clicked()
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	db->connect();
	db->open();


	DetailedStudySession *ds = new DetailedStudySession;
	ds->show();
	this->close();
}