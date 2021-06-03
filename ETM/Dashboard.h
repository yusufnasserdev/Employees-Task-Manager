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

class Dashboard : public QWidget, public SqlInterface
{
	Q_OBJECT

public:
	Dashboard(Employee user, QWidget *parent = Q_NULLPTR);
	~Dashboard();

private:
	Ui::Dashboard ui;
	AddTask* addTask = new AddTask();
	Employee m_user;

	enum class SortingCriteria {
		priority, deadline
	};

	void getTasks(SortingCriteria sortingCriteria);

private slots:
	void on_logout_btn_clicked();
	void on_addTask_btn_clicked();
	void Dashboard::paintEvent(QPaintEvent* event);

	// Inherited via SqlInterface
	virtual void retrieve() override;
	virtual void add() override;
	virtual void update() override;
	virtual void remove() override;
};
