#include "Task.h"

Task::Task(string title, string description, int id, short priority, Date assigningDate, Date deadline, Employee assignee)
	: m_title(title), m_description(description), m_id(id), m_priority(priority),
	m_assigningDate(assigningDate), m_deadline(deadline), m_assignee(assignee)
{
}

Task::Task(int id, Employee assignee)
	: m_id(id), m_assignee(assignee)
{
	retrieve();
}

Task::~Task()
{
}

void Task::edit(const Task& editedTask)
{
	this->m_description = editedTask.m_description;
	this->m_title = editedTask.m_title;
	this->m_priority = editedTask.m_priority;
}

void Task::postpone(Date newDeadline)
{
	this->m_deadline = newDeadline;
}

void Task::retrieve()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("select * from Task where employeeUsername = :assignee");
	qry.bindValue(":assignee", m_assignee.getUsername().c_str());

	if (qry.exec()) {
		while (qry.next()) {
			m_title = qry.value(0).toString().toUtf8().constData();
			m_description = qry.value(1).toString().toUtf8().constData();
			
		}
	}
	qry.clear();
	closedb();
}

void Task::add()
{
}

void Task::update()
{
}

void Task::remove()
{
}
