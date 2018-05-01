#ifndef DETAILEDSTUDYSESSION_H
#define DETAILEDSTUDYSESSION_H

#include <QWidget>
#include "ui_detailedstudysession.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h"
#include "AccountSingleton.h"
#include "viewsessions.h"

class DetailedStudySession : public QWidget, public Ui::DetailedStudySession
{
	Q_OBJECT

public:
	static DetailedStudySession* get_instance();
	~DetailedStudySession();
	void populate_fields();
protected:
	static DetailedStudySession *instance;
private:
	DetailedStudySession(QWidget *parent = 0);
	DatabaseHandler *db;
	ErrorHandler *er;
	AccountSingleton *ac;
	ViewSessions *vs;
public slots :
	void on_leaveButton_clicked();
	void on_deleteButton_clicked();
	void on_joinButton_clicked();


};

#endif // DETAILEDSTUDYSESSION_H
