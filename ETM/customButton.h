#pragma once
#include <QPushButton>
class customButton :public QPushButton {
public:
	explicit customButton(const QString type,QWidget* parent = 0): QPushButton(type,parent) {
		setText("");
		QIcon icon1;
		if (type == "edit") {
			icon1.addFile(QString::fromUtf8("res/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
		}
		else if (type=="postpone") {
			icon1.addFile(QString::fromUtf8("res/calendar.png"), QSize(), QIcon::Normal, QIcon::Off);
		}
		else {
			icon1.addFile(QString::fromUtf8("res/done.png"), QSize(), QIcon::Normal, QIcon::Off);

		}
			setIcon(icon1);
		setIconSize(QSize(16,16));
		setStyleSheet("border:none;");
		



	}
};
