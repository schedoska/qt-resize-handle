#include "resize_handler.h"
#include <QDebug>
#include <QBrush>
#include <QPen>

#define SKALA 3
#define ODLEGLOSCY_STRZALEK 13
#define FRAME_ODL 6

Resize_Handler::Resize_Handler(Rodzaj_Resizera rodz, Itemek* Edyt)
{
    QPolygon pls;
    rodzaj = rodz;

    if(rodz == TOP){
        pls << QPoint(0,-5) << QPoint(5,0) << QPoint(-5,0);
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::NoPen));
        setPolygon(pls);
        setScale(SKALA);
    }
    else if(rodz == RIGHT){
        pls << QPoint(5,0) << QPoint(0,5) << QPoint(0,-5);
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::NoPen));
        setPolygon(pls);
        setScale(SKALA);
    }
    else if(rodz == DOWN){
        pls << QPoint(0, 5) << QPoint(-5, 0) << QPoint(5, 0);
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::NoPen));
        setPolygon(pls);
        setScale(SKALA);
    }
    else if(rodz == LEFT){
        pls << QPoint(-5,0) << QPoint(0,5) << QPoint(0,-5);
        setBrush(QBrush(Qt::black));
        setPen(QPen(Qt::NoPen));
        setPolygon(pls);
        setScale(SKALA);
    }
    else if(rodz == FRAME){
        pls << QPoint(-FRAME_ODL,-FRAME_ODL) << QPoint(Edyt->rozmiar.width() + FRAME_ODL, -FRAME_ODL)
            << QPoint(Edyt->rozmiar.width() + FRAME_ODL, Edyt->rozmiar.height() + FRAME_ODL)
            << QPoint(-FRAME_ODL,Edyt->rozmiar.height() + FRAME_ODL);
        QPen dlugosz;
        dlugosz.setStyle(Qt::DashLine);
        dlugosz.setWidth(2);
        setPen(dlugosz);
        setPolygon(pls);
    }

    setPos(50,50);
    Edytowany_obiekt = Edyt;

    setAcceptHoverEvents(1);
}

void Resize_Handler::Update_pos()
{
    QPointF pozycja;

    if(rodzaj == TOP){
        pozycja.setX(Edytowany_obiekt->rozmiar.center().x());
        pozycja.setY(Edytowany_obiekt->rozmiar.top()-ODLEGLOSCY_STRZALEK);
    }
    else if(rodzaj == RIGHT){
        pozycja.setX(Edytowany_obiekt->rozmiar.right()+ODLEGLOSCY_STRZALEK);
        pozycja.setY(Edytowany_obiekt->rozmiar.center().y());
    }
    else if(rodzaj == DOWN){
        pozycja.setX(Edytowany_obiekt->rozmiar.center().x());
        pozycja.setY(Edytowany_obiekt->rozmiar.bottom()+ODLEGLOSCY_STRZALEK);
    }
    else if(rodzaj == LEFT){
        pozycja.setX(Edytowany_obiekt->rozmiar.left()-ODLEGLOSCY_STRZALEK);
        pozycja.setY(Edytowany_obiekt->rozmiar.center().y());
    }
    else if(rodzaj == FRAME){
        pozycja = Edytowany_obiekt->rozmiar.topLeft();
        QPolygon pls;
            pls << QPoint(-FRAME_ODL,-FRAME_ODL)
                << QPoint(Edytowany_obiekt->rozmiar.width() + FRAME_ODL, -FRAME_ODL)
                << QPoint(Edytowany_obiekt->rozmiar.width() + FRAME_ODL, Edytowany_obiekt->rozmiar.height() + FRAME_ODL)
                << QPoint(-FRAME_ODL,Edytowany_obiekt->rozmiar.height() + FRAME_ODL);
        setPolygon(pls);
    }
    setPos(pozycja);
}

void Resize_Handler::mousePressEvent(QGraphicsSceneMouseEvent *evento)
{
    Pozycja_poczatku_klikniecia = evento->scenePos();
    kwadrat_poczatku_klikniecia = Edytowany_obiekt->rozmiar;
}

void Resize_Handler::mouseMoveEvent(QGraphicsSceneMouseEvent *evento)
{
    float delta;

    if(rodzaj == TOP){
        delta = kwadrat_poczatku_klikniecia.top()-Pozycja_poczatku_klikniecia.y();
        QRectF kwadrat = Edytowany_obiekt->rozmiar;
        kwadrat.setTop(evento->scenePos().y() + delta);
        Edytowany_obiekt->rozmiar = kwadrat;
        Edytowany_obiekt->Update_size();
    }
    else if(rodzaj == RIGHT){
        delta = Pozycja_poczatku_klikniecia.x() - kwadrat_poczatku_klikniecia.right();
        QRectF kwadrat = Edytowany_obiekt->rozmiar;
        kwadrat.setRight(evento->scenePos().x() - delta);
        Edytowany_obiekt->rozmiar = kwadrat;
        Edytowany_obiekt->Update_size();
    }
    else if(rodzaj == DOWN){
        delta = kwadrat_poczatku_klikniecia.bottom() - Pozycja_poczatku_klikniecia.y();
        QRectF kwadrat = Edytowany_obiekt->rozmiar;
        kwadrat.setBottom(evento->scenePos().y() + delta);
        Edytowany_obiekt->rozmiar = kwadrat;
        Edytowany_obiekt->Update_size();
    }
    else if(rodzaj == LEFT){
        delta = kwadrat_poczatku_klikniecia.left() - Pozycja_poczatku_klikniecia.x();
        QRectF kwadrat = Edytowany_obiekt->rozmiar;
        kwadrat.setLeft(evento->scenePos().x() + delta);
        Edytowany_obiekt->rozmiar = kwadrat;
        Edytowany_obiekt->Update_size();
    }
}

void Resize_Handler::hoverEnterEvent(QGraphicsSceneHoverEvent *evento)
{
    if(rodzaj == FRAME) return;

    setBrush(QBrush(QColor(145,145,145)));
}

void Resize_Handler::hoverLeaveEvent(QGraphicsSceneHoverEvent *evento)
{
    if(rodzaj == FRAME) return;

    setBrush(QBrush(Qt::black));
}
