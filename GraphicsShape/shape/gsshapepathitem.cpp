#include "gsshapepathitem.h"
#include <QPainter>

GsShapePathItem::GsShapePathItem(QRectF rectF, QGraphicsObject *parent)
    : GsShapeBaseItem(rectF,parent)
{

}

GsShapePathItem::~GsShapePathItem()
{

}

bool GsShapePathItem::hasSelected(const QPointF &pos)
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path.contains(pos);
}

GsShapeType GsShapePathItem::shapeType() const
{
    return Shape_Pen;
}

void GsShapePathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setRenderHint(QPainter::Antialiasing);
    QColor color = Qt::red;
    painter->setPen(QPen(color, 2, Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->setBrush(color);
    painter->drawPolyline(m_vecPoints);
}
