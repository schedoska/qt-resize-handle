#include "okno.h"
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>

void OKno::menu_init()
{
    QCheckBox *Czy_edit_mode = new QCheckBox("Edit Area",this);
    Czy_edit_mode->setGeometry(850,40,100,50);

    QPushButton *Clear_all = new QPushButton("Clear", this);
    Clear_all->setGeometry(830,200,140,50);


    Add_new = new QRadioButton("Add new item",this);
    Add_new->setGeometry(850,80,120,50);
    Add_new->setEnabled(0);
    Edit = new QRadioButton("Edit item",this);
    Edit->setGeometry(850,110,120,50);
    Edit->setEnabled(0);
    Delete = new QRadioButton("Delete item",this);
    Delete->setGeometry(850,140,120,50);
    Delete->setEnabled(0);

    QObject::connect(Czy_edit_mode,&QCheckBox::toggled,this,&OKno::set_enable_disable);

    QObject::connect(Add_new, &QRadioButton::toggled, scene, &Scena_Nueva::set_ADD);
    QObject::connect(Edit, &QRadioButton::toggled, scene, &Scena_Nueva::set_EDIT);
    QObject::connect(Delete, &QRadioButton::toggled, scene, &Scena_Nueva::set_DELETE);
}

OKno::OKno()
{
    scene = new Scena_Nueva;
    scene->setSceneRect(0,0,800,700);
    scene->setParent(this);

    obraz = new QGraphicsView(scene, this);
    obraz->setGeometry(0,0,800,700);

    obraz->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    obraz->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setGeometry(400,150,1000,700);

    menu_init();
}

void OKno::set_enable_disable(bool tog)
{
    if(tog){
        Edit->setEnabled(1);
        Add_new->setEnabled(1);
        Delete->setEnabled(1);
    }
    else {
        Edit->setEnabled(0);
        Add_new->setEnabled(0);
        Delete->setEnabled(0);
        scene->set_NOTHING(0);
    }
}
