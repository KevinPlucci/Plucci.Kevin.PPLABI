#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "harcodeoMascotas.h"
#define TAM_TIPO 4
#define TAM_COLOR 5
#define TAM_SERVICIO 4
#define TAM_MASCOTA 10
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idMascota;
    eTipo tipo;
    eColor color;
    int isEmpty;
}eMascota;

typedef struct
{
    int idTrabajo;
    eMascota mascota;
    eServicio servicio;
    eFecha fechaTrabajo;
}eTrabajo;



int altaMascota(eMascota mascota[], int tam, int idMascota);
int buscarLibre(eMascota mascota[], int tam);

char menu();
int main()
{


    char seguir = 's';
    char confirma;
    int idProxMascota=3000;
    int proximoIdTipo=1000;
    int proximoIdColor=10000;
    int proximoIdServicio=20000;
    eTipo tipo[TAM_TIPO];
    eColor color[TAM_COLOR];
    eServicio servicio[TAM_SERVICIO];
    eMascota mascota[TAM_MASCOTA];
    proximoIdTipo+=harcodearTipos(tipo, TAM_TIPO, 4);
    proximoIdColor+=harcodearColor(color, TAM_COLOR, 5);
    proximoIdServicio+=harcodearServicios(servicio, TAM_SERVICIO, 4);


    do
    {
        switch(menu())
        {

        case 'a':
            if(altaMascota(mascota, TAM_MASCOTA, idProxMascota)==0)
            {
                idProxMascota++;
                printf("Alta exitosa!!!!\n\n");
            }
            else
            {
                printf("Problema al realizar el alta.....\n");
            }
            break;
        case 'b':
            bajaMascota(mascota,TAM_MASCOTA,);

            break;
        case 'c':
            mostrarMascotas(mascota);
            break;
        case 'd':

            break;
        case 'e':
            mostrarTipos(tipo, TAM_TIPO);
            break;
        case 'f':
            mostrarColores(color, TAM_COLOR);
            break;
        case 'g':
            mostrarServicios(servicio, TAM_SERVICIO);
            break;

        case 'h':

            break;

        case 'x':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}


char menu()
{
    char opcion;
    system("cls");

    printf(" .......Mascotas.......\n");
    printf("                       |\n");
    printf("  a ALTA MASCOTA          |\n");
    printf("  b MODIFICAR MASCOTA         |\n");
    printf("  c BAJA MASCOTA       |\n");
    printf("  d LISTAR MASCOTAS       |\n");
    printf("  e LISTAR TIPOS     |\n");
    printf("  f LISTAR COLORES   |\n");
    printf("  g LISTAR SERVICIOS       |\n");
    printf("  h ALTA TRABAJO     |\n");
    printf("  x SALIR              |\n");
    printf("                       |\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}

int altaMascota(eMascota mascota[], int tam, int idMascota)
{
    int error=1;
    eMascota nuevaMascota;
    int indice;


    if(moto != NULL && tam > 0 && idMascota>0)
    {
        indice = buscarLibre(moto, tam);
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

            printf("Ingrese Tipo (1000 a 1004): ");
            fflush(stdin);
            scanf("%d", &nuevaMascota.tipo.idTipo);

            printf("Ingrese un id de color (1000 a 1004): ");
            scanf("%d", &nuevaMascota.color.idColor);

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
        if(moto[i].isEmpty==1)
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

int mostrarMascotas(eMascota mascota[], int tam)
{
   int error=1;

    if(mascota!= NULL && tam > 0)
    {

        printf("   Id  /// Descripcion \n");
        printf(" -...................\n");
        for(int i=0; i<tam; i++)
        {
            mostrarMascotas(mascota[i]);
        }
        error= 0;
    }
    return error;
}

void mostrarMascotas(eMascota mascota)
{
        printf("    %5d       %10s        %6s    \n", mascota.idMascota , mascota.color, mascota.tipo);
}

