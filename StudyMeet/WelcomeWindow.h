#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>
#include "ui_WelcomeWindow.h"

class WelcomeWindow : public QWidget
{
	Q_OBJECT

public:
	~WelcomeWindow();
	static WelcomeWindow* get_instance();
private:
	WelcomeWindow(QWidget *parent = 0);
	Ui::WelcomeWindow ui;
protected:
	static WelcomeWindow* instance;
};

#endif // WELCOMEWINDOW_H
