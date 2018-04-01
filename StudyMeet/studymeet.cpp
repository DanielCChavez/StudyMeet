#include "studymeet.h"
#include "Account.h"
#include "Session.h"
#include "DatabaseHandler.h"
#include "viewsessions.h"
#include "createaccountwindow.h"
#include "login.h"
#include "AccountSingleton.h"

StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Login *login_window = Login::get_instance();
	login_window->setWindowModality(Qt::WindowModality::ApplicationModal);
	login_window->show();
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

void StudyMeet::on_loggedInAsButton_clicked()
{
	ErrorHandler *err = ErrorHandler::get_instance();
	AccountSingleton *as = AccountSingleton::get_instance();
	Account acc = as->get_account();

	QString display = QString::fromStdString(acc.get_username()) + " " + QString::fromStdString(acc.get_password());
	err->display_error(display);
}