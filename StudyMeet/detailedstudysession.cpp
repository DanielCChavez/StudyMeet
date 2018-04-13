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
	ViewSessions *vs;
	Session se;
	ErrorHandler *er;

	vs = ViewSessions::Instance();
	se = vs->get_selected_session();
	er = ErrorHandler::get_instance();

	hostEdit->setText(QString::number(se.get_hostId()));
	subjectEdit->setText(QString::fromStdString(se.get_subject()));
	startTimeEdit->setText(QString::fromStdString(se.get_timestart()));
	endTimeEdit->setText(QString::fromStdString(se.get_timeend()));
	dateEdit->setText(QString::fromStdString(se.get_date()));
	locationEdit->setText(QString::fromStdString(se.get_location()));
	sizeEdit->setText(QString::number(se.get_currentNumberOfPeople()));
	limitEdit->setText(QString::number(se.get_limitNumberOfPeople()));
	descriptionEdit->setText(QString::fromStdString(se.get_description()));
}

void DetailedStudySession::on_leaveButton_clicked()
{
	AccountSingleton *account;
	DatabaseHandler *db;
	ViewSessions *vs;
	Session se;
	ErrorHandler *er;
	int check;

	account = AccountSingleton::get_instance();
	db = DatabaseHandler::get_instance();
	vs = ViewSessions::Instance();
	se = vs->get_selected_session();
	er = ErrorHandler::get_instance();
	check = -1;

	check = db->leave_session(account->get_account().get_accountID(),se.get_sessionID(), se.get_hostId());
	
	//grab the current user id of the account 
	//grab the session id of the selected session
	//call the database function to remove the user from the session 
	//function to remove the user from database: leave_session(int accID, string sessID);
	//if leave_session == 1 run the error handler
	if (check == 0) 
	{
		er->display_error("Left the session.");
		close();
	}
	else
	{
		er->display_error("Could not leave the session.");
	}
}

void DetailedStudySession::on_deleteButton_clicked()
{
	DatabaseHandler *db;
	AccountSingleton *account;
	ViewSessions *vs;
	Session se;
	ErrorHandler *er;
	TableData *td;
	int check;


	db = DatabaseHandler::get_instance();
	account = AccountSingleton::get_instance();
	vs = ViewSessions::Instance();
	se = vs->get_selected_session();
	er = ErrorHandler::get_instance();
	td = TableData::get_instance();
	check = -1;


	check = db->remove_session(se);
	
	if (check == 1)
	{
		er->display_error("You are no the host of this session.");
		close();
		return;
	}
	else if (check == 2)
	{
		er->display_error("Could not remove session.");
		close();
		return;
	}
	else
	{
		account->set_sessionID("");
		er->display_error("session succesfully removed");
	}

	close();
	return;
}

void DetailedStudySession::on_joinButton_clicked()
{
	DatabaseHandler *db;
	AccountSingleton *account;
	ViewSessions *vs;
	Session se;
	ErrorHandler *er;
	int check, join;

	db = DatabaseHandler::get_instance();
	account = AccountSingleton::get_instance();
	vs = ViewSessions::Instance();
	se = vs->get_selected_session();
	er = ErrorHandler::get_instance();
	check = -1;
	join = -1;

	join = db->join_session((account->get_account()).get_accountID(), se.get_sessionID());
	
	if (join != 0)
		er->display_error("Error joining.");
	else
		er->display_error("Succesfully joined session.");

	close();
	return;
}
