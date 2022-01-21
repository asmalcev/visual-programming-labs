#ifndef FLAG_H
#define FLAG_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class Flag : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Flag(QObject * parent = 0);
    ~Flag();

    bool isTranformed = true;
    QRectF _rect;

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

public slots:
};

#endif // FLAG_H
