#pragma once

#include <QtWidgets/QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <qdebug.h>
#include <regex>
#include "ui_EmployeesTaskManager.h"

class EmployeesTaskManager : public QMainWindow
{
    Q_OBJECT

public:
    EmployeesTaskManager(QWidget *parent = Q_NULLPTR);

private:
    Ui::EmployeesTaskManagerClass ui;
    QRegularExpression re;
private slots:
   bool isPasswordValid(QString password);
   void on_pushButton_clicked();
};
