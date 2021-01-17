#include "gsrootitem.h"
#include <QDebug>
#include "gsshapebaseitem.h"
#include "gsshapelineitem.h"
#include <QGraphicsScene>
#include <QtMath>

GsRootItem::GsRootItem(const QSizeF &size, QGraphicsObject *parent):
    QGraphicsObject (parent),
    m_size(size)
{
    m_pTempLayer = new GsTempCanvasLayer(size,this);
    m_pTempLayer->setZValue(10);

    m_pShapeFactory = new GsShapeFactory();
}

GsRootItem::~GsRootItem()
{
    SAFE_DELETE(m_pShapeFactory);
}

void GsRootItem::drawPress(int id, const QPointF &p)
{
    if (m_vecPoints.isEmpty())
    {
        m_vecPoints.append(p);
    }
    ShapeInfo info;
    info.firstPos = p;
    info.type = getCurType();
    m_Objs.insert(id,info);
}

void GsRootItem::drawMove(int id, const QPointF &lastPoint, const QPointF &curPoint)
{
    Q_UNUSED(lastPoint);
    if(!m_Objs.contains(id)){
        return;
    }
    if (m_curType == Shape_Pen)
    {
        m_vecPoints.append(curPoint);
    }
    ShapeInfo info = m_Objs.value(id);
    m_pTempLayer->drawShape(info.type, m_vecPoints, curPoint);
}

void GsRootItem::drawRelease(int id, const QPointF &point)
{
    if(!m_Objs.contains(id)){
        return;
    }
    ShapeInfo info = m_Objs.value(id);

    switch (m_curType) {
    case Shape_Polygon:
    {
        qreal len = (qPow(m_vecPoints.first().x() - point.x() , 2.0) + qPow(m_vecPoints.first().y() - point.y() , 2.0) );
        if(m_vecPoints.count() >= 3)
        {
            if (len < 50 && m_vecPoints.size() >= 3)
            {
                drawRealShape(m_curType, m_vecPoints);
                m_Objs.remove(id);
                m_pTempLayer->clear();
                return;
            }
        }
        // 处理初始拖动绘制
        if (len < 5 && m_vecPoints.size() == 2)
        {
            return;
        }
        m_vecPoints.append(point);
        update();
    }
        break;
    default:
        m_vecPoints.append(point);
        drawRealShape(info.type,m_vecPoints);
        m_Objs.remove(id);
        m_pTempLayer->clear();
        break;
    }
}

void GsRootItem::clear()
{
    QList<QGraphicsItem*> items = this->childItems();
    QList<QGraphicsItem*>::iterator it = items.begin();
    while(it != items.end()){
        QGraphicsItem* item = *it++;
        if(item->type() == Type_ShapeItem){
            delete item;
            item = nullptr;
        }
    }
}

QRectF GsRootItem::boundingRect() const
{
    return  QRectF(0,0,m_size.width(),m_size.height());
}

void GsRootItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    QImage pixmap("d:\\test2.bmp");
    painter->drawImage(this->boundingRect(), pixmap);
//    painter->setPen(Qt::NoPen);
//    painter->setBrush(Qt::white);
//    painter->drawRect(this->boundingRect());
}

void GsRootItem::drawRealShape(GsShapeType type, const QVector<QPointF> &vecPoint)
{
    //计算图形绘制区域    
    if(vecPoint.isEmpty())
    {
        return;
    }
    QRectF rect;
    CalShapeRegion(type, rect, vecPoint);
    GsShapeBaseItem * item = m_pShapeFactory->getShapeItem(type,rect,this);
    item->drawShape(vecPoint);
    m_vecPoints.clear();
}

void GsRootItem::CalShapeRegion(GsShapeType type, QRectF &rect, const QVector<QPointF> &vecPoints)
{
    switch (type) {
    case Shape_Polygon:
    {
        qreal minx = vecPoints.first().x();
        qreal maxx = vecPoints.first().x();
        qreal miny = vecPoints.first().y();
        qreal maxy = vecPoints.first().y();

        auto iter = vecPoints.begin();
        while(iter != vecPoints.end())
        {
            minx = qMin(minx, (*iter).x());
            maxx = qMax(maxx, (*iter).x());
            miny = qMin(miny, (*iter).y());
            maxy = qMax(maxy, (*iter).y());
            ++iter;
        }
        rect.setX(minx);
        rect.setY(miny);
        rect.setWidth(maxx - minx);
        rect.setHeight(maxy - miny);
//        rect.adjust(0, 0, 0, 0);
    }
        break;
    default:
    {
        QPointF p1 = m_vecPoints.first();
        QPointF p2 = m_vecPoints.last();
        rect.setX(qMin(p1.x(),p2.x()));
        rect.setY(qMin(p1.y(),p2.y()));
        if(type == Shape_Circle){
            rect.setWidth(qAbs(p1.y() - p2.y()));
            rect.setHeight(qAbs(p1.y() - p2.y()));
        }
        else{
            rect.setWidth(qAbs(p1.x() - p2.x()));
            rect.setHeight(qAbs(p1.y() - p2.y()));
        }
    }
        break;
    }

}
