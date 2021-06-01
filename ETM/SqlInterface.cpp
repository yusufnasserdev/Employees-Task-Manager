#include "SqlInterface.h"

SqlInterface::SqlInterface()
{	
}

SqlInterface::~SqlInterface()
{
}

bool SqlInterface::opendb()
{
	
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("../Database/ETM_database.db");
	if (db.open())
	{
		cout << "is opened\n";
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
