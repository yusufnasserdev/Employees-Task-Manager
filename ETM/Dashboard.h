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
#include "customButton.h"
#include "postponeTask.h"
#include "showTask.h"
#include "editTask.h"
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
	customButton* edit_btn;
	customButton* postpone_btn;
	customButton* delete_btn;
	bool priorityReversed = true, deadlineReversed = true;
	postponeTask* postponetask;
	editTask* edittask;
	showTask* showtask;
	int rowID;

	enum class SortingCriteria {
		priority, priorityReversed, deadline, deadlineReversed
	};

	void refresh();
	void getTasks();
	void viewTasks(SortingCriteria sortingCriteria);

private slots:
	void on_logout_btn_clicked();
	void on_addTask_btn_clicked();
	void on_sortByDeadline_clicked();
	void on_sortByPriority_clicked();
	void on_tableView_doubleClicked();
	void paintEvent(QPaintEvent* event);
	void deleteTaskBtn();
	void editTaskBtn();
	void postponeTaskBtn();
};
