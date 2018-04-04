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
	ww->show();
	ww->close();
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
	Account acc = as->get_account();

	QString display = QString::fromStdString(acc.get_username()) + ", " +
		QString::fromStdString(acc.get_password()) + ", " +
		QString::fromStdString(acc.get_dateCreated()) + ", " +
		QString::number(acc.get_accountID()) + ", " +
		QString::fromStdString(acc.get_firstName()) + ", " +
		QString::fromStdString(acc.get_firstName()) + ", " +
		QString::fromStdString(acc.get_gradeLevel());
	err->display_error(display);
}