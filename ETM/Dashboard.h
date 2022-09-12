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
#include <QMessageBox>
#include <random>

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
	QMessageBox msg;
	QString alertmsg;
	int rowID;
	string qoutes[10];
	int qoutenum;
	enum class SortingCriteria {
		priority, priorityReversed, deadline, deadlineReversed
	};

	void refresh();
	void getTasks();
	void viewTasks(SortingCriteria sortingCriteria);
	void showReminder();

private slots:
	void on_logout_btn_clicked();
	void on_addTask_btn_clicked();
	void on_sortByDeadline_clicked();
	void on_sortByPriority_clicked();
	void on_tableView_doubleClicked();

	 /// <summary>
	 /// A paint event is a request to repaint all or part of a widget. It can happen when the widget was obscured and has now been uncovered.
	 /// </summary>
	 /// <param name="event">A QPaintEvent</param>
	void paintEvent(QPaintEvent* event) override;
	void deleteTaskBtn();
	void editTaskBtn();
	void postponeTaskBtn();
};
