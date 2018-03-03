#ifndef TESTINGGITHUB_H
#define TESTINGGITHUB_H

#include <QWidget>
#include "ui_testinggithub.h"

class testinggithub : public QWidget, public Ui::testinggithub
{
	Q_OBJECT

public:
	testinggithub(QWidget *parent = 0);
	~testinggithub();
};

#endif // TESTINGGITHUB_H
