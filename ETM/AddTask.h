#pragma once

#include <QWidget>
#include "ui_AddTask.h"

class AddTask : public QWidget
{
	Q_OBJECT

public:
	AddTask(QWidget *parent = Q_NULLPTR);
	~AddTask();
	

private:
	Ui::AddTask ui;
	
private slots:
	void on_addTask_btn_clicked();
};
