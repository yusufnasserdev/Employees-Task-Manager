#include "ETM.h"

ETM::ETM(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 600);
    ui.setupUi(this);
}

bool ETM::isPasswordValid(QString password)
{
    QString spicalCharactersPattern = "[!@#$%^&*(),.?:{} | <>]";
    QString pattern = "^[a-zA-Z0-9!@#$%&*]{8,40}$";
    //"^[a-zA-Z0-9!@#$%&*]{8,40}$"
    //^(?=.*\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[^\w\d\s:])([^\s]){12,123}$
    re.setPattern(pattern);
    re2.setPattern(spicalCharactersPattern);
    std::cout << password.toStdString() << std::endl;
    return re.match(password).hasMatch() && re2.match(password).hasMatch();
}

void ETM::on_pushButton_clicked()
{
    qDebug() << isPasswordValid(ui.lineEdit_2->text());
}
