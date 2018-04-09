#include "detailedstudysession.h"
#include "viewsessions.h"
#include "ErrorHandler.h"
#include "DatabaseHandler.h"
#include "AccountSingleton.h"
DetailedStudySession::DetailedStudySession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	populate_fields();
}

DetailedStudySession::~DetailedStudySession()
{

}

void DetailedStudySession::populate_fields()
{
	ViewSessions *vs = ViewSessions::Instance();
	Session se = vs->get_selected_session();

	hostEdit->setText(QString::number(se.get_hostId()));
	subjectEdit->setText(QString::fromStdString(se.get_subject()));
	startTimeEdit->setText(QString::fromStdString(se.get_timestart()));
	endTimeEdit->setText(QString::fromStdString(se.get_timeend()));
	dateEdit->setText(QString::fromStdString(se.get_date()));
	locationEdit->setText(QString::fromStdString(se.get_location()));
	sizeEdit->setText(QString::number(se.get_currentnumberofpeopleinsession()));
	limitEdit->setText(QString::number(se.get_maximumcapacityofpeopleinsession()));
	descriptionEdit->setText(QString::fromStdString(se.get_description()));
}

void DetailedStudySession::on_leaveButton_clicked()
{
	AccountSingleton * account = AccountSingleton::get_instance();
	DatabaseHandler * db = DatabaseHandler::get_instance();
	ViewSessions * vs = ViewSessions::Instance();
	Session se = vs->get_selected_session();
	ErrorHandler * er = ErrorHandler::get_instance();
	int check;

	check = db->leave_session(account->get_accountID(),se.get_sessionID());
	//grab the current user id of the account 
	//grab the session id of the selected session
	//call the database function to remove the user from the session 
	//function to remove the user from database: leave_session(int accID, string sessID);
	
	//if leave_session == 1 run the error handler
	if (check == 1) {
		er->display_error("left the session");
	   close();
	}
	else
	{
		er->display_error("could not leave the session");
	}
}