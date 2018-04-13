#ifndef VIEWSESSIONS_H
#define VIEWSESSIONS_H

#include <QWidget>
#include "ui_viewsessions.h"
#include "Session.h"
#include "TableData.h"
#include <QtWidgets\qmainwindow.h>

class ViewSessions : public QWidget
{
	Q_OBJECT

public:
	ViewSessions(QWidget *parent = 0);
	~ViewSessions();
	static ViewSessions*  Instance();
	Session get_selected_session();
	void set_selected_session(int);
	int populate_table();
	void set_hid(int);
	int get_hid() const { return hid; }

	void set_row_selected(int);
	int get_row_selected() const { return row_selected; }
	TableData *td;

public slots:
	void on_detailsButton_clicked();
	void on_createSessionButton_clicked();
	void on_sessionTable_itemClicked();
	void on_refreshButton_clicked();
private:
	Ui::ViewSessions ui;
	Session selected_session;
	int hid;
	int row_selected;
protected:
	static ViewSessions * instance; 
};	

#endif // VIEWSESSIONS_H
