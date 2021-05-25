#include "EmployeesTaskManager.h"
/*
*Ayman Hassan 24-5-2021
* Badr 24-5-2021
*/
EmployeesTaskManager::EmployeesTaskManager(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 600);
    ui.setupUi(this);
}

bool EmployeesTaskManager::isPasswordValid(QString password)
{

    
     re.setPattern("^[a-zA-Z0-9!@#$%&*]{8,40}$");
     qDebug()<< password;
     QRegularExpressionMatch match = re.match(password);
     return match.hasMatch();
    
}

void EmployeesTaskManager::on_pushButton_clicked()
{
   qDebug()<< isPasswordValid(ui.lineEdit_2->text());
}
