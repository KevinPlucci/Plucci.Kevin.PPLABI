#include "Servicios.h"
#include <string.h>
#include <stdio.h>


void listarServicios(eServicio servicios[], int tam)
{
    for(int i = 0; i< tam ; i++)
    {
        mostrarServicio(servicios,i);
    }
}

void mostrarServicio(eServicio servicios[], int pos)
{
    printf("ID  DESCRIPCION     PRECIO\n");
    printf("%d   %s             %.2f\n", servicios[pos].id,servicios[pos].descripcion,servicios[pos].precio);
}

int BuscarServicioPosById(eServicio servicios[], int tam, int id)
{
    for(int i = 0; i< tam; i++)
    {
        if(servicios[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarServicioById(eServicio servicios[],int tam, int id)
{
    int pos = BuscarServicioPosById(servicios,tam,id);

    mostrarServicio(servicios,pos);
}
