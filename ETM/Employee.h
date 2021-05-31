#pragma once
#include <iostream>

using namespace std;

class Employee
{
private:
	string m_firstName, m_lastName, m_username, m_email, m_password;

public:
	Employee(string, string, string, string, string);
	~Employee();
};

