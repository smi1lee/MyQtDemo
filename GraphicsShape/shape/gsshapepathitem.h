#ifndef GSSHAPEPATHITEM_H
#define GSSHAPEPATHITEM_H

#include "gsshapebaseitem.h"

class GsShapePathItem : public GsShapeBaseItem
{
public:
    explicit GsShapePathItem(QRectF rectF, QGraphicsObject *parent = 0);
    ~GsShapePathItem();
    bool hasSelected(const QPointF &pos) override;
    GsShapeType shapeType() const override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
};

#endif // GSSHAPEPATHITEM_H
