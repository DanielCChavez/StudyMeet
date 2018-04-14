#ifndef CREATEACCOUNTWINDOW_H
#define CREATEACCOUNTWINDOW_H

#include <QWidget>
#include "ui_createaccountwindow.h"
#include "ErrorHandler.h"
#include "DatabaseHandler.h"

class CreateAccountWindow : public QWidget, public Ui::CreateAccountWindow
{
	Q_OBJECT

public:
	CreateAccountWindow(QWidget *parent = 0);
	~CreateAccountWindow();

private:
	ErrorHandler *er;
	DatabaseHandler *db;
	
public slots:
	void on_createAccountButton_clicked();
};

#endif // CREATEACCOUNTWINDOW_H
