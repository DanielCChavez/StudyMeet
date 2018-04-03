#include "createnewsession.h"
#include "Session.h"
#include "ErrorHandler.h"
#include "DatabaseHandler.h"
#include "AccountSingleton.h"
#include <ctime>

CreateNewSession* CreateNewSession::instance = NULL;

CreateNewSession::CreateNewSession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

CreateNewSession::~CreateNewSession()
{

}

CreateNewSession * CreateNewSession::Instance()
{
	if (instance == NULL)
		instance = new CreateNewSession();

	return instance; 
}

void CreateNewSession::on_PublishSessionButton_clicked()
{
	
	string subject, timeStart, timeEnd, date, description, location; 
	ErrorHandler *er;
	DatabaseHandler * db;
	AccountSingleton * loggedIn; 
	int sessionid;
	int host;
	int session_size;
	string sessionid_string;

	db = DatabaseHandler::get_instance();
	er = ErrorHandler::get_instance();
	loggedIn = AccountSingleton::get_instance();

	subject = SubjectEntry->text().toStdString();
	timeStart = timeStartEdit->text().toStdString();
	timeEnd = timeEndEdit->text().toStdString();
	date = (dateEdit->date().toString("MM/dd/yyyy")).toStdString();
	description = DesciptionEdit->toPlainText().toStdString();
	location = LocationEdit->text().toStdString();
	session_size = sizeOfSessionEdit->text().toInt();
	host = loggedIn->get_account().get_accountID();
	
	er->display_error(dateEdit->date().toString());


	srand(time(NULL));
	sessionid = rand() % 10000;
	while (db->validate_session(sessionid) == 0)
		sessionid = rand() % 10000;

	sessionid_string = to_string(sessionid);

	Session sess(sessionid_string, host, timeStart, 1, timeEnd, date, subject, location, session_size, description);

	if (db->add_to_database(sess) == 0)
		close();
}