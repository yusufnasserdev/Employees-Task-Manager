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

	model = new QStandardItemModel();
	parentItem = model->invisibleRootItem();
	item = new QStandardItem();

	m_pqPriority = new priority_queue<Task, vector<Task>, ComparePriority>();
	m_pqDeadline = new priority_queue<Task, vector<Task>, CompareDeadline>();
	
	getTasks();
	viewTasks(SortingCriteria::priority);
}

Dashboard::~Dashboard()
{
	delete addTask;
	delete m_pqPriority;
	delete m_pqDeadline;
	delete model;
	delete item;
}

void Dashboard::getTasks()
{
	delete m_pqPriority;
	delete m_pqDeadline;

	m_pqPriority = new priority_queue<Task, vector<Task>, ComparePriority>();
	m_pqDeadline = new priority_queue<Task, vector<Task>, CompareDeadline>();

	QSqlQuery qry;
	qry.prepare("select id from task where employeeUsername = :m_username");
	qry.bindValue(":m_username", m_user.getUsername().c_str());

	if (qry.exec()) {
		while (qry.next()) {
			m_pqPriority->push(Task(qry.value(0).toInt()));
			m_pqDeadline->push(Task(qry.value(0).toInt()));
		}
	}

	qry.clear();
}

void Dashboard::viewTasks(SortingCriteria sortingCriteria)
{
	model->setColumnCount(6);

	if (sortingCriteria == SortingCriteria::priority) {
		priority_queue<Task, vector<Task>, ComparePriority> pqTemp = *m_pqPriority;

		model->setRowCount(pqTemp.size());

		for (int i = 0; !pqTemp.empty(); i++) {

			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());

			pqTemp.pop();
		}
		
	}
	else if (sortingCriteria == SortingCriteria::priorityReversed) {
		priority_queue<Task, vector<Task>, ComparePriority> pqTemp = *m_pqPriority;

		model->setRowCount(pqTemp.size());

		for (int i = pqTemp.size() - 1; !pqTemp.empty(); i--) {

			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());

			pqTemp.pop();
		}
	}
	else if (sortingCriteria == SortingCriteria::deadline) {
		priority_queue<Task, vector<Task>, CompareDeadline> pqTemp = *m_pqDeadline;

		model->setRowCount(pqTemp.size());

		for (int i = 0; !pqTemp.empty(); i++) {

			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());

			pqTemp.pop();
		}
	}
	else if (sortingCriteria == SortingCriteria::deadlineReversed) {
		priority_queue<Task, vector<Task>, CompareDeadline> pqTemp = *m_pqDeadline;

		model->setRowCount(pqTemp.size());

		for (int i = pqTemp.size() - 1; !pqTemp.empty(); i--) {

			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());

			pqTemp.pop();
		}
	}

	ui.tableView->setModel(model);
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
		addTask = new AddTask(m_user);
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


void Dashboard::on_sortByDeadline_clicked() {
	getTasks();
	viewTasks(deadlineReversed ? SortingCriteria::deadline : SortingCriteria::deadlineReversed);
	deadlineReversed = !(deadlineReversed);
}

void Dashboard::on_sortByPriority_clicked() {
	getTasks();
	viewTasks(priorityReversed ? SortingCriteria::priority : SortingCriteria::priorityReversed);
	priorityReversed = !(priorityReversed);
}