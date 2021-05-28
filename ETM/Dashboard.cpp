#include "Dashboard.h"
#include "ETM.h"
Dashboard::Dashboard(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
}

Dashboard::~Dashboard()
{
}


void Dashboard::on_logout_btn_clicked()
{
	ETM* signin = new ETM();
	signin->show();
	close();
}

void Dashboard::on_addTask_btn_clicked()
{
	addTask = new AddTask();
	addTask->show();
}
