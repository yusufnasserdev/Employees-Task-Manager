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
	bool passwordValid;
	bool passwordConfirmed;
	bool isEmailValid(QString email);
private slots:
	void on_tosignIn_btn_clicked();
	void on_sign_email_textChanged(QString email);
	void on_sign_password_textChanged(QString password);
	void on_sign_confirmpassword_textChanged(QString password);

};
