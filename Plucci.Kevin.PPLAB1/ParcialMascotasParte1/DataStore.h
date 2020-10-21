#ifndef DATASTORE_H_INCLUDED
#define DATASTORE_H_INCLUDED
#include "Servicios.h"
#include "Mascota.h"
char vTipo[5][20] =
{   "Ave",
    "Perro",
    "Gato",
    "Roedor",
    "Pez"
};

char vColores[5][20]  =
{   "Gris",
    "Negro",
    "Blanco",
    "Azul",
    "Rojo"
};
eServicio vServicios[] =
{
    {20000,"Corte",250},
    {20001,"Desparasitado",300},
    {20002,"Castrado",400},
};

eMascota vMascota[] =
{
    {1,"Perro",1000,50000,20},
    {2,"Gato",1001,50001,26},
    {3,"Haster",1002,50002,0.5},
    {4,"Serpiente",1003,50003,29}
};
#endif // DATASTORE_H_INCLUDED
