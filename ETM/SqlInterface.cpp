#include "SqlInterface.h"

SqlInterface::SqlInterface()
{
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("$(SolutionDir)Database\ETM_database.db");
	if (db.open()) 
	{
		cout << "opened\n";
	}
	else 
	{
		cout << "not opened\n";
	}
		
}

SqlInterface::~SqlInterface()
{
	cout << "dbjlsddsvddf\n";
	db.close();
}
