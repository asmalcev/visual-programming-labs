#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget
{
	Q_OBJECT

	QScrollArea * scrollArea1;
	QScrollArea * scrollArea2;

	QTreeWidget * treeWidget;
	QListWidget * listWidget;

public:
	Widget(QWidget *parent = 0);
	~Widget();
};

#endif // WIDGET_H
