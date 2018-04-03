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
	Ui::ViewSessions get_ui() const { return ui; }

public slots:
void on_detailsButton_clicked(Session session);
void on_createSessionButton_clicked();
void on_sessionTable_itemClicked();
void on_refreshButton_clicked();
private:
	Ui::ViewSessions ui;
	Session selected_session;
	TableData *td;
protected:
	static ViewSessions * instance; 
};	

#endif // VIEWSESSIONS_H
