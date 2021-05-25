#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ETM.h"
#include <QtWidgets/QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <qdebug.h>
#include<iostream>
#include <regex>
#include "SignUp.h"


class ETM : public QMainWindow
{
    Q_OBJECT

public:
    ETM(QWidget *parent = Q_NULLPTR);

private:
    Ui::ETM ui;
    QRegularExpression re;
    QRegularExpression re2;
    SignUp* signUp;
private slots:
    bool isPasswordValid(QString password);
    void on_login_btn_clicked();
    void on_tosignup_btn_clicked();

};
