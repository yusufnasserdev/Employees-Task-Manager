#pragma once

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_showTask.h"
#include "Task.h"

class showTask : public QWidget
{
	Q_OBJECT

public:
	showTask(QWidget *parent = Q_NULLPTR);
	~showTask();
	void setTask(int);
private:
	Ui::showTask ui;
};
