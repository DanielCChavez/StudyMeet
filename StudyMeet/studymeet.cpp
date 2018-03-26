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
