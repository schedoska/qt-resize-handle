#ifndef RESIZE_HANDLER_H
#define RESIZE_HANDLER_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include "item.h"

enum Rodzaj_Resizera{TOP, RIGHT, DOWN, LEFT, FRAME};

class Resize_Handler: public QGraphicsPolygonItem
{
    Rodzaj_Resizera rodzaj;
    Itemek *Edytowany_obiekt;

    QPointF Pozycja_poczatku_klikniecia;
    QRectF kwadrat_poczatku_klikniecia;

public:
    Resize_Handler(Rodzaj_Resizera rodz, Itemek* Edyt);
    void Update_pos();

    void mousePressEvent(QGraphicsSceneMouseEvent *evento);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *evento);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *evento);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *evento);
};

#endif // RESIZE_HANDLER_H
