#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem * item, int column);

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;

    void countNewSum(QTreeWidgetItem * item);
};

#endif // WIDGET_H
