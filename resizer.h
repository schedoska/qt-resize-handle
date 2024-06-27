#ifndef RESIZER_H
#define RESIZER_H

#include "resize_handler.h"
#include "item.h"
#include <QGraphicsScene>
#include <QDebug>

class Resizer
{
    Resize_Handler *top;
    Resize_Handler *right;
    Resize_Handler *down;
    Resize_Handler *left;
    Resize_Handler *frame;

    bool czy_tryb_edycji = false;

    QGraphicsScene *scena;

public:
    void Tryb_edycji_ON(Itemek *Edytowany_obiekt);

    void Delete_current_Handlers();
    void Update_resizeHands_pos();

    Resizer(QGraphicsScene *scn);
};

#endif // RESIZER_H
