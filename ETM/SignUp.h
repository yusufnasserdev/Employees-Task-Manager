#pragma once

#include <QWidget>
#include "ui_SignUp.h"
#include <qdebug.h>

class SignUp : public QWidget
{
	Q_OBJECT

public:
	SignUp(QWidget *parent = Q_NULLPTR);
	~SignUp();

private:
	Ui::SignUp ui;
	

private slots:
	void on_tosignIn_btn_clicked();

};
