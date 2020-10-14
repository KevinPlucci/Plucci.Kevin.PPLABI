#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mascota.h"

int altaMascota(eMascota mascota[], eColor color[], eTipo tipo[], int tam, int TAM_COLOR, int TAM_TIPO, int idMascota)
{
    int error=1;
    eMascota nuevaMascota;
    int indice;


    if(moto != NULL && tam > 0 && idMascota>0)
    {
        indice = buscarLibre(mascota, tam);
        if(indice==-1)
        {
            printf("No hay lugar, sistema completo\n");
        }
        else
        {
            nuevaMascota.idMascota = idMascota;

            nuevaMascota.isEmpty=0;

            printf("Ingrese Marca: ");
            fflush(stdin);
            gets(nuevaMascota.marca);

            mostrarTipos(tipo, TAM_TIPO);

            printf("Ingrese Tipo (1000 a 1003): ");
            scanf("%d", &nuevaMascota.tipo.idTipo);
            printf("\n\n");
            mostrarColores(color, TAM_COLOR);

            printf("Ingrese un id de color (10000 a 10004): ");
            scanf("%d", &nuevaMascota.color.idColor);
            printf("\n\n");
            moto[indice]=nuevaMascota;
            error =0;
        }
    }
    return error;
}


int buscarLibre(eMascota mascota[], int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(mascota[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int inicializar(eMascota mascota[], int tam)
{
    int error=1;

    if(mascota != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            mascota[i].isEmpty =1;
        }
        error= 0;
    }
    return error;
}

int mostrarMascota(eMascota mascota[],eColor color[], eTipo tipo[], int tam, int TAM_COLOR, int TAM_TIPO)
{
   int error=1;

    if(mascota!= NULL && tam > 0)
    {

        printf("      Id    //    Color    //   Tipo   //   \n");
        printf(" ..................................................................\n");
        for(int i=0; i<tam; i++)
        {
            mostrarMascota(mascota[i], tipo, color, TAM_COLOR, TAM_TIPO);
        }
        error= 0;
    }
    return error;
}
void mostrarMascota(eMascota mascota, eTipo tipo[], eColor color[], int TAM_COLOR, int TAM_TIPO)
{
        char auxColor[20];
        char auxTipo[20];

        if(cargarColoryTipo(tipo, color, auxColor, auxTipo, mascota.color.idColor, mascota.tipo.idTipo, TAM_COLOR, TAM_TIPO)==0)
        {
            printf("    %5d      %12s   %10s   %10s     %3d\n", mascota.idMascota , auxColor, auxTipo);
        }else
        {
        printf("No hay descripciones\n\n");
        }

}

int cargarColoryTipo( eTipo tipo[], eColor color[], char auxColor[], char auxTipo[], int idColor, int idTipo, int TAM_COLOR, int TAM_TIPO)
{
    int error=1;

        for(int i=0;i<TAM_COLOR;i++)
        {
            if(idColor==color[i].idColor)
            {
                strcpy(auxColor, color[i].nombreColor);
                error=0;

            }
        }

        for(int i=0;i<tam_t;i++)
        {
            if(idT==tipo[i].idTipo)
            {
                strcpy(auxTipo, tipo[i].descripcionTipo);
                error=0;

            }
        }
    return error;
}

int modificarMascota(eMascota mascota[],eColor color[],eTipo tipo[], int TAM_COLOR,int TAM_TIPO, int TAM_MASCOTA)
{
    int error=1;
    int indice;
    int id;
    char confirmar;
    char modificar;

    if(moto !=NULL && TAM_MASCOTA >0)
    {
        system("cls");
        printf("              MODIFICAR MASCOTA        \n\n");
        mostrarMascota(mascota, color, tipo, TAM_MASCOTA, TAM_COLOR, TAM_TIPO);
        printf("Ingrese id Mascota: ");
        scanf("%d", &id);

        indice = buscarMascota(moto, TAM_MASCOTA, id);

        if(indice==-1)/
        {
            printf("No se encontro el id de la mascota\n\n");
        }
        else
        {
            printf("a Color\n");
            printf("Que desea modificiar?: ");
            fflush(stdin);
            scanf("%c", &modificar);

            switch(modificar)
            {
            case 'a':
                mostrarColores(color, tam_c);
                printf("Ingrese id de Color(10000 a 10004): ");
                scanf("%d", &mascota[indice].color.idColor);
                break;
            }
            printf("Desea confirmar el cambio?: ");
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar=='s')
            {
                error=0;
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}

int buscarMascota(eMascota mascota[], int tam, int id)
{
    int indice;

    for(int i=0; i<tam; i++)
    {
        if(mascota[i].idMascota==id&&mascota[i].isEmpty==0)
        {
            indice=i;
            break;
        }
        else
        {
            indice= -1;
        }
    }
    return indice;
}

int bajaMascota(eMascota mascota[],eColor color[], eTipo tipo[], int TAM_MASCOTA, int TAM_COLOR, int TAM_TIPO)
{
    int error=1;
    int indice;
    int id;
    char confirma;

    if(mascota !=NULL && TAM_MASCOTA >0)
    {
        system("cls");
        printf("             BAJA MASCOTA\n\n");
        mostrarMascota(mascota, color, tipo, TAM_MASCOTA,TAM_COLOR,TAM_TIPO);
        printf("Ingrese ID: ");
        scanf("%d", &id);

        indice = buscarMascota(mascota, TAM_MASCOTA, id);

        if(indice==-1)
        {
            printf("No hay ninguna mascota con ese ID\n\n");
        }
        else
        {
            mostrarMascota(mascota[indice], tipo, color, tam_c,tam_t);
            printf("Confirma eliminar a la Mascota?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma=='s')
            {
                moto[indice].isEmpty=1;
                error=0;/
            }
            else
            {
                error=2;
            }
        }
    }
    return error;
}
