#include "Dashboard.h"
#include "ETM.h"

Dashboard::Dashboard(Employee user, QWidget* parent)
	: m_user(user), QWidget(parent)
{
	this->setFixedSize(800, 600);
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	ui.label->setText("Hi User"); //m_user.getFirstName().c_str()
	//getTasks(SortingCriteria::priority);
}

Dashboard::~Dashboard()
{
}

void Dashboard::getTasks(SortingCriteria sortingCriteria)
{
	if (sortingCriteria == SortingCriteria::priority) {
		priority_queue<Task, vector<Task>, ComparePriority> pq;

		opendb();

		QSqlQuery qry;
		qry.prepare("select id from task where employeeUsername = :m_username");
		qry.bindValue(":m_username", m_user.getUsername().c_str());
		cout << m_user.getUsername().c_str() << endl;

		if (qry.exec()) {
			cout << "Exec\n";
			while (qry.next()) {
				cout << "May!";
				Task task(qry.value(0).toInt());
				//pq.push(task);
			}
		}

		qry.clear();
		closedb();

		// viewTasks();
	}
	else if (sortingCriteria == SortingCriteria::deadline) {
		priority_queue<Task, vector<Task>, CompareDeadline> pq;

		QSqlDatabase db; db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("../Database/ETM_database.db");
		db.open();

		QSqlQuery qry;
		qry.prepare("select id from task where employeeUsername = :m_username");
		qry.bindValue(":m_username", m_user.getUsername().c_str());

		if (qry.exec()) {
			while (qry.next()) {
				cout << "May!";
				Task task(qry.value(0).toInt());
				pq.push(task);
			}
		}

		qry.clear();
		db.close();
		db.removeDatabase(QSqlDatabase::defaultConnection);

		// viewTasks();
	}
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

void Dashboard::retrieve()
{
}

void Dashboard::add()
{
}

void Dashboard::update()
{
}

void Dashboard::remove()
{
}
