#include "Dashboard.h"
#include "ETM.h"
#include "globalHeader.h"
#include "globalVariables.h"
Dashboard::Dashboard(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
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
	if (!isshown) {
		 addTask = new AddTask();
		 addTask->show();
		 isshown = true;
	}
	else {
		qDebug() << "not today";
	}
	
}



void Dashboard::paintEvent(QPaintEvent* event)
{
	ui.addTask_btn->setDisabled(isshown);
}
