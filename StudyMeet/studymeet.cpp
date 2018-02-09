#include "studymeet.h"
#include "dialog.h"

StudyMeet::StudyMeet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

StudyMeet::~StudyMeet()
{

}

void StudyMeet::on_heyButton_clicked()
{
	Dialog dia(this);
	dia.exec();
}
