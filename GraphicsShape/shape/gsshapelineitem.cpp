#include "gsshapelineitem.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QVector2D>

GsShapeLineItem::GsShapeLineItem(QRectF rectF, QGraphicsObject *parent):
    GsShapeBaseItem(rectF,parent)
{
}

GsShapeLineItem::~GsShapeLineItem()
{

}

bool GsShapeLineItem::hasSelected(const QPointF& pos)
{
    //判断点是否在直线上
    QPainterPath path;

    path.addRect(boundingRect());

    return path.contains(pos);
}

GsShapeType GsShapeLineItem::shapeType() const
{
    return Shape_Line;
}

void GsShapeLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(m_vecPoints.isEmpty())
    {
        return;
    }
    QPointF firstPoint = m_vecPoints.first();
    QPointF lastPoint = m_vecPoints.last();
    painter->setRenderHint(QPainter::Antialiasing);
    QColor color = Qt::red;//(rand()%255,rand()%255,rand()%255);
    painter->setPen(QPen(color,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin));
    painter->setBrush(color);
    painter->drawLine(firstPoint,lastPoint);
}
