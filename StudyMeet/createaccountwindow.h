#ifndef CREATEACCOUNTWINDOW_H
#define CREATEACCOUNTWINDOW_H

#include <QWidget>
#include "ui_createaccountwindow.h"

class CreateAccountWindow : public QWidget, public Ui::CreateAccountWindow
{
	Q_OBJECT

public:
	CreateAccountWindow(QWidget *parent = 0);
	~CreateAccountWindow();

	//account.name = 
	//create account button
	//db.add_to_database(Acc)
};

#endif // CREATEACCOUNTWINDOW_H
