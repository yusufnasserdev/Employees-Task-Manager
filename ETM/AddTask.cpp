#include "AddTask.h"
#include "globalHeader.h"
#include "globalVariables.h"
#include "Dashboard.h"
AddTask::AddTask(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

}

AddTask::~AddTask()
{
}

void AddTask::on_addTask_btn_clicked()
{
	//Dashboard* dashboard = new Dashboard();
	//dashboard->show();'
	close();
	//ui.lineEdit->setText("");
	//ui.lineEdit_2->setText("");
}

void AddTask::closeEvent(QCloseEvent* event)
{
	isShown = false;
}
