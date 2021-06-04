#pragma once

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_postponeTask.h"

class postponeTask : public QWidget
{
	Q_OBJECT

public:
	postponeTask(QWidget *parent = Q_NULLPTR);
	~postponeTask();
	void excuteqry(int);
	void editqry(int);

private:
	Ui::postponeTask ui;
};
