#include "Employee.h"

Employee::Employee(string firstName, string lastName, string username, string email, string password)
	: m_firstName(firstName), m_lastName(lastName), 
	m_username(username), m_email(email), m_password(password)
{
}

Employee::~Employee()
{
}
