#pragma once

#include <QWidget>
#include <queue>
#include "ui_Dashboard.h"
#include "globalHeader.h"
#include "globalVariables.h"
#include "AddTask.h"
#include "Employee.h"
#include "Task.h"
#include "Comparators.h"

class Dashboard : public QWidget
{
	Q_OBJECT

public:
	Dashboard(Employee user, QWidget *parent = Q_NULLPTR);
	~Dashboard();

private:
	Ui::Dashboard ui;
	AddTask* addTask = new AddTask();
	Employee m_user;
	priority_queue<Task, vector<Task>, ComparePriority> *m_pqPriority;
	priority_queue<Task, vector<Task>, CompareDeadline> *m_pqDeadline;

	enum class SortingCriteria {
		priority, deadline
	};

	void getTasks(SortingCriteria sortingCriteria);

private slots:
	void on_logout_btn_clicked();
	void on_addTask_btn_clicked();
	void Dashboard::paintEvent(QPaintEvent* event);
};
