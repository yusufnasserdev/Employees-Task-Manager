#include "Task.h"

Task::Task(string title, string description, string username, int id, short priority, QDateTime deadline)
	: m_title(title), m_description(description), m_assigneeUsername(username),
	m_id(id), m_priority(priority), m_deadline(deadline)
{
}

Task::Task(string title, string description, string username, short priority, QDateTime assigningDate, QDateTime deadline)
	: m_title(title), m_description(description), m_assigneeUsername(username),
	m_priority(priority), m_assigningDate(assigningDate), m_deadline(deadline)
{
	add();
}

Task::Task(int id)
	: m_id(id)
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

string Task::getTitle() const
{
	return m_title;
}

string Task::getDescription() const
{
	return m_description;
}

int Task::getId() const
{
	return m_id;
}

short Task::getPriority() const
{
	return m_priority;
}

QDateTime Task::getDeadline() const
{
	return m_deadline;
}

QDateTime Task::getAssigningDate() const
{
	return m_assigningDate;
}

void Task::retrieve()
{
	QSqlQuery qry;
	qry.prepare("select title, description, assigningDate, endingDate, priority, employeeUsername from Task where id = :m_id");
	qry.bindValue(":m_id", m_id);

	if (qry.exec()) {
		int i = 0;
		while (qry.next()) {
			m_title = qry.value(0).toString().toUtf8().constData();
			m_description = qry.value(1).toString().toUtf8().constData();
			m_assigningDate = QDateTime::fromString(qry.value(2).toString().toUtf8().constData(), m_dateFormat);
			m_deadline = QDateTime::fromString(qry.value(3).toString().toUtf8().constData(), m_dateFormat);
			m_priority = qry.value(4).toInt();
			m_assigneeUsername = qry.value(5).toString().toUtf8().constData();
		}
	}

	qry.clear();
}

void Task::add()
{
	QSqlQuery qry;
	qry.prepare("insert into Task(title, description, assigningDate, endingDate, priority, employeeUsername) values(:m_title , :m_description, :m_assigningDate, :m_deadline,:m_priority, :m_employeeUsername)");

	qry.bindValue(":m_title", m_title.c_str());
	qry.bindValue(":m_description", m_description.c_str());
	qry.bindValue(":m_assigningDate", m_assigningDate.toString(m_dateFormat).toStdString().c_str());
	qry.bindValue(":m_deadline", m_deadline.toString(m_dateFormat).toStdString().c_str());
	qry.bindValue(":m_priority", m_priority);
	qry.bindValue(":m_employeeUsername", m_assigneeUsername.c_str());

	qry.exec();
	qry.clear();
}

void Task::update()
{
	QSqlQuery qry;
	qry.prepare("update Task set title = :m_title, description = :m_description, endingDate = :m_deadline, priority = :m_priority where id = :m_id");

	qry.bindValue(":m_title", m_title.c_str());
	qry.bindValue(":m_description", m_description.c_str());
	qry.bindValue(":m_deadline", m_deadline.toString(m_dateFormat).toStdString().c_str());
	qry.bindValue(":m_priority", m_priority);
	qry.bindValue(":m_id", m_id);

	qry.exec();
	qry.clear();
}

void Task::remove()
{
	QSqlQuery qry;
	qry.prepare("DELETE FROM Task WHERE id = :m_id");

	qry.bindValue(":m_id", to_string(m_id).c_str());

	qry.exec();
	qry.clear();
}

const char* Task::m_dateFormat = "yyyy-MM-dd hh:mm:ss";