#include "WelcomeWindow.h"
#include "DatabaseHandler.h"
#include "TableData.h"


WelcomeWindow* WelcomeWindow::instance = 0;

WelcomeWindow::WelcomeWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	DatabaseHandler *db;
	TableData *td;

	ui.infoEdit->clear();
	ui.infoEdit->setText("connecting to database...");
	db->get_instance();
	ui.infoEdit->clear();
	ui.infoEdit->setText("loading sessions...");
	td = TableData::get_instance();

	this->close();
}

WelcomeWindow::~WelcomeWindow()
{

}

WelcomeWindow* WelcomeWindow::get_instance()
{
	if (instance == 0)
		instance = new WelcomeWindow();

	return instance;
}
