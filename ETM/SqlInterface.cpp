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
		//cout << "DB is open\n";
		return true;
	}
	else
	{
		//cout << "DB is NOT open\n";
		return false;
	}
}

void SqlInterface::closedb()
{
	//cout << "DB Closed\n";
	db.close();
	db.removeDatabase(QSqlDatabase::defaultConnection);
}
