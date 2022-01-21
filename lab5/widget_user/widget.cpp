#include "widget.h"
#include "ui_widget.h"

#include <QList>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->widget, SIGNAL(labelClicked(int)), this, SLOT(on_graphic_control_panel_clicked(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_graphic_control_panel_clicked(int labelID) {
    QImage pic;
    QString image_path = QString("../pics/pic") + QString::number(labelID) + QString(".jpg");
    pic.load(image_path);
    ui->label->setPixmap(QPixmap::fromImage( pic.scaledToWidth(ui->label->width()) ));
}

void Widget::on_pushButton_clicked()
{
    QList<bool> labels_states = ui->widget->getLabelsStates();
    QString states_msg;
    for (int i = 0; i < labels_states.size(); i++) {
        states_msg.append( "Label " );
        states_msg.append( QString::number(i + 1) );
        states_msg.append( labels_states.at(i) ? " choosed\n" : " not choosed\n" );
    }
    QMessageBox msgBox;
    msgBox.setText(states_msg);
    msgBox.exec();
}
