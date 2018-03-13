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
};

#endif // CREATENEWSESSION_H
