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
	static CreateAccountWindow* Instance();
	//account.name = 
	//create account button
	//db.add_to_database(Acc)
protected:
	static CreateAccountWindow* instance; 
};

#endif // CREATEACCOUNTWINDOW_H
