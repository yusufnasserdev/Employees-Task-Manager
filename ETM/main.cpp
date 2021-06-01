#include "ETM.h"
#include <QtWidgets/QApplication>
#include "SignUp.h"
#include "globalVariables.h"
#include "Employee.h"
#include "Task.h"
#include <string>
#include <iostream>
#include <QDir>
#include <QVariant>
#include "SqlInterface.h"


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
	QString username = "aymannerd";
	QString password = "123456789";
	QString temp = "2021-07-04 16:22:00";
	
	QDateTime assdate = QDateTime::currentDateTime();
	QDateTime enddate  = QDateTime::fromString(temp, "yyyy-MM-dd hh:mm:ss");

	Employee ela5tabot(username.toStdString(), password.toStdString());

	Task t1(7, ela5tabot), t2("ab", "aa", t1.getId(), 8, enddate, ela5tabot);

	return 0;
}


