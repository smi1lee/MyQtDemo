#include "gsshapebaseitem.h"

GsShapeBaseItem::GsShapeBaseItem(QRectF rectF,QGraphicsObject *parent):
    QGraphicsObject(parent),
    m_boundRectF(rectF)
{
    setFlag(ItemIsSelectable,true);
    setFlag(ItemIsMovable,true);
//    setAcceptHoverEvents(true);
}

GsShapeBaseItem::~GsShapeBaseItem()
{

}

int GsShapeBaseItem::type() const
{
    return Type_ShapeItem;
}

void GsShapeBaseItem::drawShape(const QVector<QPointF>& vecPoints)
{
    m_vecPoints = vecPoints;
    update();
}

QRectF GsShapeBaseItem::boundingRect() const
{
    return m_boundRectF;
}
