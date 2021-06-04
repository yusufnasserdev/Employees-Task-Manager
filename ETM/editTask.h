#pragma once

#include <QWidget>
#include "Employee.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_editTask.h"

class editTask : public QWidget
{
	Q_OBJECT

public:
	editTask(QWidget *parent = Q_NULLPTR);
	~editTask();
	void excuteqry(int);
	void editqry(int);

private:
	Ui::editTask ui;
};
