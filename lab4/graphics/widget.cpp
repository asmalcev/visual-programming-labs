#include "widget.h"
#include "ui_widget.h"

#include <QStringList>

#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->graphicsView->setMinimumWidth(512);
    ui->graphicsView->setMinimumHeight(512);
    scene->setSceneRect(0, 0, 496, 496);


    QStringList sl;
    sl << "Grass" << "Planks" << "Water";
    backgrounds = new QStringListModel(this);
    backgrounds->setStringList( sl );
    ui->comboBox->setModel( backgrounds );

    bg = new Background(
        nullptr,
        -margin * 2,
        -margin,
        ui->graphicsView->width() + margin * 4,
        ui->graphicsView->height() + margin * 2
    );
    bg->name = "../Grass.jpg";
    scene->addItem( bg );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_comboBox_activated(const QString &arg1)
{

    bg->name = "../" + arg1 + ".jpg";
    bg->update();

}

void Widget::on_pushButton_4_clicked()
{
    Opossum * opossum = new Opossum();
    scene->addItem( opossum );
}

void Widget::on_pushButton_2_clicked()
{
    scene->clear();

    bg = new Background(
        nullptr,
        -margin * 2,
        -margin,
        ui->graphicsView->width() + margin * 4,
        ui->graphicsView->height() + margin * 2
    );
    bg->name = "../Grass.jpg";
    scene->addItem( bg );
    ui->comboBox->setCurrentIndex(0);
}

void Widget::on_pushButton_3_clicked()
{
    Flag * flag = new Flag();
    scene->addItem( flag );
}

void Widget::on_pushButton_clicked()
{
    Square * square = new Square();
    scene->addItem( square );
}
