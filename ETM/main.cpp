#include "ETM.h"
#include <QtWidgets/QApplication>
#include "SignUp.h"
#include "globalVariables.h"

bool isShown = false, isClosed = false;

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

void opendb()
{
	db.setDatabaseName("../Database/ETM_database.db");
	db.open();
}

void closedb()
{
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
