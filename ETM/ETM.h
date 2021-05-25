#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ETM.h"
#include <QtWidgets/QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <qdebug.h>
#include<iostream>
#include <regex>

class ETM : public QMainWindow
{
    Q_OBJECT

public:
    ETM(QWidget *parent = Q_NULLPTR);

private:
    Ui::ETM ui;
    QRegularExpression re;
    QRegularExpression re2;
private slots:
    bool isPasswordValid(QString password);
    void on_pushButton_clicked();
};
