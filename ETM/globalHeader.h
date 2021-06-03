#pragma once
#include<iostream>
#include <QtWidgets/QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <qdebug.h>
#include <Qthread>

bool static isPasswordValid(QString password) {
QRegularExpression re;
    QString pattern = "^(?=.*\\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[^\\w\\d\\s:])([^\\s]){8,40}$";
    re.setPattern(pattern);
    qDebug() << password;
    return re.match(password).hasMatch();
}

QString  static fieldValidation(bool isValid, QString passwordText) {

    if (passwordText == "") {
        return "background-color: #292f45;";
    }
    if (isValid) {
        return "background-color: rgba(78, 240, 78, 50);";
    }
    return "background-color: rgba(240, 78, 78, 50);";
}


