#ifndef VIEWSESSIONS_H
#define VIEWSESSIONS_H

#include <QWidget>
#include "ui_viewsessions.h"
#include "Session.h"
#include "TableData.h"
#include <QtWidgets\qmainwindow.h>
#include <QMenu>
#include "DatabaseHandler.h"
#include "ErrorHandler.h"

class ViewSessions : public QWidget
{
	Q_OBJECT

public:
	~ViewSessions();
	static ViewSessions*  get_instance();
	Session get_selected_session();
	int populate_table();
	int get_row_selected() const { return row_selected; }
	int get_hid() const { return hid; }
	void set_hid(int);
	void set_selected_session(int);
	void set_row_selected(int);

public slots:
	void on_detailsButton_clicked();
	void on_createSessionButton_clicked();
	void on_sessionTable_itemClicked();
	void on_sessionTable_doubleClicked();
	void on_refreshButton_clicked(bool = false);
	void force_refresh();
	void on_logoutButton_clicked();
	void showContextMenu(const QPoint& p);
	void on_mySessionButton_clicked();
private:
	ViewSessions(QWidget *parent = 0);
	Ui::ViewSessions ui;
	Session selected_session;
	int hid;
	int row_selected;
	DatabaseHandler *db;
	ErrorHandler *er;
	AccountSingleton *ac;
	TableData *td;
	QMenu context;
	QDateTime last_updated;
protected:
	static ViewSessions *instance; 
};	

#endif // VIEWSESSIONS_H
