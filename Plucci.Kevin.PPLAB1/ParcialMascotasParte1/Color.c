#include "Color.h"
#include <stdio.h>
#include <string.h>

void ListarColores(eColor colores[],int tam)
{   printf("ID:    Nombre:\n");
    for(int i = 0;i < tam; i++)
    {
        printf("%d  %s\n",colores[i].id,colores[i].nombreColor);
    }
}

char * MostrarColor(eColor colores[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(colores[i].id == id)
        {
            return colores[i].nombreColor;
        }
    }
    return "";
}
