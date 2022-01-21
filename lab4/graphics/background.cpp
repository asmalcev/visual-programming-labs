#include "background.h"

Background::Background(QObject * parent, int x, int y, int width, int height):
    QObject(parent), QGraphicsItem() {
    _rect = QRectF(x, y, width, height);
}

Background::~Background() {}

QRectF Background::boundingRect() const
{
    return _rect;
}

void Background::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->drawImage(_rect, QImage(name));

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
