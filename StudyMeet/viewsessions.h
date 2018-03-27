#ifndef VIEWSESSIONS_H
#define VIEWSESSIONS_H

#include <QWidget>
#include "ui_viewsessions.h"

class ViewSessions : public QWidget
{
	Q_OBJECT

public:
	ViewSessions(QWidget *parent = 0);
	~ViewSessions();
	static ViewSessions*  Instance();
public slots:
void on_detailsButton_clicked();
void on_createSessionButton_clicked();

private:
	Ui::ViewSessions ui;
protected:
	static ViewSessions * instance; 
};	

#endif // VIEWSESSIONS_H
