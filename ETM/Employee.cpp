#include "Employee.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <iostream>


Employee::Employee()
{
}

Employee::Employee(string firstName, string lastName, string username, string email, string password)
	: m_firstName(firstName), m_lastName(lastName),
	m_username(username), m_email(email), m_password(password)
{
}

Employee::Employee(string username, string password)
	: m_username(username), m_password(password)
{
	retrieve();
}

Employee::~Employee()
{
}

void Employee::retrieve()
{
	QSqlQuery qry;
	qry.prepare("select firstName, secondName , email from Employee where username = :m_username");
	qry.bindValue(":m_username", m_username.c_str());
	if (qry.exec()) {
		while (qry.next()) {
			m_firstName = qry.value(0).toString().toUtf8().constData();
			m_lastName = qry.value(1).toString().toUtf8().constData();
			m_email = qry.value(2).toString().toUtf8().constData();
		}
	}
	qry.clear();
}

void Employee::add()
{
	QSqlQuery qry;
	qry.prepare("insert into Employee values(:m_username, :m_firstName, :m_lastName, :m_email, :m_password)");
	qry.bindValue(":m_username", m_username.c_str());
	qry.bindValue(":m_firstName", m_firstName.c_str());
	qry.bindValue(":m_lastName", m_lastName.c_str());
	qry.bindValue(":m_email", m_email.c_str());
	qry.bindValue(":m_password", m_password.c_str());
	qry.exec();
	qry.clear();

}

void Employee::update()
{
}

void Employee::remove()
{
}

const string Employee::getUsername() const
{
	return m_username;
}

const string Employee::getPassword(const string& username)
{
	string password = "";

	QSqlQuery qry;
	qry.prepare("select password from Employee where username = :m_username");
	qry.bindValue(":m_username", username.c_str());
	if (qry.exec()) {
		while (qry.next()) {
			password = qry.value(0).toString().toUtf8().constData();
		}
	}
	qry.clear();

	return password;
}

const string Employee::getFirstName() const
{
	return m_firstName;
}
