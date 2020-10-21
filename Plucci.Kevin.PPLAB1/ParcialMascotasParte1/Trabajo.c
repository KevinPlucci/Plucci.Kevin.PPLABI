#include <stdio.h>
#include <stdlib.h>
#include "Trabajo.h"
#include "Mascota.h"
#include "Color.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Servicios.h"
#include "DataStoreTrabajo.h"
#define TRUE 1
#define FALSE 0
#define TAMTrabajosHard 5

void InicializarTrabajos(eTrabajo trabajos[], int tam,int cargaDatos)
{
    for(int i = 0; i< tam ; i++)
    {
        trabajos[i].isEmpty = TRUE;
    }
    if(cargaDatos)
    {
    // datos harcodeados
        for(int i = 0; i< TAMTrabajosHard ; i++)
        {
            trabajos[i].isEmpty = FALSE;
            trabajos[i].fecha = vTrabajos[i].fecha;
            trabajos[i].id = vTrabajos[i].id;
            trabajos[i].idMascota = vTrabajos[i].idMascota;
            trabajos[i].idServicio = vTrabajos[i].idServicio;
        }
    }
}
void listarTrabajos(eTrabajo trabajos[],eMascota mascotas[],eTipo tipos[], eColor colores[],eServicio servicios[], int tamTrabajo,int tamMasc, int tamTipo, int tamColor, int tamServ)
{
    if(trabajos == NULL || tamTrabajo <=0)
    {
        printf("Lista de trabajos vacia \n");
    }
    for(int i = 0; i< tamTrabajo; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos,mascotas,tipos,colores,servicios,tamTrabajo,tamMasc,tamTipo,tamColor,tamServ,i);
        }
    }
}

int mostrarTrabajo(eTrabajo trabajos[],eMascota mascotas[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamMasc, int tamTipo, int tamColor, int tamServ, int pos)
{
    if(trabajos == NULL || tamTrabajo <0)
    {
        printf("Lista trabajo vacia\n");
        return TRUE;
    }
    printf("ID Trabajo: %d\n",trabajos[pos].id);
    printf("Fecha: \n");
    MostrarFecha(trabajos[pos].fecha);
    printf("Mascota:\n");
    MOSTRARMASCOTABYID(mascotas,tipos,colores,trabajos[pos].idMascota,tamMasc,tamTipo,tamColor);
    printf("Servicio realizado: \n");
    mostrarServicioById(servicios,tamServ,trabajos[pos].idServicio);
    printf("\n------------------\n");
    printf("\n\n");
    return FALSE;
}

int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(trabajos[i].id <0)
        {
            return i;
        }
    }
    return -1;
}

int BuscarProximoId(eTrabajo trabajos[], int tam)
{
    for(int i =0; i< tam ; i++)
    {
        if(trabajos[i].id <0)
        {
            if(i == 0)
            {
                return 0;
            }
            return (trabajos[i-1].id + 1);
        }
    }
    return 0;
}

int AltaTrabajo(eTrabajo trabajos[], int idMascota, int idServicio, int tam, int idTrabajo)
{
    eTrabajo trabajo;
    trabajo.fecha = crearFecha();
    trabajo.id =idTrabajo;
    trabajo.idMascota = idMascota;
    trabajo.idServicio = idServicio;
    trabajo.isEmpty = FALSE;
    int index =BuscarIdTrabajoLibre(trabajos,tam);
    trabajos[index] = trabajo;
    printf("Alta de trabajo correcta \n");
    return FALSE;
}


