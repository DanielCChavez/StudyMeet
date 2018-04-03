#include "detailedstudysession.h"
#include "viewsessions.h"

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
