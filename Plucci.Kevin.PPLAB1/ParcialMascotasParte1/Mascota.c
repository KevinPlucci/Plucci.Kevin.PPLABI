#include "Mascota.h"
#include <stdio.h>
#include <string.h>
#include "DataStore.h"
#include "Tipo.h"
#include "Color.h"
#include "ValidacionesMascotas.h"
#include "Mascota.h"
#include "Menu.h"
#define TAMINIMAS 4
#define TRUE 1
#define FALSE 0

void inicializarVectores(eMascota mascotas[],eTipo tipos[],eColor colores[],eServicio servicios[],int tamM, int tamT, int tamC, int tamS)
{
    InicializarMascotas(mascotas,tamM);
    for(int i =0; i<TAMINIMAS; i++)
    {
        mascotas[i].id = vMascota[i].id;
        mascotas[i].idColor = vMascota[i].idColor;
        mascotas[i].idTipo = vMascota[i].idTipo;
        strcpy(mascotas[i].nombre,vMascota[i].nombre);
        mascotas[i].edad = vMascota[i].edad;
    }
    int id = 1000;
    for(int i =0; i<tamT; i++)
    {
        tipos[i].id = id;
        strcpy(tipos[i].descripcion,vTipo[i]);
        id ++;
    }
    id = 50000;
    for(int i =0; i<tamC; i++)
    {
        colores[i].id = id;
        strcpy(colores[i].nombreColor,vColores[i]);
        id ++;
    }
    id = 20000;
    for(int i =0; i<tamS; i++)
    {
        servicios[i].id = vServicios[i].id ;
        strcpy(servicios[i].descripcion,vServicios[i].descripcion);
        servicios[i].precio = vServicios[i].precio;
        id ++;
    }

}

int ALTA(eMascota mascotas[],eColor colores[], eTipo tipos[], int tamMasc, int tamC, int tamT, int id)
{
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;

    eMascota masc ;
    int pos = BuscarIdLibre(mascotas,tamMasc);


    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombre);

    printf("indique el ID del tipo de mascota\n");
    ListarTipos(tipos,tamT);
    scanf("%d",&idTipo);
    if(!validaciones_ValidarTipoValido(tipos,tamT,idTipo))
    {
        printf("Tipo seleccionado Invalido\n");
        return TRUE;
    }

    printf("indique el ID del color de la mascota\n");
    ListarColores(colores,tamC);
    scanf("%d",&idColor);
    if(!validaciones_ValidarColorValido(colores,tamC,idColor))
    {
        printf("Color seleccionado Invalido\n");
        return TRUE;
    }

    printf("Ingrese edad \n");
    scanf("%d",&edad);
    if(!validaciones_validarEdad(edad))
    {
        printf("Edad invalida");
        return TRUE;
    }

    masc.id = id;
    masc.idColor = idColor;
    masc.idTipo = idTipo;
    strcpy(masc.nombre,nombre);
    masc.edad = edad;

    mascotas[pos] = masc;
    printf("Alta correcta \n");
    return FALSE;
}

int BAJA(eMascota mascotas[],eColor colores[], eTipo tipos[], int tamMasc, int tamC, int tamT,int id)
{
    int borra;
    int pos = BuscarPosById(mascotas,tamMasc,id);

    printf("Mascota a dar de baja :\n");
    MOSTRARMASCOTA(mascotas,tipos,colores,pos,tamMasc,tamT,tamC);
    printf("Esta seguro que desa darla de baja? SI 1, NO 0");
    scanf("%d",&borra);
    if(borra)
    {
        mascotas[pos].id = -1;
        printf("Mascota dada de baja");
    }
    return FALSE;
}

int MODIFICAR(eMascota mascotas[],eColor colores[], eTipo tipos[], int tamMasc, int tamC, int tamT,int id)
{
    int pos = BuscarPosById(mascotas,tamMasc,id);
    int modifica = 0;
    printf("Mascota a Modificar :\n");
    MOSTRARMASCOTA(mascotas,tipos,colores,pos,tamMasc,tamT,tamC);
    printf("Esta seguro que desea modificar la mascota? SI 1, NO 0");
    scanf("%d",&modifica);
    if(modifica)
    {
        int  opcion =menu_getMenu("1 Modifica Tipo\n 2 Modifica Edad\n","Opcion invalida. Reingrese",1,2,3);

        if(opcion == 1)
        {
            int idTipo;
            printf("indique el id nuevo tipo de mascota e\n");
            ListarTipos(tipos,tamT);
            scanf("%d",&idTipo);
            if(!validaciones_ValidarTipoValido(tipos,tamT,idTipo))
            {
                printf("Tipo seleccionado Invalido\n");
                return TRUE;
            }
            mascotas[pos].idTipo = idTipo;

        }
        else
        {
            float edad;
            printf("Ingrese la nueva edad \n");
            scanf("%f",&edad);
            if(!validaciones_validarEdad(edad))
            {
                printf("Edad invalida");
                return TRUE;
            }
            mascotas[pos].edad = edad;
        }
    }
    printf("Modificacion correcta \n");
    return FALSE;
}

void ListarMascotas(eMascota mascotas[],eTipo tipos[], eColor colores[], int tamM, int tamT, int tamC)
{
    OrdenarVectorBurbuja(mascotas,tamM);
    for(int i = 0; i< tamM; i++)
    {
        if(mascotas[i].id > 0)
        {
          MOSTRARMASCOTA(mascotas,tipos,colores,i,tamM,tamT,tamC);

        }
    }
}

void OrdenarVectorBurbuja(eMascota mascotas[], int tam)
{
    for(int i =0; i < tam ; i++)
    {
        for(int j = i+1; j <tam; j++)
        {
            if(mascotas[i].id > 0 && mascotas[j].id >0)
            {
                 if(mascotas[i].idTipo > mascotas[j].idTipo || (mascotas[i].idTipo == mascotas[j].idTipo && strcmp(mascotas[i].nombre,mascotas[j].nombre) >0) )
                {
                    makeSwap(mascotas,i,j);
                }
            }
        }
    }

}

/** \brief
 * Make a swap in a array
 * \param eMascota  mascotas[]
 * \param i int
 * \param j int
 * \return void
 *
 */
void makeSwap(eMascota  mascotas[], int i, int j)
{
    eMascota auxEmp;
    auxEmp = mascotas[j];
    mascotas[j] = mascotas[i];
    mascotas[i] = auxEmp;
}

void InicializarMascotas(eMascota mascotas[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        mascotas[i].id = -1;
    }
}

int BuscarPosById(eMascota mascotas[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(mascotas[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

void MOSTRARMASCOTA(eMascota mascotas[],eTipo tipos[], eColor colores[], int index, int tam, int tamT, int tamC)
{
    printf("ID  NOMBRE   TIPO  COLOR  EDAD\n"),
    printf("%d  %s    %s     %s %.2f\n",mascotas[index].id,mascotas[index].nombre,MostrarTipo(tipos,tamT,mascotas[index].idTipo),MostrarColor(colores,tamC,mascotas[index].idColor),mascotas[index].edad);

}

void MOSTRARMASCOTABYID (eMascota mascotas[],eTipo tipos[], eColor colores[], int id, int tam, int tamT, int tamC)
{
  int pos = BuscarPosById(mascotas,tam,id);
  if(pos < 0)
  {
      printf("Id invalido \n");
  }
  else
  {
    MOSTRARMASCOTA(mascotas,tipos,colores,pos,tam,tamT,tamC);

  }
}

int BuscarIdLibre(eMascota mascotas[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        if(mascotas[i].id <0)
        {
            return i;
        }
    }
    return 0;
}
