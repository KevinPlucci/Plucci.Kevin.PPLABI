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

int mostrarPorColor(eMascota mascota[],eTipo tipo[],int tam,eColor color[],int TAMClientes, int TAMTIPOS, int idColor)
{
    int error=1;
    int flag=0;
    if(mascota!= NULL && tam > 0 && TAMColores > 0 && color!= NULL )
    {
        printf(" Listado De Mascota por color\n\n");
        printf("      Id             Mascota        Color       Tipo     Clientes \n");
        printf(" -----------------------------------------------------------------\n");
        for(int i =0 ; i < tam ; i++)
        {
            if(mascota[i].isEmpty==0 && mascota[i].color.idColor==idColor)
            {
                MOSTRARMASCOTA(mascota[i],tipo,color,TAMColores,TAMTIPOS);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("    No Hay Colores con ese ID \n\n");
        }
        else
        {
            printf("\n\n");
        }
    }
    error=0;
    return error;
}
