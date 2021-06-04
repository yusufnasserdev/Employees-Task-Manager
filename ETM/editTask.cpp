#include "editTask.h"

editTask::editTask(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

}

editTask::~editTask()
{
}

void editTask::excuteqry(int rowID)
{
	QSqlQuery qry;
	qry.prepare("select title,priority,description from task where id = :m_rowID");
	qry.bindValue(":m_rowID",rowID);

	if (qry.exec()) {
		while (qry.next()) {
			ui.title->setText(qry.value(0).toString());
			ui.priority->setValue(qry.value(1).toInt());
			ui.description->setText(qry.value(2).toString());
		}
		
	}

	qry.clear();
}

void editTask::editqry(int rowID)
{
	//TODO
}




