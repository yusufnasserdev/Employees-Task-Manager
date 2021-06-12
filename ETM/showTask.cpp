#include "showTask.h"

showTask::showTask(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(400, 600);
	ui.setupUi(this);
	setDisabled(true);
	setAttribute(Qt::WA_DeleteOnClose);
}

showTask::~showTask()
{
}

void showTask::setTask(int rowID)
{
	Task showedTask(rowID);
	setWindowTitle(showedTask.getTitle().c_str());
	ui.description->setText(showedTask.getDescription().c_str());
	ui.assigningDate->setText(showedTask.getAssigningDate().toString());
	ui.deadline->setText(showedTask.getDeadline().toString());
	ui.priority->setText(to_string(showedTask.getPriority()).c_str());
	ui.priority->alignment().setFlag(Qt::AlignmentFlag::AlignCenter);
}

