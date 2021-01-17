#include "gsshapecircleitem.h"
#include <QPainter>

GsShapeCircleItem::GsShapeCircleItem(QRectF rectF, QGraphicsObject *parent):
    GsShapeBaseItem(rectF,parent)
{
}

GsShapeCircleItem::~GsShapeCircleItem()
{

}

bool GsShapeCircleItem::hasSelected(const QPointF& pos)
{
    QPainterPath path;
    path.addEllipse(boundingRect());

    return path.contains(pos);
}

GsShapeType GsShapeCircleItem::shapeType() const
{
    return Shape_Circle;
}

void GsShapeCircleItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

    painter->drawEllipse(firstPoint.x(),firstPoint.y(),
                         qAbs(lastPoint.y() - firstPoint.y()),
                         qAbs(lastPoint.y() - firstPoint.y()));
}
