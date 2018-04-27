#include "studymeet.h"
#include <QtWidgets/QApplication>
#include "AccountSingleton.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	StudyMeet w;

	//w.show();

	int r = a.exec();

	AccountSingleton *ac = AccountSingleton::get_instance();
	ac->log_off();
	return r;
}
