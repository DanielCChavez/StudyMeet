#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include "ui_createaccount.h"

class CreateAccount : public QDialog, public Ui::CreateAccount
{
	Q_OBJECT

public:
	CreateAccount(QWidget *parent = 0);
	~CreateAccount();
};

#endif // CREATEACCOUNT_H
