#ifndef CREATENEWSESSION_H
#define CREATENEWSESSION_H

#include <QWidget>
#include "ui_createnewsession.h"
#include "DatabaseHandler.h"
#include "ErrorHandler.h"
#include "AccountSingleton.h"

class CreateNewSession : public QWidget, public Ui::CreateNewSession
{
	Q_OBJECT

public:
	~CreateNewSession();
	static CreateNewSession* get_instance(); 

protected:
	static CreateNewSession* instance; 

private:
	CreateNewSession(QWidget *parent = 0);
	void clear_fields();
	ErrorHandler *er;
	DatabaseHandler *db;
	AccountSingleton *ac;

public slots: 
	void on_PublishSessionButton_clicked();
	void on_CancelButton_clicked();

};

#endif // CREATENEWSESSION_H
