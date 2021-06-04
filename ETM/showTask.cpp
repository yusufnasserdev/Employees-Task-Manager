#include "showTask.h"

showTask::showTask(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setDisabled(true);
	setAttribute(Qt::WA_DeleteOnClose);

}

showTask::~showTask()
{
}

void showTask::excuteqry(int rowID)
{
	QSqlQuery qry;
	qry.prepare("select title, description, assigningDate, endingDate, priority from Task where id = :m_id");
	qry.bindValue(":m_id", rowID);

	if (qry.exec()) {
		int i = 0;
		while (qry.next()) {
			ui.title->setText(qry.value(0).toString().toUtf8().constData());
			ui.description->setText(  qry.value(1).toString().toUtf8().constData());
			ui.assigningDate->setDateTime(qry.value(2).toDateTime());
			ui.deadline->setDateTime(qry.value(3).toDateTime());
			ui.priority->setValue( qry.value(4).toInt());
		}
	}

	qry.clear();
}

