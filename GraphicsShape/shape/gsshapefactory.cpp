#include "gsshapefactory.h"
#include "gsshapelineitem.h"
#include "gsshaperectangeitem.h"
#include "gsshapecircleitem.h"
#include "gsshapeovalitem.h"
#include "gsshapepolygonitem.h"
#include "gsshapepathitem.h"

GsShapeFactory::GsShapeFactory()
{

}

GsShapeFactory::~GsShapeFactory()
{

}

GsShapeBaseItem *GsShapeFactory::getShapeItem(GsShapeType type,QRectF rectF,
                                              QGraphicsObject *parent)
{
    GsShapeBaseItem * item = nullptr;
    switch (type) {
    case Shape_Line:
        item = new GsShapeLineItem(rectF,parent);
        break;
    case Shape_Rectange:
        item = new GsShapeRectangeItem(rectF,parent);
        break;
    case Shape_Circle:
        item = new GsShapeCircleItem(rectF,parent);
        break;
    case Shape_Oval:
        item = new GsShapeOvalItem(rectF,parent);
        break;
    case Shape_Polygon:
        item = new GsShapePolygonItem(rectF, parent);
        break;
    case Shape_Pen:
        item = new GsShapePathItem(rectF, parent);
        break;
    default:
        break;
    }
    item->setZValue(10);
    return item;
}
