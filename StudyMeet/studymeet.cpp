#include "studymeet.h"
#include "Account.h"
#include "Session.h"
#include "DatabaseHandler.h"
#include "viewsessions.h"
#include "createaccountwindow.h"

StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	CreateAccountWindow *caw = CreateAccountWindow::Instance();
	caw->setWindowModality(Qt::WindowModality::ApplicationModal);
	caw->show();
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
	DetailedStudySession *ds = new DetailedStudySession;// = DetailedStudySession::Instance();
	ds->show();
	this->close();
}