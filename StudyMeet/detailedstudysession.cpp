#include "detailedstudysession.h"

DetailedStudySession::DetailedStudySession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);

	hostEdit->setText("host name here");
	subjectEdit->setText("subject here");
	timeEdit->setText("time goes here");
	locationEdit->setText("location goes here");
	sizeEdit->setText("group size goes here");
	limitEdit->setText("group size limit goes here");
	descriptionEdit->setText("description goes here");
}

DetailedStudySession::~DetailedStudySession()
{

}
