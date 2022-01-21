#include "square.h"

Square::Square(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    _rect = QRectF(-50, -50, 100, 100);
}

Square::~Square() {}

QRectF Square::boundingRect() const
{
    return _rect;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if (isTranformed) {
        painter->setBrush(Qt::black);
        painter->drawRect(_rect.x(), _rect.y(), _rect.width(), _rect.height());
        painter->setBrush(Qt::white);
        painter->drawRect(_rect.x() * 0.9, _rect.y() * 0.9, _rect.width() * 0.9, _rect.height() * 0.9);
    } else {
        painter->setBrush(Qt::white);
        painter->drawRect(_rect.x(), _rect.y() * 0.7, _rect.width(), _rect.height() * 0.7);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Square::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    this->setPos(mapToScene( event->pos() ));
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(event->button() == Qt::LeftButton) {
        this->setCursor( QCursor(Qt::ClosedHandCursor) );
    } else {
        isTranformed = !isTranformed;
        update();
    }
    Q_UNUSED(event);
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    this->setCursor( QCursor(Qt::ArrowCursor) );
    Q_UNUSED(event);
}
