#ifndef CREATENEWSESSION_H
#define CREATENEWSESSION_H

#include <QWidget>
#include "ui_createnewsession.h"

class CreateNewSession : public QWidget, public Ui::CreateNewSession
{
	Q_OBJECT

public:
	CreateNewSession(QWidget *parent = 0);
	~CreateNewSession();
	static CreateNewSession* Instance(); 

protected:
	static CreateNewSession* instance; 

private:
	void clear_fields();

public slots: 
	void on_PublishSessionButton_clicked();
	void on_CancelButton_clicked();

};

#endif // CREATENEWSESSION_H
