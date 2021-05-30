#include "Employee.h"

Employee::Employee(string firstName, string lastName, string username, string email, string password)
	: m_firstName(firstName), m_lastName(lastName), 
	m_username(username), m_email(email), m_password(password)
{
}

Employee::Employee(string username, string password)
	:m_username(username), m_password(password)
{
}

Employee::~Employee()
{
}

void Employee::retrieve()
{
	QSqlQuery qry;
	qry.prepare("SELECT firstName, secondName, email FROM Employee WHERE username = :m_username");
	qry.bindValue(":m_username", "yesyusuf");
	if (qry.exec())
	{
		cout << "ex\n";
		while (qry.next())
		{

			m_firstName = qry.value(0).toString().toStdString();
			m_lastName = qry.value(1).toString().toUtf8().constData();
			m_email = qry.value(2).toString().toStdString();
		}
		cout << m_firstName << "\t" << m_lastName << "\t" << m_email;
	}
	
}

void Employee::add()
{
}

void Employee::update()
{
}

void Employee::remove()
{
}
