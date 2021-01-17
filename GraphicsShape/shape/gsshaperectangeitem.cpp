#include "gsshaperectangeitem.h"
#include <QPainter>

GsShapeRectangeItem::GsShapeRectangeItem(QRectF rectF, QGraphicsObject *parent):
    GsShapeBaseItem(rectF,parent)
{

}

GsShapeRectangeItem::~GsShapeRectangeItem()
{

}

bool GsShapeRectangeItem::hasSelected(const QPointF& pos)
{
    return shape().contains(pos);
}

GsShapeType GsShapeRectangeItem::shapeType() const
{
    return Shape_Rectange;
}

void GsShapeRectangeItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(m_vecPoints.isEmpty())
    {
        return;
    }
    QPointF firstPoint = m_vecPoints.first();
    QPointF lastPoint = m_vecPoints.last();
    painter->setRenderHint(QPainter::Antialiasing);
    QColor color = Qt::red;//(rand()%255,rand()%255,rand()%255);
    painter->setBrush(color);
    painter->setPen(QPen(color,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->drawRect(QRectF(firstPoint,lastPoint));
}
