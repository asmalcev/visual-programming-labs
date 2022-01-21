#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QImage>
#include <QStringListModel>

#include "background.h"
#include "opossum.h"
#include "square.h"
#include "flag.h"

namespace Ui {
class Widget;
}

constexpr int margin = 16;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;

    QGraphicsScene * scene;

    QStringListModel * backgrounds;
    Background * bg;
};

#endif // WIDGET_H
