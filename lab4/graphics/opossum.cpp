#include "opossum.h"

Opossum::Opossum(QObject *parent):
    QObject(parent), QGraphicsItem()
{
    _rect = QRectF(-80, -20, 160, 40);
}

Opossum::~Opossum() {}

QRectF Opossum::boundingRect() const
{
    return _rect;
}

void Opossum::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    if (isSleep) {
        painter->setPen(Qt::black);
        painter->setFont(QFont("Helvetica", 14));
        painter->drawText(_rect, Qt::AlignCenter, "Опоссум спит");
    } else {
        painter->setPen(Qt::red);
        painter->setFont(QFont("Helvetica", 14));
        painter->drawText(_rect, Qt::AlignCenter, "AAAAAA");
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Opossum::mouseMoveEvent(QGraphicsSceneMouseEvent * event)
{
    this->setPos(mapToScene( event->pos() ));
}

void Opossum::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    if (event->button() == Qt::LeftButton) {
        this->setCursor( QCursor(Qt::ClosedHandCursor) );
    } else if (isSleep) {
        isSleep = false;
        update();

        QMessageBox msgBox;
        msgBox.setText("You woken up opossum :(");
        msgBox.exec();
    }
}

void Opossum::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor( QCursor(Qt::ArrowCursor) );
    Q_UNUSED(event);
}
