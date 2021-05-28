#pragma once

#include <QWidget>
#include "ui_Dashboard.h"
#include "AddTask.h"

class Dashboard : public QWidget
{
	Q_OBJECT

public:
	Dashboard(QWidget *parent = Q_NULLPTR);
	~Dashboard();

private:
	Ui::Dashboard ui;
	AddTask* addTask = new AddTask();
	
	
private slots:
	void on_logout_btn_clicked();
	void on_addTask_btn_clicked();
	void Dashboard::paintEvent(QPaintEvent* event);
};
