#ifndef SCENA__H
#define SCENA__H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "resizer.h"
#include "item.h"

enum Mode_ofWork{ADD_NEW, EDIT, DELETE, NOTHING};

class Scena_Nueva: public QGraphicsScene
{
    Mode_ofWork tryb_pracy = NOTHING;
    Resizer *edytor_rozmiaru;

    Itemek *edytowany_aktualnie_item;

public:
    Scena_Nueva();
    void mousePressEvent(QGraphicsSceneMouseEvent *evnt);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *evnt);

public slots:
    void set_ADD(bool tog) {if(tog) tryb_pracy = ADD_NEW;}
    void set_EDIT(bool tog) {if(tog) tryb_pracy = EDIT;}
    void set_DELETE(bool tog);
    void set_NOTHING(bool tog) {if(!tog) tryb_pracy = NOTHING;}
};

#endif // SCENA__H
