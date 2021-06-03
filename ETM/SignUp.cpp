#include "SignUp.h"
#include "globalHeader.h"
#include "globalVariables.h"
#include "ETM.h"



SignUp::SignUp(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	ui.emailWarning->hide();
	ui.emailWarning->setDisabled(1);
	ui.passwordWarning->hide();
	ui.passwordWarning->setDisabled(1);
	ui.confirmPasswordWarning->hide();
	ui.confirmPasswordWarning->setDisabled(1);
}

SignUp::~SignUp()
{
}

bool SignUp::isEmailValid(QString email)
{
	QRegularExpression re;
	QString pattern = ".+\\@.+\\..+";
	re.setPattern(pattern);
	return re.match(email).hasMatch();
}

void SignUp::on_tosignIn_btn_clicked()
{
	ETM* signIn = new ETM();
	signIn->show();
	close();
}

void SignUp::on_sign_email_textChanged(QString email)
{
	QString stylesheet = fieldValidation(isEmailValid(email), email);
	 ui.sign_email->setStyleSheet(stylesheet);
	 if (stylesheet== "background-color: rgba(240, 78, 78, 50);") {
		 ui.emailWarning->setHidden(0);
	}else{
		 ui.emailWarning->setHidden(1);
	 }
}

void SignUp::on_sign_password_textChanged(QString password)
{
	QString temp =ui.sign_password->text().trimmed();
	ui.sign_password->setText(temp);
	passwordValid=isPasswordValid(temp);
	QString stylesheet = fieldValidation(passwordValid, temp);
	ui.sign_password->setStyleSheet(stylesheet);
	if (stylesheet == "background-color: rgba(240, 78, 78, 50);") {
		ui.passwordWarning->setHidden(0);
	}
	else {
		ui.passwordWarning->setHidden(1);
	}
}


void SignUp::on_sign_confirmpassword_textChanged(QString password)
{
	if (passwordValid) {
	QString temp = ui.sign_confirmpassword->text().trimmed();
	ui.sign_confirmpassword->setText(temp);
	passwordConfirmed = ui.sign_confirmpassword->text() == ui.sign_password->text();
	QString stylesheet = fieldValidation(passwordConfirmed, temp);
	ui.sign_confirmpassword->setStyleSheet(stylesheet);
	if (stylesheet == "background-color: rgba(240, 78, 78, 50);") {
		ui.confirmPasswordWarning->setHidden(0);
	}
	else {
		ui.confirmPasswordWarning->setHidden(1);
	}
	qDebug() << passwordConfirmed;
	}
}
