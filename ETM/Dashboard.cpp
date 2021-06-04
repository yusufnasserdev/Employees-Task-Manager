#include "Dashboard.h"
#include "ETM.h"



Dashboard::Dashboard(Employee user, QWidget* parent)
	: m_user(user), QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	string firstname = m_user.getFirstName();
	firstname[0] = firstname[0] - 32;
	string greeting = "Hi, " + firstname;
	ui.label->setText(greeting.c_str());

	addTask = new AddTask(m_user);

	model = new QStandardItemModel();
	parentItem = model->invisibleRootItem();
	item = new QStandardItem();

	m_pqPriority = new priority_queue<Task, vector<Task>, ComparePriority>();
	m_pqDeadline = new priority_queue<Task, vector<Task>, CompareDeadline>();
	
	
	getTasks();
	viewTasks(SortingCriteria::priority);
	//Header settings
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableView->model()->setHeaderData(0, Qt::Horizontal, tr("ID"));
	ui.tableView->model()->setHeaderData(1, Qt::Horizontal, tr("Title"));
	ui.tableView->model()->setHeaderData(2, Qt::Horizontal, tr("description"));
	ui.tableView->model()->setHeaderData(3, Qt::Horizontal, tr("assigningDate"));
	ui.tableView->model()->setHeaderData(4, Qt::Horizontal, tr("endingDate"));
	ui.tableView->model()->setHeaderData(5, Qt::Horizontal, tr("priority"));
	ui.tableView->model()->setHeaderData(6, Qt::Horizontal, tr("Edit task"));
	ui.tableView->model()->setHeaderData(7, Qt::Horizontal, tr("Edit date"));
	ui.tableView->model()->setHeaderData(8, Qt::Horizontal, tr("Delete"));
	ui.tableView->hideColumn(0);
	ui.tableView->horizontalHeader()->setStretchLastSection(true);


}

Dashboard::~Dashboard()
{
	delete addTask;
	delete m_pqPriority;
	delete m_pqDeadline;
	delete model;
	delete item;
}

void Dashboard::refresh()
{
	getTasks();
	viewTasks(SortingCriteria::priority);
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
	model->setColumnCount(9);
	ui.tableView->setModel(model);
	if (sortingCriteria == SortingCriteria::priority) {
		priority_queue<Task, vector<Task>, ComparePriority> pqTemp = *m_pqPriority;
		model->setRowCount(pqTemp.size());
		for (int i = 0; !pqTemp.empty(); i++) {
			edit_btn = new customButton("edit");
			postpone_btn = new customButton("postpone");
			delete_btn = new customButton("delete");
			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());
			ui.tableView->setColumnWidth(6, 16);
			ui.tableView->setColumnWidth(7, 16);
			ui.tableView->setColumnWidth(8, 20);
			ui.tableView->setIndexWidget(model->index(i, 6), edit_btn);
			ui.tableView->setIndexWidget(model->index(i, 7), postpone_btn);
			ui.tableView->setIndexWidget(model->index(i, 8), delete_btn);
			connect(edit_btn, SIGNAL(clicked()), this, SLOT(editTaskBtn()));
			connect(postpone_btn, SIGNAL(clicked()), this, SLOT(postponeTaskBtn()));
			connect(delete_btn, SIGNAL(clicked()), this, SLOT(deleteTaskBtn()));
			pqTemp.pop();
		}
		
	}
	else if (sortingCriteria == SortingCriteria::priorityReversed) {
		priority_queue<Task, vector<Task>, ComparePriority> pqTemp = *m_pqPriority;

		model->setRowCount(pqTemp.size());

		for (int i = pqTemp.size() - 1; !pqTemp.empty(); i--) {

			edit_btn = new customButton("edit");
			postpone_btn = new customButton("postpone");
			delete_btn = new customButton("delete");
			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());
			ui.tableView->setIndexWidget(model->index(i, 6), edit_btn);
			ui.tableView->setIndexWidget(model->index(i, 7), postpone_btn);
			ui.tableView->setIndexWidget(model->index(i, 8), delete_btn);
			connect(edit_btn, SIGNAL(clicked()), this, SLOT(editTaskBtn()));
			connect(postpone_btn, SIGNAL(clicked()), this, SLOT(postponeTaskBtn()));
			connect(delete_btn, SIGNAL(clicked()), this, SLOT(deleteTaskBtn()));

			pqTemp.pop();
		}
	}
	else if (sortingCriteria == SortingCriteria::deadline) {
		priority_queue<Task, vector<Task>, CompareDeadline> pqTemp = *m_pqDeadline;

		model->setRowCount(pqTemp.size());

		for (int i = 0; !pqTemp.empty(); i++) {

			edit_btn = new customButton("edit");
			postpone_btn = new customButton("postpone");
			delete_btn = new customButton("delete");
			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());
			connect(edit_btn, SIGNAL(clicked()), this, SLOT(editTaskBtn()));
			ui.tableView->setIndexWidget(model->index(i, 6), edit_btn);
			ui.tableView->setIndexWidget(model->index(i, 7), postpone_btn);
			ui.tableView->setIndexWidget(model->index(i, 8), delete_btn);
			connect(postpone_btn, SIGNAL(clicked()), this, SLOT(postponeTaskBtn()));
			connect(delete_btn, SIGNAL(clicked()), this, SLOT(deleteTaskBtn()));

			pqTemp.pop();
		}
	}
	else if (sortingCriteria == SortingCriteria::deadlineReversed) {
		priority_queue<Task, vector<Task>, CompareDeadline> pqTemp = *m_pqDeadline;

		model->setRowCount(pqTemp.size());

		for (int i = pqTemp.size() - 1; !pqTemp.empty(); i--) {

			edit_btn = new customButton("edit");
			postpone_btn = new customButton("postpone");
			delete_btn = new customButton("delete");
			model->setData(model->index(i, 0), pqTemp.top().getId());
			model->setData(model->index(i, 1), pqTemp.top().getTitle().c_str());
			model->setData(model->index(i, 2), pqTemp.top().getDescription().c_str());
			model->setData(model->index(i, 3), pqTemp.top().getAssigningDate());
			model->setData(model->index(i, 4), pqTemp.top().getDeadline());
			model->setData(model->index(i, 5), pqTemp.top().getPriority());
			ui.tableView->setIndexWidget(model->index(i, 6), edit_btn);
			ui.tableView->setIndexWidget(model->index(i, 7), postpone_btn);
			ui.tableView->setIndexWidget(model->index(i, 8), delete_btn);
			connect(edit_btn, SIGNAL(clicked()), this, SLOT(editTaskBtn()));
			connect(postpone_btn, SIGNAL(clicked()), this, SLOT(postponeTaskBtn()));
			connect(delete_btn, SIGNAL(clicked()), this, SLOT(deleteTaskBtn()));

			pqTemp.pop();
		}
	}

}

void Dashboard::deleteTaskBtn()
{
	Task deletedTask(rowID);
	deletedTask.remove();
	refresh();
}

void Dashboard::editTaskBtn()
{
	edittask = new editTask();
	edittask->excuteqry(rowID);
	edittask->show();
}

void Dashboard::postponeTaskBtn()
{
	 postponetask = new postponeTask();
	 postponetask->excuteqry(rowID);
	postponetask->show();
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
	rowID = ui.tableView->currentIndex().siblingAtColumn(0).data().toInt();
	if (isClosed) {
		refresh();
	}

}

void Dashboard::on_tableView_doubleClicked()
{
	showtask = new showTask();
	showtask->excuteqry(rowID);
	showtask->show();
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
