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

private:
	Ui::ViewSessions ui;
};

#endif // VIEWSESSIONS_H
