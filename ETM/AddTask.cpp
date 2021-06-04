#include "AddTask.h"
#include "globalHeader.h"
#include "globalVariables.h"
#include "Dashboard.h"
AddTask::AddTask(Employee user, QWidget* parent)
	: QWidget(parent), m_assignee(user)
{
	this->setFixedSize(400, 600);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
}

AddTask::~AddTask()
{
}

void AddTask::on_addTask_btn_clicked()
{
	string title = ui.title->text().toStdString();
	string description = ui.description->toPlainText().toStdString();
	string assignee = m_assignee.getUsername();
	short priority = ui.priority->value();
	QDateTime assigningDate = ui.assigningDate->dateTime();
	QDateTime deadline = ui.deadline->dateTime();
	Task newTask(title, description, assignee, priority, assigningDate, deadline);
	close();
}

void AddTask::closeEvent(QCloseEvent* event)
{
	isShown = false;
}
