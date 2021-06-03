#pragma once

#include <QWidget>
#include "ui_AddTask.h"
#include "Employee.h"

class AddTask : public QWidget
{
	Q_OBJECT

public:
	AddTask(Employee user, QWidget* parent = Q_NULLPTR);
	~AddTask();
private:
	Ui::AddTask ui;
	Employee m_assignee;
	
private slots:
	void on_addTask_btn_clicked();
	void AddTask::closeEvent(QCloseEvent* event);
};
