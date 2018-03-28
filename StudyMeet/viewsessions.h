#ifndef VIEWSESSIONS_H
#define VIEWSESSIONS_H

#include <QWidget>
#include "ui_viewsessions.h"
#include "Session.h"
#include <QtWidgets\qmainwindow.h>

class ViewSessions : public QWidget
{
	Q_OBJECT

public:
	ViewSessions(QWidget *parent = 0);
	~ViewSessions();
	static ViewSessions*  Instance();
	Session get_selected_session();
	void set_selected_session(QTableWidgetItem* );

public slots:
void on_detailsButton_clicked(Session session);
void on_createSessionButton_clicked();
void on_sessionTable_itemClicked();
private:
	Ui::ViewSessions ui;
	Session selected_session;
protected:
	static ViewSessions * instance; 
};	

#endif // VIEWSESSIONS_H
