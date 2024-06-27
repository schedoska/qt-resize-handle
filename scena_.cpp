#include "scena_.h"
#include "item.h"
#include <QDebug>
#include <QTransform>

Scena_Nueva::Scena_Nueva()
{
    edytor_rozmiaru = new Resizer(this);
}

void Scena_Nueva::mousePressEvent(QGraphicsSceneMouseEvent *evnt)
{
    QGraphicsScene::mousePressEvent(evnt);

    if(tryb_pracy == ADD_NEW){
        QPointF pkt = evnt->scenePos();
        pkt.setX(pkt.x()-30);
        pkt.setY(pkt.y()-30);
        Itemek *nowy = new Itemek(pkt);
        addItem(nowy);
    }

    if(tryb_pracy == EDIT && evnt->button() == Qt::LeftButton){
        QGraphicsItem *it = itemAt(evnt->scenePos(),QTransform());

        if(it == NULL){
            edytowany_aktualnie_item = NULL;
            edytor_rozmiaru->Delete_current_Handlers();
            return;
        }
        else if(it->type() != 1){
            return;
        }

        Itemek *klikniety_item = dynamic_cast<Itemek*>(it);
        if(klikniety_item == NULL) return;

        if(klikniety_item != edytowany_aktualnie_item){
            edytor_rozmiaru->Tryb_edycji_ON(klikniety_item);
            edytowany_aktualnie_item = klikniety_item;
        }
    }

    if(tryb_pracy == DELETE){
        QGraphicsItem *it = itemAt(evnt->scenePos(),QTransform());

        if(it == NULL){
            return;
        }
        else if(it->type() != 1){
            return;
        }

        Itemek *klikniety_item = dynamic_cast<Itemek*>(it);
        if(klikniety_item == NULL) return;

        removeItem(klikniety_item);
        delete klikniety_item;
    }
}

void Scena_Nueva::mouseMoveEvent(QGraphicsSceneMouseEvent *evnt)
{
    QGraphicsScene::mouseMoveEvent(evnt);
    if(tryb_pracy == EDIT) edytor_rozmiaru->Update_resizeHands_pos();
}

void Scena_Nueva::set_DELETE(bool tog)
{
    if(tog){
        tryb_pracy = DELETE;
        edytor_rozmiaru->Delete_current_Handlers();
    }
}
