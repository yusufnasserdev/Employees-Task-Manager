#include "Employee.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <iostream>


Employee::Employee(string firstName, string lastName, string username, string email, string password)
	: m_firstName(firstName), m_lastName(lastName),
	m_username(username), m_email(email), m_password(password)
{
}

Employee::Employee(string username, string password)
	: m_username(username), m_password(password)
{
	retrieve();
	cout << "dvhjd\n";
}

Employee::~Employee()
{
}

void Employee::retrieve()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("select firstName, secondName , email from Employee where username = :m_username");
	qry.bindValue(":m_username", m_username.c_str());
	if (qry.exec()) {
		cout << "exe\n";
		while (qry.next()) {
			m_firstName = qry.value(0).toString().toUtf8().constData();
			m_lastName = qry.value(1).toString().toUtf8().constData();
			m_email = qry.value(2).toString().toUtf8().constData();
		}
	}
	qry.clear();
	closedb();
}

void Employee::add()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("insert into Employee values(:m_username, :m_firstName, :m_lastName, :m_email, :m_password)");
	qry.bindValue(":m_username", m_username.c_str());
	qry.bindValue(":m_firstName", m_firstName.c_str());
	qry.bindValue(":m_lastName", m_lastName.c_str());
	qry.bindValue(":m_email", m_email.c_str());
	qry.bindValue(":m_password", m_password.c_str());
	qry.exec();
	qry.clear();
	closedb();

}

void Employee::update()
{
}

void Employee::remove()
{
}

string Employee::getUsername() const
{
	
	return m_username;
}
