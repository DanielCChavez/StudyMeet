#ifndef STUDYMEET_H
#define STUDYMEET_H

#include <QtWidgets/QMainWindow>
#include <QtSql>
//#include <QtSql/qsqldatabase.h>
//#include <qsqlerror.h>
#include <QTextEdit>
//#include <qtextedit.h>

#include "ui_studymeet.h"

class StudyMeet : public QMainWindow
{
	Q_OBJECT

public:
	StudyMeet(QWidget *parent = 0);
	~StudyMeet();

public slots:
	void on_heyButton_clicked();
	void on_insertButton_clicked();
	void on_getStartedButton_clicked();

private:
	Ui::StudyMeetClass ui;

};

#endif // STUDYMEET_H
