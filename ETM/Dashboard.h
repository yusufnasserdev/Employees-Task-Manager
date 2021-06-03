#pragma once

#include <QWidget>
#include <QStandardItemModel>
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
	AddTask* addTask;
	Employee m_user;
	priority_queue<Task, vector<Task>, ComparePriority> *m_pqPriority;
	priority_queue<Task, vector<Task>, CompareDeadline> *m_pqDeadline;
	QStandardItemModel* model;
	QStandardItem* parentItem, *item;

	bool priorityReversed = true, deadlineReversed = true;

	enum class SortingCriteria {
		priority, priorityReversed, deadline, deadlineReversed
	};

	void getTasks();
	void viewTasks(SortingCriteria sortingCriteria);

private slots:
	void on_logout_btn_clicked();
	void on_addTask_btn_clicked();
	void on_sortByDeadline_clicked();
	void on_sortByPriority_clicked();


	void Dashboard::paintEvent(QPaintEvent* event);
};
