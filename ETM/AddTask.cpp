#include "AddTask.h"
AddTask::AddTask(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

AddTask::~AddTask()
{
}

void AddTask::on_addTask_btn_clicked()
{
	
	close();
}
