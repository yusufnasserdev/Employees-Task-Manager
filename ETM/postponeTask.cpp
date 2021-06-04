#include "postponeTask.h"

postponeTask::postponeTask(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	ui.title->setDisabled(true);

}

postponeTask::~postponeTask()
{
}

void postponeTask::excuteqry(int rowID)
{
	QSqlQuery qry;
	qry.prepare("select title,endingDate from task where id = :m_rowID");
	qry.bindValue(":m_rowID", rowID);

	if (qry.exec()) {
		while (qry.next()) {
			ui.title->setText(qry.value(0).toString());
			ui.deadline->setDateTime(qry.value(1).toDateTime());
		}

	}

	qry.clear();
}

void postponeTask::editqry(int rowID)
{
	//TODO
}
