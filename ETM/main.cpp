#include "ETM.h"
#include <QtWidgets/QApplication>
#include "SignUp.h"
#include "globalVariables.h"
#include "Employee.h"

bool isshown = false;

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    ETM w;
//    w.show();
//    return a.exec();
//}

int main() {
	Employee e1("hamada", "mayada","hamadamayada", "hamadamayada@gmail.com","123456789");
	e1.add();

	return 0;
}