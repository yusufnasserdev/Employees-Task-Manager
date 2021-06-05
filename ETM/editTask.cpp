#include "editTask.h"

editTask::editTask(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedSize(400, 550);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

}

editTask::~editTask()
{
	isClosed = true;
}

void editTask::viewTask(int id)
{
	this->rowID = id;
	Task editedTask(rowID);
	ui.title->setText(editedTask.getTitle().c_str());
	ui.priority->setValue(editedTask.getPriority());
	ui.description->setText(editedTask.getDescription().c_str());
}

void editTask::excute()
{
	
}

void editTask::on_edit_btn_clicked()
{
	Task oldTask(rowID), editedTask(rowID);
	editedTask.setTitle(ui.title->text().toStdString());
	editedTask.setTitle(ui.description->document()->toPlainText().toStdString());
	editedTask.setPriority(ui.priority->value());
	oldTask.edit(editedTask);
	close();
}




