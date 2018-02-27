#ifndef DETAILEDSTUDYSESSION_H
#define DETAILEDSTUDYSESSION_H

#include <QWidget>
#include "ui_detailedstudysession.h"

class DetailedStudySession : public QWidget, public Ui::DetailedStudySession
{
	Q_OBJECT

public:
	DetailedStudySession(QWidget *parent = 0);
	~DetailedStudySession();
};

#endif // DETAILEDSTUDYSESSION_H
