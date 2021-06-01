#include "ETM.h"
#include <QtWidgets/QApplication>
#include "SignUp.h"
#include "globalVariables.h"
#include "Employee.h"
#include "Task.h"
#include<string>
#include<iostream>
#include <QDir>
bool isshown = false;
using namespace std;

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    ETM w;
//    w.show();
//    return a.exec();
//}

int main() {
	QString username = "ela5tabot";
	QString password = "123456789";
	Employee ramy= Employee(username.toStdString(), password.toStdString());
	Task t0(1,ramy);

	return 0;
}