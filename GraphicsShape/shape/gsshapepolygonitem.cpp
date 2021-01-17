#include "gsshapepolygonitem.h"
#include <QPainter>

GsShapePolygonItem::GsShapePolygonItem(QRectF rectF, QGraphicsObject *parent)
    : GsShapeBaseItem(rectF, parent)
{

}

GsShapePolygonItem::~GsShapePolygonItem()
{

}

bool GsShapePolygonItem::hasSelected(const QPointF &pos)
{
    QPainterPath path;
    QPolygonF polygon(m_TempPoints);
    path.addPolygon(polygon);

    return path.contains(pos);
}

GsShapeType GsShapePolygonItem::shapeType() const
{
    return Shape_Polygon;
}

void GsShapePolygonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();
    painter->setPen(QPen(QColor(34, 163, 169), 2));
    painter->setBrush(QColor(162, 121, 197));
    painter->drawPolygon(m_vecPoints);
    painter->restore();
}
