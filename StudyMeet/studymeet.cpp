#include "studymeet.h"


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
	ViewSessions *vs = new ViewSessions;
	vs->show();
	this->close();
}

void StudyMeet::on_toDSWButton_clicked()
{
	DetailedStudySession *ds = new DetailedStudySession;
	ds->show();
	this->close();
}