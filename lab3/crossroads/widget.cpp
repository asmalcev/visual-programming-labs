#include "widget.h"
#include "ui_widget.h"

#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

#include <QScrollArea>
#include <QInputDialog>

#include <QStringList>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    for (int i = 0; i < 4; i++) {
        modelsListView[i] = new QListView();
        models[i] = new CrossroadsModel(this);
        modelsListView[i]->setModel(models[i]);

        ui->verticalLayout_2->addWidget(modelsListView[i]);
    }

}

Widget::~Widget()
{
    delete ui;
    delete[] cars_data;
}

void Widget::on_pushButton_clicked()
{
    bool ok;
    int count = QInputDialog::getInt(this,
        tr("Enter the count of cars"),
        tr("Count:"),
        10, 0, 1000, 1,
        &ok
    );
    if (ok) {
        generateCars(count);
        startSimulation(count);
    }
}

void Widget::generateCars(int count) {
    srand(time(0));
    cars_data = new car_data[count]();

    QStringList modelsStrings[5];

    modelsStrings[0] << "North-South\n";
    modelsStrings[1] << "South-North\n";
    modelsStrings[2] << "West-East\n";
    modelsStrings[3] << "East-West\n";

    for (int i = 0; i < count; i++) {
        int pathType = rand() % 4;

        cars_data[i].number = i;
        cars_data[i].arriveTime = QTime( rand() % 24, rand() % 60);
        cars_data[i].spentTime = QTime(0, 0);

        QString text = QString::number(i) + " car\n" +
                "arrived: " + cars_data[i].arriveTime.toString() +
                "\nspent: " + cars_data[i].spentTime.toString() + "\n";

        if (pathType == 0) {

            cars_data[i]._path = path::NS;
            cars_data[i].index = modelsStrings[0].count();
            modelsStrings[0] << text;

        } else if (pathType == 1) {

            cars_data[i]._path = path::SN;
            cars_data[i].index = modelsStrings[1].count();
            modelsStrings[1] << text;

        } else if (pathType == 2) {

            cars_data[i]._path = path::WE;
            cars_data[i].index = modelsStrings[2].count();
            modelsStrings[2] << text;

        } else if (pathType == 3) {

            cars_data[i]._path = path::EW;
            cars_data[i].index = modelsStrings[3].count();
            modelsStrings[3] << text;

        }
    }

    models[0]->setStringList( modelsStrings[0] );
    models[1]->setStringList( modelsStrings[1] );
    models[2]->setStringList( modelsStrings[2] );
    models[3]->setStringList( modelsStrings[3] );
}

int qtimeToInt(const QTime & time) {
    return time.hour() * 60 + time.minute();
}

void Widget::startSimulation(int count) {
    std::sort(cars_data, cars_data + count, [](car_data car1, car_data car2) {
        return car1.arriveTime < car2.arriveTime;
    });

    QStringList msl;
    msl << "Start the simulation\n";

    const int TLI = qtimeToInt(TRAFFIC_LIGHTS_INTERVAL);
    for (int i = 0; i < count; i++)
    {
        bool isHorizontal = (qtimeToInt(cars_data[i].arriveTime) / TLI) % 2;
        QTime spentTime;

        if (
            (isHorizontal && (cars_data[i]._path == path::WE || cars_data[i]._path == path::EW)) ||
            (!isHorizontal && (cars_data[i]._path == path::NS || cars_data[i]._path == path::SN))
        ) {
            spentTime = CAR_CROSSROADS_TIME;
        } else {
            spentTime = QTime(TRAFFIC_LIGHTS_INTERVAL.hour() + CAR_CROSSROADS_TIME.hour(), TRAFFIC_LIGHTS_INTERVAL.minute() + CAR_CROSSROADS_TIME.minute());
        }
        QString text = QString::number(cars_data[i].number) + " car\n" +
                "arrived: " + cars_data[i].arriveTime.toString() +
                "\nspent: " + spentTime.toString() + "\n";
        msl << text;

        models[ cars_data[i]._path ]->_list.replace( cars_data[i].index, text );
    }

    msl << "The simulation ended";

    models[4] = new CrossroadsModel(this);
    models[4]->setStringList( msl );
    ui->listView->setModel( models[4] );
}
