#include "flag.h"

Flag::Flag(QObject *parent):
    QObject(parent), QGraphicsItem()

{
    _rect = QRect(-67, -45, 135, 90);
}

Flag::~Flag() {}

QRectF Flag::boundingRect() const
{
    return _rect;
}

void Flag::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if (isTranformed) {
        painter->setBrush(Qt::red);
        painter->drawRect(_rect.x(), _rect.y(), _rect.width(), _rect.height());
        painter->setBrush(Qt::white);
        painter->drawRect(_rect.x(), _rect.height() / 6 + _rect.y(), _rect.width(), _rect.height() / 3 * 2);
        painter->setBrush(Qt::darkBlue);
        painter->drawRect(_rect.x(), _rect.height() / 3 + _rect.y(), _rect.width(), _rect.height() / 3);
    } else {
        painter->setBrush(Qt::yellow);
        painter->drawRect(_rect.x(), _rect.y(), _rect.width(), _rect.height() / 3);
        painter->setBrush(Qt::green);
        painter->drawRect(_rect.x(), _rect.height() / 3 + _rect.y(), _rect.width(), _rect.height() / 3);
        painter->setBrush(Qt::red);
        painter->drawRect(_rect.x(), _rect.height() / 3 * 2 + _rect.y(), _rect.width(), _rect.height() / 3);

        QPainterPath star;
        star.moveTo(0, 20 + _rect.y());
        star.lineTo(73 + _rect.x(), 39 + _rect.y());
        star.lineTo(95 + _rect.x(), 39 + _rect.y());
        star.lineTo(78 + _rect.x(), 51 + _rect.y());
        star.lineTo(85 + _rect.x(), 70 + _rect.y());
        star.lineTo(68 + _rect.x(), 59 + _rect.y());
        star.lineTo(51 + _rect.x(), 69 + _rect.y());
        star.lineTo(57 + _rect.x(), 52 + _rect.y());
        star.lineTo(41 + _rect.x(), 39 + _rect.y());
        star.lineTo(61 + _rect.x(), 39 + _rect.y());
        star.lineTo(0, 20 + _rect.y());

        painter->setPen(Qt::black);
        painter->drawPath(star);
        painter->fillPath(star, Qt::white);
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Flag::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    this->setPos(mapToScene( event->pos() ));
}

void Flag::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if(event->button() == Qt::LeftButton) {
        this->setCursor( QCursor(Qt::ClosedHandCursor) );
    } else {
        isTranformed = !isTranformed;
        update();
    }
    Q_UNUSED(event);
}

void Flag::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    this->setCursor( QCursor(Qt::ArrowCursor) );
    Q_UNUSED(event);
}
