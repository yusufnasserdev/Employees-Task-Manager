#pragma once
#include <iostream>
#include "Employee.h"
#include "SqlInterface.h"
#include <QDateTime>

using namespace std;

class Task : public SqlInterface
{
private:
	string m_title, m_description, m_assigneeUsername;
	int m_id;
	short m_priority;
	QDateTime m_assigningDate, m_deadline;

	void retrieve() override;
	void add() override;
	void update() override;

public:
	// Create a new task to use in runtime but won't be added to the DB
	Task(string, string, string, int, short, QDateTime);
	// Create a new task and add it to the DB
	Task(string, string, string, short, QDateTime, QDateTime);
	// Create an object to hold an existent task and retrieve its data from the DB
	Task(int);
	~Task();

	void remove() override;

	void edit(const Task&);
	void postpone(const QDateTime&);

	int getId();
	short getPriority() const;
	QDateTime getDeadline() const;

	static const char* m_dateFormat;
};

