#include "createaccountwindow.h"

CreateAccountWindow* CreateAccountWindow::instance = NULL;

CreateAccountWindow::CreateAccountWindow(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

CreateAccountWindow::~CreateAccountWindow()
{

}

CreateAccountWindow * CreateAccountWindow::Instance()
{
	if (instance == NULL)
		instance = new CreateAccountWindow();

	return instance;
}
