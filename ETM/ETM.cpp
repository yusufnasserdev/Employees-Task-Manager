#include "ETM.h"
#include "globalHeader.h"
#include "globalVariables.h"

ETM::ETM(QWidget* parent)
	: QMainWindow(parent)
{
	this->setFixedSize(400, 600);
	ui.setupUi(this);
	ui.signinWarning->hide();
	ui.signinWarning->setDisabled(1);
	setWindowTitle("Tasky");
}


bool ETM::isCredentialsValid()
{
	m_username = ui.main_username->text().toStdString();
	m_password = ui.main_password->text().toStdString();

	if (ui.main_password->text().isEmpty() || ui.main_username->text().isEmpty())
	{
		return false;
	}
	if (Employee::getPassword(m_username) == m_password) {
		return true;
	}
	return false;
}

void ETM::on_login_btn_clicked()
{

	if (isCredentialsValid()) {
		ui.signinWarning->setHidden(1);
		dashboard = new Dashboard(Employee(m_username, m_password));
		dashboard->show();
		close();
	}
	else {
		ui.signinWarning->setHidden(0);
	}
}

void ETM::on_tosignup_btn_clicked()
{
	signUp = new SignUp();
	signUp->show();
	this->close();
}
