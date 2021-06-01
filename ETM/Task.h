#pragma once
#include <iostream>
#include "Date.h"
#include "Employee.h"
#include "SqlInterface.h"
#include <QDateTime>

using namespace std;

class Task : public SqlInterface
{
private:
	string m_title, m_description;
	int m_id;
	short m_priority;
	QDateTime m_assigningDate, m_deadline;
	const Employee m_assignee;

	//Functions
	void retrieve() override;

public:
	Task(string, string, short, QDateTime, QDateTime, Employee);
	Task(int, Employee);
	~Task();
	
	void edit(const Task&);
	void postpone(QDateTime);

	void add() override;
	void update() override;
	void remove() override;
};

