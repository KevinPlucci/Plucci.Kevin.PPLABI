#include "Mascota.h"
#include <stdio.h>
#include <string.h>
#include "DataStore.h"
#include "Tipo.h"
#include "Color.h"
#include "ValidacionesMascotas.h"
#include "Mascota.h"
#include "Cliente.h"
#include "Menu.h"
#define TAMINIMAS 4
#define TRUE 1
#define FALSE 0

void inicializarVectores(eMascota mascotas[],eTipo tipos[],eColor colores[],eServicio servicios[],eCliente clientes[],int tamM, int tamT, int tamC, int tamS, int tamClientes)
{
    inicializarCliente(clientes,tamClientes);
    InicializarMascotas(mascotas,tamM);
    for(int i =0; i<TAMINIMAS; i++)
    {
        mascotas[i].id = vMascota[i].id;
        mascotas[i].idColor = vMascota[i].idColor;
        mascotas[i].idTipo = vMascota[i].idTipo;
        mascotas[i].idCliente = vMascota[i].idCliente;
        strcpy(mascotas[i].nombre,vMascota[i].nombre);
        mascotas[i].edad = vMascota[i].edad;
        mascotas[i].isEmpty = FALSE;
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

int ALTA(eMascota mascotas[],eColor colores[], eTipo tipos[], eCliente clientes[],int tamMasc, int tamC, int tamT, int id,int tamClientes)
{
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    int idCliente;
    eMascota masc ;
    int pos = BuscarIdLibre(mascotas,tamMasc);
    if(pos < 0){return TRUE;}
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombre);

    printf("indique el ID del tipo de mascota\n");
    ListarTipos(tipos,tamT);
    scanf("%d",&idTipo);
    while(!validaciones_ValidarTipoValido(tipos,tamT,idTipo))
    {
        printf("Tipo seleccionado Invalido\n");
        ListarTipos(tipos,tamT);
        scanf("%d",&idTipo);
    }

    printf("Indique el ID del cliente\n");
    ListarClientes(clientes,tamClientes);
    scanf("%d",&idCliente);
    while(!validaciones_ValidarCliente(clientes,tamClientes,idCliente))
    {
        printf("Id cliente Invalido. Reingrese\n");
        ListarClientes(clientes,tamClientes);
        scanf("%d",&idCliente);
    }
    printf("indique el ID del color de la mascota\n");
    ListarColores(colores,tamC);
    scanf("%d",&idColor);
    while(!validaciones_ValidarColorValido(colores,tamC,idColor))
    {
        printf("Color seleccionado Invalido\n");
        ListarColores(colores,tamC);
        scanf("%d",&idColor);
    }

    printf("Ingrese edad \n");
    scanf("%d",&edad);
    while(!validaciones_validarEdad(edad))
    {
        printf("Edad invalida");
        scanf("%d",&edad);
    }

    masc.id = id;
    masc.idColor = idColor;
    masc.idTipo = idTipo;
    strcpy(masc.nombre,nombre);
    masc.idCliente = idCliente;
    masc.isEmpty = FALSE;
    masc.edad = edad;

    mascotas[pos] = masc;
    printf("Alta correcta \n");
    return FALSE;
}

int BAJA(eMascota mascotas[],eColor colores[], eTipo tipos[], eCliente clientes[],int tamMasc, int tamC, int tamT,int id, int tamCliente)
{
    int borra;
    int pos = BuscarPosById(mascotas,tamMasc,id);

    printf("Mascota a dar de baja :\n");
    MOSTRARMASCOTA(mascotas,tipos,colores,clientes,pos,tamMasc,tamT,tamC,tamCliente);
    printf("Esta seguro que desa darla de baja? SI 1, NO 0");
    scanf("%d",&borra);
    if(borra)
    {
        mascotas[pos].isEmpty = TRUE;
        printf("Mascota dada de baja");
    }
    return FALSE;
}

int MODIFICAR(eMascota mascotas[],eColor colores[], eTipo tipos[], eCliente clientes[], int tamMasc, int tamC, int tamT,int id, int tamCliente)
{
    int pos = BuscarPosById(mascotas,tamMasc,id);
    int modifica = 0;
    printf("Mascota a Modificar :\n");
    MOSTRARMASCOTA(mascotas,tipos,colores,clientes,pos,tamMasc,tamT,tamC,tamCliente);
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

void ListarMascotas(eMascota mascotas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamM, int tamT, int tamC, int tamClientes)
{
    OrdenarVectorBurbuja(mascotas,tamM);
    for(int i = 0; i< tamM; i++)
    {
        if(!mascotas[i].isEmpty)
        {
          MOSTRARMASCOTA(mascotas,tipos,colores,clientes,i,tamM,tamT,tamC,tamClientes);

        }
    }
}

void OrdenarVectorBurbuja(eMascota mascotas[], int tam)
{
    for(int i =0; i < tam ; i++)
    {
        for(int j = i+1; j <tam; j++)
        {
            if(!mascotas[i].isEmpty && !mascotas[j].isEmpty)
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
        mascotas[i].isEmpty = TRUE;
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

void MOSTRARMASCOTA(eMascota mascotas[],eTipo tipos[], eColor colores[], eCliente clientes[],int index, int tam, int tamT, int tamC, int tamCliente)
{
    printf("ID  NOMBRE   TIPO  COLOR  EDAD  CLIENTE\n"),
    printf("%d  %s    %s     %s %.2f    %s\n",mascotas[index].id,mascotas[index].nombre,MostrarTipo(tipos,tamT,mascotas[index].idTipo),MostrarColor(colores,tamC,mascotas[index].idColor),mascotas[index].edad,MostrarUnCliente(clientes,tamCliente,mascotas[index].idCliente));

}

void MOSTRARMASCOTABYID (eMascota mascotas[],eTipo tipos[], eColor colores[],eCliente clientes[],int id, int tam, int tamT, int tamC, int tamClientes)
{
  int pos = BuscarPosById(mascotas,tam,id);
  if(pos < 0)
  {
      printf("Id invalido \n");
  }
  else
  {
    MOSTRARMASCOTA(mascotas,tipos,colores,clientes,pos,tam,tamT,tamC,tamClientes);

  }
}

int BuscarIdLibre(eMascota mascotas[], int tam)
{
    for(int i = 0; i < tam ; i++)
    {
        if(mascotas[i].isEmpty)
        {
            return i;
        }
    }
    return 0;
}

int buscarColor(eColor color[], int TAMColores, char auxColor[],int id)
{
    int i;

    if(color != NULL && TAMColores > 0)
    {
        for(i = 0; i < TAMColores; i++)
        {
            if(id == color[i].id)
            {
                strcpy(auxColor,color[i].nombre);
            }
        }
    }

    return 0;
}
int buscarTipo(eTipo tipo[], int TAMTIPOS, char auxTipo[],int id)
{
    int i;
    int retorno = -1;

    if(marca != NULL && TAMTIPOS > 0)
    {
        for(i = 0; i < TAMTIPOS; i++)
        {
            if(id == tipo[i].id)
            {
                strcpy(auxTipo,tipo[i].descripcion);
                retorno = 0;
            }
        }
    }

    if(retorno == -1)
    {
        printf("No existe un tipo con ese id, por favor intente nuevamente");
    }
    return retorno;
}

void mascotaMasJoven(eMascota mascota[],int TAMMasc, eTipo tipo[],int TAMTIPOS, eColor color[], int TAMColores)
{
    int error=1;
    int minimo;
    int idAux;
    char auxColor[21];
    char auxTip[21];

    if(mascota != NULL && tipo != NULL && color != NULL && TAMMasc > 0 && TAMTIPOS > 0 && TAMColores > 0)
    {
        printf("               Mascotas mas Jovem      ");
        printf("\n     ------------------------------------------\n\n");
        printf("ID      Edad       Mascota         Color     Tipos\n\n");

        minimo = mascota[0].edad;
        for(i = 0; i < TAMMasc; i++)
        {
            if(mascota[i].edad <= minimo && mascota[i].isEmpty == 0)
            {
                minimo = mascota[i].edad;
            }
        }
        for(i = 0; i < TAMMasc; i++)
        {
            if(mascota[i].edad == minimo && mascota[i].isEmpty == 0 )
            {
                idAux = mascota[i].idColor;
                buscarColor(color,TAMColores,auxColor,idAux);
                idAux = mascota[i].idMarca;
                buscarTipo(marca,TAMTIPOS,auxMarca,idAux);
                printf("%d   %8s  %12s %12s      %d\n",mascota[i].id,mascota[i].nombre,auxMarca,auxColor,autos[i].edad);
            }
        }
    }
}

void separarPorTipo(eMascota mascota[],int TAMMasc, eTipo tipo[], int TAMTIPOS, eColor color[],int TAMColores)
{
    int i;
    int j;
    int idAux;
    int aux;
    char auxColor[21];

    if(mascota != NULL && tipo != NULL && color != NULL && TAMMasc > 0 && TAMTIPOS > 0 && TAMColores)
    {
        for(i = 0; i < TAMTIPOS; i++)
        {
            aux = tipo[i].id;
            printf("%12s           |\n",tipo[i].descripcion;
            printf("-----------------------\n");
            printf("ID      MASCOTA        Color     EDAD\n\n");
            for(j = 0; j < TAMMasc; j++)
            {
                if(aux == mascota[j].idTipo && mascota[j].isEmpty == 0)
                {
                    idAux = mascota[j].idColor;
                    buscarColor(color,TAMColores,aux,idAux);
                    printf("%d   %8s  %12s      %d\n",mascota[j].id,mascota[j].nombre,auxColor,mascota[j].edad);
                }
            }
            printf("\n");
            printf("-----------------------------------------------\n");
        }
    }
}
