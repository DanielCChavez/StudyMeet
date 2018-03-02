#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QWidget>
#include "ui_testclass.h"

class testclass : public QWidget, public Ui::testclass
{
	Q_OBJECT

public:
	testclass(QWidget *parent = 0);
	~testclass();
};

#endif // TESTCLASS_H
