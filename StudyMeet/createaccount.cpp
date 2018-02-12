#include "createaccount.h"

CreateAccount::CreateAccount(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

CreateAccount::~CreateAccount()
{

}

void CreateAccount::on_enterButton_clicked()
{
	QString username = emailEdit->text();
	QString password = passwordEdit->text();
	QByteArray hpassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha1);
	QString hstring(hpassword.toHex());

	if (!username.isEmpty() && !hstring.isEmpty())
	{
		add_account(username, hstring);
	}
	close();
}

void CreateAccount::add_account(QString user, QString pw)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("studymeet.cswura1xfuzk.us-west-1.rds.amazonaws.com");
	db.setDatabaseName("users");
	db.setUserName("studymeet");
	db.setPassword("studymeet");

	if (db.open())
	{
		QSqlQuery query(db);
		query.prepare("INSERT INTO users (username, password_hash) "
			"VALUES (?, ?)");
		query.addBindValue(user);
		query.addBindValue(pw);

		if (!query.exec())
		{
			QMessageBox box;
			box.setWindowTitle("Error");
			box.setText(query.lastError().text());
			box.setStandardButtons(QMessageBox::Ok);
			box.exec();
		}
	}
	db.close();
	db.removeDatabase("QMYSQL");
}