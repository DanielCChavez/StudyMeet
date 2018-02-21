#ifndef STUDYMEET_H
#define STUDYMEET_H

#include <QtWidgets/QMainWindow>
#include <QtSql>
#include <QTextEdit>

#include "DatabaseHandler.h"


#include "ui_studymeet.h"

class StudyMeet : public QMainWindow
{
	Q_OBJECT

public:
	StudyMeet(QWidget *parent = 0);
	~StudyMeet();

public slots:


private:
	Ui::StudyMeetClass ui;

};

#endif // STUDYMEET_H
