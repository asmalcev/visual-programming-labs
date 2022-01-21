#include "widget.h"

Widget::Widget(QWidget *parent)
	: QWidget(parent)
{
    setWindowTitle("Task 2");

    scrollArea1 = new QScrollArea(this);
    scrollArea2 = new QScrollArea(this);

    QHBoxLayout * layout = new QHBoxLayout(this);
    layout->addWidget(scrollArea1);
    layout->addWidget(scrollArea2);

    treeWidget = new QTreeWidget(this);
    listWidget = new QListWidget(this);

    scrollArea1->setWidget(treeWidget);
    scrollArea2->setWidget(listWidget);

    treeWidget->setColumnCount(1);

    QTreeWidgetItem * home = new QTreeWidgetItem(treeWidget);
    home->setText(0, tr("home/"));

    QTreeWidgetItem * username = new QTreeWidgetItem(home);
    username->setText(0, tr("username/"));

    QTreeWidgetItem * Desktop = new QTreeWidgetItem(username);
    Desktop->setText(0, tr("Desktop/"));
    QTreeWidgetItem * Documents = new QTreeWidgetItem(username);
    Documents->setText(0, tr("Documents/"));
    QTreeWidgetItem * Downloads = new QTreeWidgetItem(username);
    Downloads->setText(0, tr("Downloads/"));
    QTreeWidgetItem * Pictures = new QTreeWidgetItem(username);
    Pictures->setText(0, tr("Pictures/"));
    QTreeWidgetItem * Projects = new QTreeWidgetItem(username);
    Projects->setText(0, tr("Projects/"));
    QTreeWidgetItem * Videos = new QTreeWidgetItem(username);
    Videos->setText(0, tr("Videos/"));

    QTreeWidgetItem * QtLabs = new QTreeWidgetItem(Projects);
    QtLabs->setText(0, tr("QtLabs/"));

    QTreeWidgetItem * lab1 = new QTreeWidgetItem(QtLabs);
    lab1->setText(0, tr("lab1/"));

    QTreeWidgetItem * maincpp = new QTreeWidgetItem(lab1);
    maincpp->setText(0, tr("main.cpp"));
    QTreeWidgetItem * mainhpp = new QTreeWidgetItem(lab1);
    mainhpp->setText(0, tr("main.hpp"));


    QListWidgetItem * list_maincpp = new QListWidgetItem(tr("main.cpp"), listWidget);
    QListWidgetItem * list_mainhpp = new QListWidgetItem(tr("main.hpp"), listWidget);
}

Widget::~Widget()
{

}
