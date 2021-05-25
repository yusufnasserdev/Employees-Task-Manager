#include "EmployeesTaskManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EmployeesTaskManager w;
    w.show();
    return a.exec();
}
