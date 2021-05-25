#include "ETM.h"
#include "globalHeader.h"
ETM::ETM(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(400, 600);
    ui.setupUi(this);
}



void ETM::on_login_btn_clicked()
{
    //todo
    /*
    * to validated when the db is ready
    */
}



void ETM::on_tosignup_btn_clicked()
{
    signUp = new SignUp();
    signUp->show();
    this->close();
    
}
