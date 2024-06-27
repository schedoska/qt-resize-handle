#ifndef OKNO_H
#define OKNO_H

#include <QWidget>
#include <QGraphicsView>
#include <QRadioButton>
#include "scena_.h"

class OKno: public QWidget
{
    QGraphicsView *obraz;
    Scena_Nueva *scene;

    void menu_init();

    QRadioButton *Add_new;
    QRadioButton *Edit;
    QRadioButton *Delete;

public:
    OKno();

public slots:
    void set_enable_disable(bool tog);
};

#endif // OKNO_H
