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

int mascotasTipos(eMascota mascota[],int TAMMasc,eTipo tipo[],int TAMTIPOS,eColor color[],int TAMColores)
{
    int retorno = -1;
    int idTipo;
    int respuesta;

    if(tipo != NULL && tipo != NULL && tipo != NULL && TAMTIPOS > 0 && TAMColores > 0 && TAMTIPOS > 0)
    {
        MostrarTipo(tipo,TAMTIPOS);
        respuesta = capturarMascota(&idMarca);
        while(respuesta == -1)
        {
            printf("\nERROR! Ingrese nuevamente un id existente...\n\n");
            system("pause");
            MostrarTipo(tipo,TAMTIPOS;
            respuesta = capturarMarca(&idMarca);
        }
        system("cls");
        MOSTRARMASCOTA(mascota,TAMMasc,tipo,TAMTIPOS,color,TAMColores,idTipo);
        retorno = 0;

    }
    return retorno;
}
