#include "Task.h"

Task::Task(string title, string description, int id, short priority, Date assigningDate, Date deadline, Employee assignee)
	: m_title(title), m_description(description), m_id(id), m_priority(priority),
	m_assigningDate(assigningDate), m_deadline(deadline), m_assignee(assignee)
{
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
