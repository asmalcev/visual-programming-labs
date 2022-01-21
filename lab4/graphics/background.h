#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <QGraphicsItem>
#include <QString>
#include <QPainter>
#include <QImage>

class Background : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Background(QObject * parent = 0, int x = 0, int y = 0, int width = 100, int height = 100);
    ~Background();

    QString name;
    QRectF _rect;

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

private:

public slots:

};

#endif // BACKGROUND_H
