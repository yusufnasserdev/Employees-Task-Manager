#pragma once

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_showTask.h"

class showTask : public QWidget
{
	Q_OBJECT

public:
	showTask(QWidget *parent = Q_NULLPTR);
	~showTask();
	void excuteqry(int);
private:
	Ui::showTask ui;
};
