#ifndef OPOSSUM_H
#define OPOSSUM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QCursor>
#include <QFont>
#include <QMessageBox>

class Opossum : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Opossum(QObject * parent = 0);
    ~Opossum();

    bool isSleep = true;
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

#endif // OPOSSUM_H
