#include "postponeTask.h"

postponeTask::postponeTask(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(400, 300);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	ui.title->setDisabled(true);
}

postponeTask::~postponeTask()
{
	isClosed = true;
}

void postponeTask::viewTask(int id)
{
	this->rowID = id;
	Task editedTask(rowID);
	ui.title->setText(editedTask.getTitle().c_str());
	ui.deadline->setDateTime(editedTask.getDeadline());
}

void postponeTask::editDeadline()
{
	Task editedTask(rowID);
	editedTask.postpone(ui.deadline->dateTime());
}

void postponeTask::on_pushButton_clicked()
{
	editDeadline();
	close();
}
