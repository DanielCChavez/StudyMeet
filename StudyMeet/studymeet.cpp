#include "studymeet.h"
#include "dialog.h"
#include "login.h"

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
	ErrorHandler err;
	DatabaseHandler db;

	// Database did not open correctly, leave
	if (!db.open())
		return;

	QTextEdit *text = new QTextEdit();	//the window
	QStringList tables = db.get_db().tables();	//list of all tables ont he db
		
	//add each table to the QStringList
	for (auto& a : tables)
	{
		text->append(a);
	}
	text->show();

	//get information from the user (from UI text fields)
	QString pet_name = ui.petName->text(); //each text field has a unique name
	QString pet_age = ui.petAge->text();
	int age = pet_age.toInt();

	//creating the sql query that inserts into the DB
	QSqlQuery query(db.get_db());

	//the test_pet table has only two columns, name and age_dog
	query.prepare("INSERT INTO test_pet (name, age_dog) "
					"values (?, ?)");	//the (?, ?) syntax is used to grab the values
										//from somewhere else and put into the query
	query.addBindValue(pet_name);
	query.addBindValue(age);
	
	//query did not execute correctly, display error message
	if(!query.exec())
		err.display_error(query.lastError().text());


	//display all entries in test_pet
	if (!query.exec("select * from test_pet"))
		err.display_error(query.lastError().text());

	// qt can only hand 1 record at a time, so loop through all results
	// from previous query and display 
	QTextEdit *text_window = new QTextEdit();
	while (query.next())
	{	
		text_window->append(query.value(0).toString() + "\t");
		text_window->moveCursor(QTextCursor::End);
		text_window->insertPlainText(query.value(1).toString());
	}
	text_window->show();
}

// When "Get Started" button clicked, open up the Login UI
void StudyMeet::on_getStartedButton_clicked()
{
	Login login(this);
	login.exec();
}