#include "createnewsession.h"

CreateNewSession* CreateNewSession::instance = NULL;

CreateNewSession::CreateNewSession(QWidget *parent)
	: QWidget(parent)
{
	setupUi(this);
}

CreateNewSession::~CreateNewSession()
{

}

CreateNewSession * CreateNewSession::Instance()
{
	if (instance == NULL)
		instance = new CreateNewSession();

	return instance; 
}
