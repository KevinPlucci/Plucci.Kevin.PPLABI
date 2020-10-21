#include "Tipo.h"
#include <stdio.h>
#include <string.h>

void ListarTipos(eTipo tipos[],int tam)
{
    printf("ID:   Descripcion:\n");
    for(int i = 0;i < tam; i++)
    {
        printf("%d  %s\n",tipos[i].id,tipos[i].descripcion);
    }
}

char * MostrarTipo(eTipo tipos[],int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(tipos[i].id == id)
        {
            return tipos[i].descripcion;
        }
    }
    return "";
}

