#ifndef STUDYMEET_H
#define STUDYMEET_H

#include <QtWidgets/QMainWindow>
#include "detailedstudysession.h"
#include "viewsessions.h"
#include "ui_studymeet.h"

class StudyMeet : public QMainWindow
{
	Q_OBJECT

public:
	StudyMeet(QWidget *parent = 0);
	~StudyMeet();

public slots:
	void on_toDSWButton_clicked();
	void on_toVSWButton_clicked();
	void on_addToSessionsButton_clicked();


private:
	Ui::StudyMeetClass ui;

};

#endif // STUDYMEET_H
