#include "ETM.h"
#include <QtWidgets/QApplication>
#include "SignUp.h"
#include "globalVariables.h"

bool isshown = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ETM w;
    w.show();
    return a.exec();
}
