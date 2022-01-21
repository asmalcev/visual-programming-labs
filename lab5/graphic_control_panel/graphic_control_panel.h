#ifndef GRAPHIC_CONTROL_PANEL_H
#define GRAPHIC_CONTROL_PANEL_H

#include "graphic_control_panel_global.h"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QPushButton>
#include <QList>

#include <iostream>

QT_BEGIN_NAMESPACE

constexpr int LABELS_COUNT = 9;

class GRAPHIC_CONTROL_PANELSHARED_EXPORT Graphic_control_panel : public QWidget
{
    Q_OBJECT
public:
    explicit Graphic_control_panel(QWidget *Graphic_control_panel = nullptr);
    ~Graphic_control_panel() override;

    QList<bool> getLabelsStates();

signals:
    void labelClicked(int labelID);

private slots:

    void on_pushButton_1_released(bool clicked);
    void on_pushButton_2_released(bool clicked);
    void on_pushButton_3_released(bool clicked);
    void on_pushButton_4_released(bool clicked);
    void on_pushButton_5_released(bool clicked);
    void on_pushButton_6_released(bool clicked);
    void on_pushButton_7_released(bool clicked);
    void on_pushButton_8_released(bool clicked);
    void on_pushButton_9_released(bool clicked);

private:
    QLabel * labels[LABELS_COUNT];
    QPushButton * buttons[LABELS_COUNT];

    int choosedLabel;
};

#endif // GRAPHIC_CONTROL_PANEL_H
