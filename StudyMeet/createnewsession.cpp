#include "createnewsession.h"
#include "Session.h"
#include <ctime>

CreateNewSession* CreateNewSession::instance = NULL;

CreateNewSession::CreateNewSession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	er = ErrorHandler::get_instance();
	db = DatabaseHandler::get_instance();
	ac = AccountSingleton::get_instance();

	subjectBox->addItem(tr("N/A"));
	subjectBox->addItem(tr("Math"));
	subjectBox->addItem(tr("English"));
	subjectBox->addItem(tr("History"));
	subjectBox->addItem(tr("Chemistry"));
	subjectBox->addItem(tr("Computer Science"));
	subjectBox->addItem(tr("Political Science"));
	subjectBox->addItem(tr("Philosophy"));
	subjectBox->addItem(tr("Physics"));
	subjectBox->addItem(tr("Biology"));
	subjectBox->addItem(tr("Engineering"));
	subjectBox->addItem(tr("Business"));
	subjectBox->addItem(tr("Music"));
	subjectBox->addItem(tr("Art"));
	subjectBox->addItem(tr("Astronomy"));
	subjectBox->addItem(tr("Statistics"));

}

CreateNewSession::~CreateNewSession()
{

}

CreateNewSession* CreateNewSession::get_instance()
{
	if (instance == NULL)
		instance = new CreateNewSession();

	instance->clear_fields();
	return instance; 
}

void CreateNewSession::clear_fields()
{
	timeStartEdit->setTime(QTime::currentTime());
	timeEndEdit->setTime(QTime::currentTime().addSecs(3600));
	dateEdit->setDate(QDate::currentDate());
	LocationEdit->clear();
	DesciptionEdit->clear();
}

void CreateNewSession::on_CancelButton_clicked()
{
	close();
}
void CreateNewSession::on_PublishSessionButton_clicked()
{
	string subject, timeStart, timeEnd, date, description, location; 
	int sessionid, host, session_size, result;
	string sessionid_string;


	// Grab GUI text field entries
	subject = subjectBox->currentText().toStdString();
	timeStart = timeStartEdit->text().toStdString();
	timeEnd = timeEndEdit->text().toStdString();
	date = (dateEdit->date().toString("MM/dd/yyyy")).toStdString();
	description = DesciptionEdit->toPlainText().toStdString();
	location = LocationEdit->text().toStdString();
	session_size = numberBox->text().toInt();
	host = ac->get_accountID();
	
	// Create a sessionID
	srand(time(NULL));
	sessionid = rand() % 10000;
	while (db->validate_session(sessionid) == 0)
		sessionid = rand() % 10000;

	sessionid_string = to_string(sessionid);
	Session sess(sessionid_string, host, timeStart, 1, timeEnd, date, 
		subject, location, session_size, description);

	result = db->add_to_database(sess);
	if (result == 0) { close(); return; }
	if (result == 1) { er->display_error("Error with database."); return; }
	if (result == 2) { er->display_error("You are already in a session."); return; }
	if (result == 3) { er->display_error("Error with database."); return; }

	return;
}