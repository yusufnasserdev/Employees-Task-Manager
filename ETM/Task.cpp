#include "Task.h"

Task::Task(string title, string description, short priority, QDateTime assigningDate, QDateTime deadline, Employee assignee)
	: m_title(title), m_description(description), m_priority(priority),
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

void Task::postpone(QDateTime newDeadline)
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
			m_title = qry.value(1).toString().toUtf8().constData();
			m_description = qry.value(2).toString().toUtf8().constData();
			m_assigningDate = qry.value(3).toDateTime();
			m_deadline = qry.value(4).toDateTime();
			m_priority = qry.value(5).toInt();
		}
		qDebug() << m_assigningDate << endl;
	}
	qry.clear();
	closedb();
}

/*QString dd ="2018-08-01";
  qDebug() << "ddddd" << dd;
  QDate da=QDate::fromString(dd,"yyyy-MM-dd");
*/

void Task::add()
{
	opendb();
	QSqlQuery qry;
	qry.prepare("insert into Task(title, description, assigningDate, endingDate, priority, employeeUsername) values(:m_title , :m_description, :m_assigningDate, :m_deadline,:m_priority, :m_employeeUsername)");

	qry.bindValue(":m_title", m_title.c_str());
	qry.bindValue(":m_description", m_description.c_str());
	qry.bindValue(":m_assigningDate", m_assigningDate.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str());
	qry.bindValue(":m_deadline", m_deadline.toString("yyyy-MM-dd hh:mm:ss").toStdString().c_str());
	qry.bindValue(":m_priority", m_priority);
	qry.bindValue(":m_employeeUsername",m_assignee.getUsername().c_str());
	//qry.exec();
	cout << qry.exec() << endl;
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
	qry.bindValue(":m_deadline", m_deadline.toString().toStdString().c_str());
	qry.bindValue(":m_priority", to_string(m_priority).c_str());
	qry.bindValue(":m_id", to_string(m_id).c_str());
	qry.exec();
	qry.clear();
	closedb();

}

void Task::remove()
{
}
