#include "studymeet.h"
#include "Account.h"
#include "Session.h"
#include "DatabaseHandler.h"
#include "viewsessions.h"
#include "createaccountwindow.h"
#include "login.h"
#include "AccountSingleton.h"
#include "WelcomeWindow.h"

StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	WelcomeWindow *ww = WelcomeWindow::get_instance();
	Login *login_window = Login::get_instance();

	ww->setWindowModality(Qt::WindowModality::ApplicationModal);
	login_window->setWindowModality(Qt::WindowModality::ApplicationModal);
	//ww->show();
	//ww->close();
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

void StudyMeet::on_loggedInAsButton_clicked()
{
	ErrorHandler *err = ErrorHandler::get_instance();
	AccountSingleton *as = AccountSingleton::get_instance();

	QString display = "Fullname: " + QString::fromStdString(as->get_fullname()) + ",\n accountID: " +
		QString::number(as->get_accountID()) + ",\n SessionID: " +
		QString::fromStdString(as->get_sessionID());
	
	err->display_error(display);
}