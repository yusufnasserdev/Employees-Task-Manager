#include "ETM.h"
#include <QtWidgets/QApplication>
#include "SignUp.h"
#include "globalVariables.h"

bool isShown = false, isClosed = false;

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

void opendb()
{
	db.setDatabaseName("../Database/ETM_database.db");
	if (db.open())
	{
		cout << "DB is open\n";
	}
	else
	{
		cout << "DB is NOT open\n";
	}
}

void closedb()
{
	cout << "DB Closed\n";
	db.close();
	db.removeDatabase(QSqlDatabase::defaultConnection);
}

int main(int argc, char* argv[])
{
	opendb();
	QApplication a(argc, argv);
	ETM w;
	w.show();
	return a.exec();
	closedb();
}
