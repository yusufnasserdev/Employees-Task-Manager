#include "Dashboard.h"
#include "ETM.h"

Dashboard::Dashboard(Employee user, QWidget* parent)
	: m_user(user), QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);

	string greeting = "Hi, " + m_user.getFirstName();
	ui.label->setText(greeting.c_str()); 

	m_pqPriority = new priority_queue<Task, vector<Task>, ComparePriority>();
	m_pqDeadline = new priority_queue<Task, vector<Task>, CompareDeadline>();
	
	getTasks(SortingCriteria::priority);
}

Dashboard::~Dashboard()
{
	delete addTask;
	delete m_pqPriority;
	delete m_pqDeadline;
}

void Dashboard::getTasks(SortingCriteria sortingCriteria)
{
	if (sortingCriteria == SortingCriteria::priority) {
		QSqlQuery qry;
		qry.prepare("select id from task where employeeUsername = :m_username");
		qry.bindValue(":m_username", m_user.getUsername().c_str());

		if (qry.exec()) {
			while (qry.next()) {
				m_pqPriority->push(Task(qry.value(0).toInt()));
			}
		}

		qry.clear();
	}
	else if (sortingCriteria == SortingCriteria::deadline) {
		QSqlQuery qry;
		qry.prepare("select id from task where employeeUsername = :m_username");
		qry.bindValue(":m_username", m_user.getUsername().c_str());

		if (qry.exec()) {
			while (qry.next()) {
				Task task(qry.value(0).toInt());
				m_pqDeadline->push(task);
			}
		}

		qry.clear();
	}
	// viewTasks();
}

void Dashboard::on_logout_btn_clicked()
{
	ETM* signin = new ETM();
	signin->show();
	close();
}

void Dashboard::on_addTask_btn_clicked()
{
	if (!isShown) {
		addTask = new AddTask();
		addTask->show();
		isShown = true;
	}
	else {
		qDebug() << "not today";
	}
}

void Dashboard::paintEvent(QPaintEvent* event)
{
	ui.addTask_btn->setDisabled(isShown);
}
