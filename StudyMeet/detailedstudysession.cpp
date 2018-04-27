#include "detailedstudysession.h"
#include "TableData.h"

DetailedStudySession* DetailedStudySession::instance = NULL;

DetailedStudySession::DetailedStudySession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
	er = ErrorHandler::get_instance();
	db = DatabaseHandler::get_instance();
	ac = AccountSingleton::get_instance();
	vs = ViewSessions::get_instance();
}

DetailedStudySession* DetailedStudySession::get_instance()
{
	if (instance == NULL)
		instance = new DetailedStudySession();


	instance->populate_fields();

	return instance;
}

DetailedStudySession::~DetailedStudySession()
{
	
}

void DetailedStudySession::populate_fields()
{
	Session se;
	se = vs->get_selected_session();

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
	Session se;
	int check;

	se = vs->get_selected_session();
	check = -1;

	//grab the current user id of the account 
	//grab the session id of the selected session
	//call the database function to remove the user from the session 
	//function to remove the user from database: leave_session(int accID, string sessID);
	check = db->leave_session(ac->get_accountID(), se.get_sessionID(), se.get_hostId());
	if (check == 0) { er->display_error("Left the session."); close(); return; }
	if (check == 1) { er->display_error("Error with database."); return; }
	if (check == 2) { er->display_error("You are not in this session."); return; }
	if (check == 3) { er->display_error("You are hosting this session. You cannot leave it."); return; }
}

void DetailedStudySession::on_deleteButton_clicked()
{
	Session se;
	int check;

	se = vs->get_selected_session();
	check = -1;


	check = db->remove_session(se);
	if (check == 1)
	{
		er->display_error("Error with database.");
		return;
	}
	else if (check == 2)
	{
		er->display_error("You are not the host of this session.");
		return;
	}
	else
	{
		ac->set_sessionID("");
		er->display_error("Removed session.");
	}

	close();
	return;
}

void DetailedStudySession::on_joinButton_clicked()
{
	Session se;
	int join;

	se = vs->get_selected_session();
	join = -1;

	join = db->join_session(ac->get_accountID(), se.get_sessionID());
	
	//error checking
	if (join == 0) { close(); return; }
	if (join == 1) { er->display_error("You are alreading in a session."); return; }
	if (join == 2) { er->display_error("Error with database."); return; }
	if (join == 3) { er->display_error("Error with database."); return; }
	if (join == 4) { er->display_error("Session is at it's size limit."); return; }
	if (join == 5) { er->display_error("Session does not exist anymore."); return; }
}
