#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include <QCryptographicHash>
#include "ui_createaccount.h"
#include <QtSql>
#include <QMessageBox>

class CreateAccount : public QDialog, public Ui::CreateAccount
{
	Q_OBJECT

public:
	CreateAccount(QWidget *parent = 0);
	~CreateAccount();

public slots:
	void on_enterButton_clicked();

private:
	void add_account(QString, QString);
};

#endif // CREATEACCOUNT_H
