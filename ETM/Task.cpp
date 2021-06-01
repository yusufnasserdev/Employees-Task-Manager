#include "Task.h"

Task::Task(string title, string description, int id, short priority, QDateTime deadline, Employee assignee)
	: m_title(title), m_description(description), m_id(id), 
	m_priority(priority), m_deadline(deadline), m_assignee(assignee)
{
}
 
Task::Task(string title, string description, short priority, QDateTime assigningDate, QDateTime deadline, Employee assignee)
	: m_title(title), m_description(description), m_priority(priority),
	m_assigningDate(assigningDate), m_deadline(deadline), m_assignee(assignee)
{
	add();
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

	update();
}

void Task::postpone(const QDateTime& newDeadline)
{
	this->m_deadline = newDeadline;

	update();
}

int Task::getId()
{
	return m_id;
}

void Task::retrieve()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("select title, description, assigningDate, endingDate, priority from Task where id = :m_id");
	qry.bindValue(":m_id", m_id);

	if (qry.exec()) {
		cout << "Retrieved\n"	;
		int i = 0;
		while (qry.next()) {
			m_title = qry.value(0).toString().toUtf8().constData();
			m_description = qry.value(1).toString().toUtf8().constData();
			m_assigningDate = QDateTime::fromString(qry.value(2).toString().toUtf8().constData(), m_dateFormat);
			m_deadline = QDateTime::fromString(qry.value(3).toString().toUtf8().constData(), m_dateFormat);
			m_priority = qry.value(4).toInt();
		}
	}

	qry.clear();
	closedb();
}

void Task::add()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("insert into Task(title, description, assigningDate, endingDate, priority, employeeUsername) values(:m_title , :m_description, :m_assigningDate, :m_deadline,:m_priority, :m_employeeUsername)");

	qry.bindValue(":m_title", m_title.c_str());
	qry.bindValue(":m_description", m_description.c_str());
	qry.bindValue(":m_assigningDate", m_assigningDate.toString(m_dateFormat).toStdString().c_str());
	qry.bindValue(":m_deadline", m_deadline.toString(m_dateFormat).toStdString().c_str());
	qry.bindValue(":m_priority", m_priority);
	qry.bindValue(":m_employeeUsername", m_assignee.getUsername().c_str());

	qry.exec();
	qry.clear();
	closedb();
}

void Task::update()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("update Task set title = :m_title, description = :m_description, endingDate = :m_deadline, priority = :m_priority where id = :m_id");

	qry.bindValue(":m_title", m_title.c_str());
	qry.bindValue(":m_description", m_description.c_str());
	qry.bindValue(":m_deadline", m_deadline.toString(m_dateFormat).toStdString().c_str());
	qry.bindValue(":m_priority", m_priority);
	qry.bindValue(":m_id", m_id);

	qry.exec();
	qry.clear();
	closedb();
}

void Task::remove()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("DELETE FROM Task WHERE id = :m_id");

	qry.bindValue(":m_id", to_string(m_id).c_str());

	qry.exec();
	qry.clear();
	closedb();
}

const char* Task::m_dateFormat = "yyyy-MM-dd hh:mm:ss";