#include "resizer.h"
#include <QDebug>

void Resizer::Update_resizeHands_pos()
{
    if(!czy_tryb_edycji) return;
    top->Update_pos();
    right->Update_pos();
    down->Update_pos();
    left->Update_pos();
    frame->Update_pos();
}

void Resizer::Delete_current_Handlers()
{
    czy_tryb_edycji = false;

    if(right){
        scena->removeItem(right);
        delete right;
        right = nullptr;

        scena->removeItem(top);
        delete top;
        top = nullptr;

        scena->removeItem(left);
        delete left;
        left = nullptr;

        scena->removeItem(down);
        delete down;
        down = nullptr;

        scena->removeItem(frame);
        delete frame;
        frame = nullptr;
    }
}

Resizer::Resizer(QGraphicsScene *scn)
{
    scena = scn;
    top = nullptr;
    right = nullptr;
    left = nullptr;
    down = nullptr;
    frame = nullptr;

    czy_tryb_edycji = false;
}

void Resizer::Tryb_edycji_ON(Itemek *Edytowany_obiektos)
{   
    Delete_current_Handlers();
    czy_tryb_edycji = true;

    top = new Resize_Handler(TOP, Edytowany_obiektos);
    scena->addItem(top);
    right = new Resize_Handler(RIGHT, Edytowany_obiektos);
    scena->addItem(right);
    down = new Resize_Handler(DOWN, Edytowany_obiektos);
    scena->addItem(down);
    left = new Resize_Handler(LEFT, Edytowany_obiektos);
    scena->addItem(left);

    frame = new Resize_Handler(FRAME, Edytowany_obiektos);
    scena->addItem(frame);

    Update_resizeHands_pos();
    qDebug() << frame;
}
