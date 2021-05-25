#include "SignUp.h"
#include "globalHeader.h"
#include "ETM.h"



SignUp::SignUp(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
}

SignUp::~SignUp()
{
}

bool SignUp::isEmailValid(QString email)
{
	QRegularExpression re;
	QString pattern = ".+\@.+\..+";
	re.setPattern(pattern);
	return re.match(email).hasMatch();
}

void SignUp::on_tosignIn_btn_clicked()
{
	ETM* signIn = new ETM();
	signIn->show();
	this->close();
}

void SignUp::on_sign_email_textChanged(QString email)
{
	ui.sign_email->setStyleSheet(fieldValidation(isEmailValid(email), email));
}

void SignUp::on_sign_password_textChanged(QString password)
{
	QString temp = ui.sign_password->text().trimmed();
	ui.sign_password->setText(temp);
	passwordValid=isPasswordValid(temp);
	ui.sign_password->setStyleSheet(fieldValidation(passwordValid,temp));
	
}



void SignUp::on_sign_confirmpassword_textChanged(QString password)
{
	if (passwordValid) {
	QString temp = ui.sign_confirmpassword->text().trimmed();
	ui.sign_confirmpassword->setText(temp);
	passwordConfirmed = ui.sign_confirmpassword->text() == ui.sign_password->text();
	ui.sign_confirmpassword->setStyleSheet(fieldValidation(passwordConfirmed, temp));
	
	qDebug() << passwordConfirmed;
	}
}
