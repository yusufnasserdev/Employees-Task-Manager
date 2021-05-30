#pragma once
#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "SqlInterface.h"

using namespace std;

class Task : public SqlInterface
{
private:
	string m_title, m_description;
	const int m_id;
	short m_priority;
	const Date m_assigningDate;
	Date m_deadline;
	const Employee m_assignee;

public:
	Task(string, string, int, short, Date, Date, Employee);
	~Task();

	void edit(const Task&);
	void postpone(Date);

	void retrieve() override;
	void add() override;
	void update() override;
	void remove() override;
};

