#include "graphic_control_panel.h"

Graphic_control_panel::Graphic_control_panel(QWidget *parent)
    : QWidget(parent)
{
    choosedLabel = -1;
    QGridLayout * gridLayout = new QGridLayout(this);

    for (int i = 0; i < LABELS_COUNT; i++) {
        labels[i] = new QLabel();
        buttons[i] = new QPushButton(QString("pic") + QString::number(i + 1));

        QImage pic;
        QString image_path = QString("../pics/pic") + QString::number(i + 1) + QString(".jpg");
        pic.load(image_path);
        labels[i]->setPixmap(QPixmap::fromImage(pic.scaledToWidth(70)));

        labels[i]->setBuddy(buttons[i]);

        gridLayout->addWidget(labels[i], i / 3, (i % 3) * 2, Qt::AlignCenter);
        gridLayout->addWidget(buttons[i], i / 3, (i % 3) * 2 + 1, Qt::AlignCenter);
    }

    connect(buttons[0], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_1_released(bool)));
    connect(buttons[1], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_2_released(bool)));
    connect(buttons[2], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_3_released(bool)));
    connect(buttons[3], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_4_released(bool)));
    connect(buttons[4], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_5_released(bool)));
    connect(buttons[5], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_6_released(bool)));
    connect(buttons[6], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_7_released(bool)));
    connect(buttons[7], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_8_released(bool)));
    connect(buttons[8], SIGNAL(clicked(bool)), this, SLOT(on_pushButton_9_released(bool)));
}

void Graphic_control_panel::on_pushButton_1_released(bool clicked) {
    choosedLabel = 0;
    emit labelClicked(1);
}

void Graphic_control_panel::on_pushButton_2_released(bool clicked) {
    choosedLabel = 1;
    emit labelClicked(2);
}

void Graphic_control_panel::on_pushButton_3_released(bool clicked) {
    choosedLabel = 2;
    emit labelClicked(3);
}

void Graphic_control_panel::on_pushButton_4_released(bool clicked) {
    choosedLabel = 3;
    emit labelClicked(4);
}

void Graphic_control_panel::on_pushButton_5_released(bool clicked) {
    choosedLabel = 4;
    emit labelClicked(5);
}

void Graphic_control_panel::on_pushButton_6_released(bool clicked) {
    choosedLabel = 5;
    emit labelClicked(6);
}

void Graphic_control_panel::on_pushButton_7_released(bool clicked) {
    choosedLabel = 6;
    emit labelClicked(7);
}

void Graphic_control_panel::on_pushButton_8_released(bool clicked) {
    choosedLabel = 7;
    emit labelClicked(8);
}

void Graphic_control_panel::on_pushButton_9_released(bool clicked) {
    choosedLabel = 8;
    emit labelClicked(9);
}

QList<bool> Graphic_control_panel::getLabelsStates() {
    QList<bool> states;

    for (int i = 0; i < LABELS_COUNT; i++) {
        states.append(i == choosedLabel);
    }

    return states;
}

Graphic_control_panel::~Graphic_control_panel() {}

