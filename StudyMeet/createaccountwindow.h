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
	//static CreateAccountWindow* Instance();
protected:
	//static CreateAccountWindow* instance; 
private:
	
public slots:
	void on_createAccountButton_clicked();
};

#endif // CREATEACCOUNTWINDOW_H
