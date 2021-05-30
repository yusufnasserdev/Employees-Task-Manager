#pragma once
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <iostream>
using namespace std;

class SqlInterface
{
private:
	QSqlDatabase db;
	
	
public:
	SqlInterface();
	~SqlInterface();

	virtual void retrieve() = 0;
	virtual void add() = 0;
	virtual void update() = 0;
	virtual void remove() = 0;
};

