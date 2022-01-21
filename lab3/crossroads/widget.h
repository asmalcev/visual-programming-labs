#ifndef WIDGET_H
#define WIDGET_H

#include "model.hpp"

#include <QWidget>
#include <QTime>
#include <QListView>

namespace Ui {
class Widget;
}

enum path {
    NS, // north-south
    SN, // south-north
    WE, // west-east
    EW  // east-west
};

struct car_data {
    enum path _path;
    int number;
    int index;
    QTime arriveTime;
    QTime spentTime;
};

const QTime TRAFFIC_LIGHTS_INTERVAL = QTime(0, 10);
const QTime CAR_CROSSROADS_TIME = QTime(0, 2);

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QListView * modelsListView[4];
    CrossroadsModel * models[5];
    car_data * cars_data;

    void generateCars(int count);
    void startSimulation(int count);
};

#endif // WIDGET_H
