#include "SignUp.h"
#include "globalHeader.h"
#include "ETM.h"



SignUp::SignUp(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
	ui.Warning1->hide();
	ui.Warning1->setDisabled(1);
	ui.Warning2->hide();
	ui.Warning2->setDisabled(1);
	ui.Warning3->hide();
	ui.Warning3->setDisabled(1);
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
	QString stylesheet = fieldValidation(isEmailValid(email), email);
	 ui.sign_email->setStyleSheet(stylesheet);
	 if (stylesheet== "background-color: rgba(240, 78, 78, 50);") {
		 ui.Warning1->setHidden(0);
	}else{
		 ui.Warning1->setHidden(1);
	 }
}

void SignUp::on_sign_password_textChanged(QString password)
{
	QString temp =ui.sign_password->text().trimmed();
	ui.sign_password->setText(temp);
	passwordValid=isPasswordValid(temp);
	QString stylesheet = fieldValidation(isEmailValid(password), temp);
	ui.sign_password->setStyleSheet(stylesheet);
	if (stylesheet == "background-color: rgba(240, 78, 78, 50);") {
		ui.Warning2->setHidden(0);
	}
	else {
		ui.Warning2->setHidden(1);
	}
	/*
	db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("ETM_database.db");
	QSqlQuery d;
	if (!db.open()) qDebug() << "error";
	d.exec("select * from employee");
	while (d.next()) {
		qDebug()<<(d.value(0).toString());
	}
	d.clear();
	db.close();
	*/
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
		ui.Warning3->setHidden(0);
	}
	else {
		ui.Warning3->setHidden(1);
	}
	qDebug() << passwordConfirmed;
	}
}
