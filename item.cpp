#include "item.h"
#include <QBrush>
#include <QPen>

Itemek::Itemek(QPointF pozy)
{
    setRect(pozy.x(),pozy.y(),60,60);
    QBrush pedzel(QColor(30,165,150));
    setBrush(pedzel);

    QPen pdz(QColor(120,120,120));
    pdz.setWidth(3);
    setPen(pdz);
    rozmiar.setRect(pozy.x(),pozy.y(),60,60);
}

void Itemek::Update_size()
{
    setRect(rozmiar);
}

