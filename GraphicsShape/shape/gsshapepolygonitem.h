#ifndef GSSHAPEPOLYGONITEM_H
#define GSSHAPEPOLYGONITEM_H

#include "gsshapebaseitem.h"
#include <QVector>
#include <QList>

class GsShapePolygonItem : public GsShapeBaseItem
{
public:
    explicit GsShapePolygonItem(QRectF rectF, QGraphicsObject* parent = 0);
    ~GsShapePolygonItem();
    virtual bool hasSelected(const QPointF& pos);
    virtual GsShapeType shapeType() const;

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = Q_NULLPTR);

private:
    QVector<QPointF> m_TempPoints;
    QList<QVector<QPointF>> m_Polygons;
};

#endif // GSSHAPEPOLYGONITEM_H
