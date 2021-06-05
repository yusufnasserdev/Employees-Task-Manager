#pragma once

#include <QWidget>
#include "Employee.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_editTask.h"
#include "Task.h"
#include "globalVariables.h"

class editTask : public QWidget
{
	Q_OBJECT

public:
	editTask(QWidget *parent = Q_NULLPTR);
	~editTask();
	void viewTask(int);

private:
	Ui::editTask ui;
	void excute();
	int rowID;

private slots:
	void on_edit_btn_clicked();
};
