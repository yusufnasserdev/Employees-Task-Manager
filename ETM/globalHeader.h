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
QRegularExpression re2;
    QString spicalCharactersPattern = "[!@#$%^&*(),.?:{} | <>]";
    QString pattern = "^[a-zA-Z0-9!@#$%&*]{8,40}$";
    //"^[a-zA-Z0-9!@#$%&*]{8,40}$"
    //^(?=.*\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[^\w\d\s:])([^\s]){12,123}$
    re.setPattern(pattern);
    re2.setPattern(spicalCharactersPattern);
    std::cout << password.toStdString() << std::endl;
    return re.match(password).hasMatch() && re2.match(password).hasMatch();
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
QSqlDatabase static db;

