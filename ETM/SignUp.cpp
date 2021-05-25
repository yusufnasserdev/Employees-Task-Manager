#include "SignUp.h"
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

void SignUp::on_tosignIn_btn_clicked()
{
	ETM* signIn = new ETM();
	signIn->show();
	this->close();
}
