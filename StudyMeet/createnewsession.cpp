#include "createnewsession.h"
#include "Session.h"
#include "ErrorHandler.h"
#include "DatabaseHandler.h"
#include "AccountSingleton.h"
#include "TableData.h"
#include <ctime>

CreateNewSession* CreateNewSession::instance = NULL;

CreateNewSession::CreateNewSession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	subjectBox->addItem(tr("N/A"));
	subjectBox->addItem(tr("Math"));
	subjectBox->addItem(tr("English"));
	subjectBox->addItem(tr("History"));
	subjectBox->addItem(tr("Chemistry"));
	subjectBox->addItem(tr("Computer Science"));
	subjectBox->addItem(tr("Political Science"));
}

CreateNewSession::~CreateNewSession()
{

}

CreateNewSession* CreateNewSession::Instance()
{
	if (instance == NULL)
		instance = new CreateNewSession();

	instance->clear_fields();
	return instance; 
}

void CreateNewSession::clear_fields()
{
	//SubjectEntry->clear();
	//subjectBox->clear();
	timeStartEdit->clear();
	timeEndEdit->clear();
	dateEdit->setDate(QDate::currentDate());
	LocationEdit->clear();
	//sizeOfSessionEdit->clear();
	//numberBox->clear();
	DesciptionEdit->clear();
}

void CreateNewSession::on_CancelButton_clicked()
{
	close();
}
void CreateNewSession::on_PublishSessionButton_clicked()
{
	string subject, timeStart, timeEnd, date, description, location; 
	ErrorHandler *er;
	DatabaseHandler *db;
	AccountSingleton *loggedIn; 
	TableData *td;
	int sessionid;
	int host;
	int session_size;
	string sessionid_string;

	db = DatabaseHandler::get_instance();
	er = ErrorHandler::get_instance();
	loggedIn = AccountSingleton::get_instance();
	td = TableData::get_instance();

	// Grab GUI text field entries
	//subject = SubjectEntry->text().toStdString();
	subject = subjectBox->currentText().toStdString();
	timeStart = timeStartEdit->text().toStdString();
	timeEnd = timeEndEdit->text().toStdString();
	date = (dateEdit->date().toString("MM/dd/yyyy")).toStdString();
	description = DesciptionEdit->toPlainText().toStdString();
	location = LocationEdit->text().toStdString();
	//session_size = sizeOfSessionEdit->text().toInt();
	session_size = numberBox->text().toInt();
	host = loggedIn->get_account().get_accountID();
	
	// Create a sessionID
	srand(time(NULL));
	sessionid = rand() % 10000;
	while (db->validate_session(sessionid) == 0)
		sessionid = rand() % 10000;

	sessionid_string = to_string(sessionid);

	Session sess(sessionid_string, host, timeStart, 1, timeEnd, date, subject, location, session_size, description);

	td->add_to_list(sess);
	if (db->add_to_database(sess) == 0)
		close();
}