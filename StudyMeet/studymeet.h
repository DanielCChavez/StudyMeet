#ifndef STUDYMEET_H
#define STUDYMEET_H

#include <QtWidgets/QMainWindow>
#include "ui_studymeet.h"

class StudyMeet : public QMainWindow
{
	Q_OBJECT

public:
	StudyMeet(QWidget *parent = 0);
	~StudyMeet();

public slots:
	void on_heyButton_clicked();
	//id on_exitButton_clicked();

private:
	Ui::StudyMeetClass ui;

};

#endif // STUDYMEET_H
