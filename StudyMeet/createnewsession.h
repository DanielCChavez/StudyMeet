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
};

#endif // CREATENEWSESSION_H
