#pragma once

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_postponeTask.h"
#include "Task.h"
#include "globalVariables.h"

class postponeTask : public QWidget
{
	Q_OBJECT

public:
	postponeTask(QWidget *parent = Q_NULLPTR);
	~postponeTask();
	void viewTask(int);
	void editDeadline();

private:
	Ui::postponeTask ui;
	int rowID;

private slots:
	void on_pushButton_clicked();
};
