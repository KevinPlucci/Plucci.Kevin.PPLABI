#ifndef DATASTOREMASCOTAS_H_INCLUDED
#define DATASTOREMASCOTAS_H_INCLUDED

    char descTipo[10][20]={
    "Ave",
    "Gato",
    "Roedor",
    "Pez"
    };

    int idTipo[]={
    1000,
    1001,
    1002,
    1003
    };

    char colores[10][20]={
    "Negro",
    "Blanco",
    "Gris",
    "Rojo",
    "Azul"
    };

    int idColor[]={
    5000,
    5001,
    5002,
    5003,
    5004
    };

    int precioServicios[]={250,300,400};

    char nombreServicios[4][25]={
    "Corte",
    "Desparasitado",
    "Castrado"
    };

    int idServicios[]={
    20000,
    20001,
    20002,
    20003
    };

//Todo el hardcodeo de mascotas con sus ID, nombres y precios y descripciones

#endif // DATASTOREMASCOTAS_H_INCLUDED
