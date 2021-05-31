#include "SqlInterface.h"

SqlInterface::SqlInterface()
{	
}

SqlInterface::~SqlInterface()
{
	cout << "indestructor\n";
}

bool SqlInterface::opendb()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("C:/Users/yn653/Desktop/ETM_database.db");
	if (db.open())
	{
		cout << "opened\n";
		return true;
	}
	else
	{
		cout << "not opened\n";
		return false;
	}
}

void SqlInterface::closedb()
{
	cout << "in close function\n";
	db.close();
	db.removeDatabase(QSqlDatabase::defaultConnection);
}
