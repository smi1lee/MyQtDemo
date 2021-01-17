#include "gsshapeovalitem.h"
#include <QPainter>

GsShapeOvalItem::GsShapeOvalItem(QRectF rectF, QGraphicsObject *parent):
    GsShapeBaseItem(rectF,parent)
{
}

GsShapeOvalItem::~GsShapeOvalItem()
{

}

bool GsShapeOvalItem::hasSelected(const QPointF& pos)
{
    QPainterPath path;
    path.addEllipse(boundingRect());

    return path.contains(pos);
}

GsShapeType GsShapeOvalItem::shapeType() const
{
    return Shape_Line;
}

void GsShapeOvalItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter->drawEllipse(QRectF(firstPoint,lastPoint));
}
