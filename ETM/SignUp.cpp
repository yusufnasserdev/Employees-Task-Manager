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
	ui.usernameWarning->hide();
	ui.usernameWarning->setDisabled(1);
	ui.signupWarning->hide();
	ui.signupWarning->setDisabled(1);
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

bool SignUp::isUniqueUsername()
{
	bool isUnique = true;
	QSqlQuery qry;
	qry.prepare("select username from Employee where username = :m_username");
	qry.bindValue(":m_username", ui.sign_username->text());

	if (qry.exec()) {
		while (qry.next()) {
			isUnique = false;
		}
	}

	qry.clear();
	return isUnique;
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
		 singUpValidator = false;
	}else{
		 ui.emailWarning->setHidden(1);
		 singUpValidator = true;
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
		singUpValidator = false;
	}
	else {
		singUpValidator = true;
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
		singUpValidator = false;
	}
	else {
		singUpValidator = true;
		ui.confirmPasswordWarning->setHidden(1);
	}
	}
}

void SignUp::on_sign_username_textEdited(QString username)
{
	QString stylesheet = fieldValidation(isUniqueUsername(),username);
	ui.sign_username->setStyleSheet(stylesheet);
	if (stylesheet == "background-color: rgba(240, 78, 78, 50);") {
		ui.usernameWarning->setHidden(0);
		singUpValidator = false;
	}
	else {
		ui.usernameWarning->setHidden(1);
		singUpValidator = true;
	}
}

void SignUp::on_signUp_clicked()
{
	singUpValidator = singUpValidator && !(ui.sign_firstname->text().isEmpty() || ui.sign_lastname->text().isEmpty() || ui.sign_password->text().isEmpty() || ui.sign_confirmpassword->text().isEmpty() || ui.sign_email->text().isEmpty() || ui.sign_username->text().isEmpty());
	if (!singUpValidator) {
		ui.signupWarning->setHidden(0);
	}
	else {
		ui.signupWarning->setHidden(1);
		string firstName = ui.sign_firstname->text().toStdString();
		string lastName = ui.sign_lastname->text().toStdString();
		string username = ui.sign_username->text().toStdString();
		string email = ui.sign_email->text().toStdString();
		string password = ui.sign_password->text().toStdString();
		Employee newEmployee(firstName, lastName, username, email, password);
	}
}


