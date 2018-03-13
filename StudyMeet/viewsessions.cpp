#include "viewsessions.h"

ViewSessions* ViewSessions::instance = NULL;

ViewSessions::ViewSessions(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}


ViewSessions::~ViewSessions()
{
	
}

ViewSessions* ViewSessions::Instance()
{
	if (instance == NULL)
		instance = new ViewSessions();
	else
		return instance; 
}

