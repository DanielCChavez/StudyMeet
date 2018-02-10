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

void StudyMeet::on_insertButton_clicked()
{
	//connect to the database
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); //mysql database
	db.setHostName("studymeet.cswura1xfuzk.us-west-1.rds.amazonaws.com"); //endpoint, from AWS instance
	db.setDatabaseName("users");	//database name within the AWS instance, we can have multiple so have
									// to give name of the db we want
	db.setUserName("studymeet");	//each database has an user name and password
	db.setPassword("studymeet");	//to have access to it 
	bool ok = db.open();

	//if DB opened correctly, open a small window that lists all tables 
	//on the DB, currently only 1 table should show: "test_pet"
	if (ok)
	{
		QTextEdit *text = new QTextEdit();	//the window
		QStringList tables = db.tables();	//list of all tables ont he db
		
		//add each table to the QStringList
		for (auto& a : tables)
		{
			text->append(a);
		}
		text->show();
	}
	else //something went wrong, display error message in new window
	{
		QTextEdit *text = new QTextEdit();
		text->setText(db.lastError().text());
		text->show();
	}
	
	//get information from the user (from UI text fields)
	QString pet_name = ui.petName->text(); //each text field has a unique name
	QString pet_age = ui.petAge->text();
	int age = pet_age.toInt();

	//creating the sql query that inserts into the DB
	QSqlQuery query(db);

	//the test_pet table has only two columns, name and age_dog
	query.prepare("INSERT INTO test_pet (name, age_dog) "
					"values (?, ?)");	//the (?, ?) syntax is used to grab the values
										//from somewhere else and put into the query
	query.addBindValue(pet_name);
	query.addBindValue(age);
	
	if(!query.exec())	//query did not execute correctly, display error message
	{
		QTextEdit *text = new QTextEdit();
		text->setText(query.lastError().text());
		text->show();
	}

	//display all entries in test_pet
	if (!query.exec("select * from test_pet"))
	{
		QTextEdit *text = new QTextEdit();
		text->setText(query.lastError().text());
		text->show();
	}
	// qt can only hand 1 record at a time, so loop through all results
	// from previous query and display 
	QTextEdit *text = new QTextEdit();
	while (query.next())
	{	
		text->append(query.value(0).toString() + "\t");
		text->moveCursor(QTextCursor::End);
		text->insertPlainText(query.value(1).toString());
	}
	text->show();

	db.close();
	db.removeDatabase("QMYSQL");
}
