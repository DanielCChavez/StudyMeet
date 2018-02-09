#ifndef DIALOG_H
#define DIALOG_H

//#include <QDialog>
#include "ui_dialog.h"

class Dialog : public QDialog, public Ui::Dialog
{
	Q_OBJECT

public:
	Dialog(QWidget *parent = 0);
	~Dialog();
};

#endif // DIALOG_H
