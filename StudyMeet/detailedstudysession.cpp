#include "detailedstudysession.h"
#include "viewsessions.h"
#include "ErrorHandler.h"
#include "DatabaseHandler.h"
#include "AccountSingleton.h"
#include "viewsessions.h"
#include "TableData.h"

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

	ErrorHandler *er = ErrorHandler::get_instance();
	//er->display_error(QString::fromStdString(se.get_description()));

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

	check = db->leave_session(account->get_account().get_accountID(),se.get_sessionID());
	//grab the current user id of the account 
	//grab the session id of the selected session
	//call the database function to remove the user from the session 
	//function to remove the user from database: leave_session(int accID, string sessID);
	
	//if leave_session == 1 run the error handler
	if (check == 0) {
		er->display_error("left the session");
		close();
	}
	else
	{
		er->display_error("could not leave the session");
	}
}

void DetailedStudySession::on_deleteButton_clicked()
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	AccountSingleton *account = AccountSingleton::get_instance();
	ViewSessions *vs = ViewSessions::Instance();
	Session se = vs->get_selected_session();
	ErrorHandler *er = ErrorHandler::get_instance();
	TableData *td = TableData::get_instance();
	int check;

	check = db->remove_session(se);
	if (check == 1)
	{
		er->display_error("you are not the host of this session");
		return;
	}
	else if (check == 2)
	{
		er->display_error("could not remove session");
		return;
	}
	else
	{
		td->remove_from_list(se.get_sessionID());
		er->display_error("session succesfully removed");
	}
	return;
}

void DetailedStudySession::on_joinButton_clicked()
{
	DatabaseHandler *db = DatabaseHandler::get_instance();
	AccountSingleton *account = AccountSingleton::get_instance();
	ViewSessions *vs = ViewSessions::Instance();
	Session se = vs->get_selected_session();
	ErrorHandler *er = ErrorHandler::get_instance();
	int check, join;

	//check if account is already in a session
	//check = db->validate_session(stoi((account->get_account()).get_accountID()));
	//if(check == 1)
	//{
	//	er->display_error("already in a session");
		//return;
	//}

	er->display_error(QString::number((account->get_account().get_accountID())));
	er->display_error(QString::fromStdString(se.get_sessionID()));

	join = db->join_session((account->get_account()).get_accountID(), se.get_sessionID());
	if (join == 1)
		er->display_error("first ");
	else if (join == 2)
		er->display_error("second");
	else if (join == 3)
		er->display_error("third");
	else
		er->display_error("succesfully joined session");
	return;
}
