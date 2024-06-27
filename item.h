#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Itemek: public QGraphicsRectItem
{
public:
    Itemek(QPointF pozy);

    int type() const override {return 1;}
    QRectF rozmiar;

    void Update_size();
};

#endif // ITEM_H
