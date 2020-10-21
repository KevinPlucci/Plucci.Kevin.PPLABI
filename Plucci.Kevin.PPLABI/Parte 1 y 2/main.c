#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "Color.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Servicios.h"
#include "ValidacionesMascotas.h"
#include "Menu.h"
#include "Cliente.h"
#define TAMMasc 20
#define TAMColores 5
#define TAMClientes 5
#define TAMTIPOS 5
#define TAMServicio 3
#define TAMTrabajos 100
#define TRUE 1
#define FALSE 0
int main()
{
    int opcion = 0;
    eMascota mascotas[TAMMasc];
    eColor colores[TAMColores];
    eTipo tipos[TAMTIPOS];
    eServicio servicios[TAMServicio];
    eTrabajo trabajos[TAMTrabajos];
    eCliente clientes[TAMClientes];
    int exit= FALSE;
    int diAltaPrimero = FALSE;
    inicializarVectores(mascotas,tipos,colores,servicios,clientes,TAMMasc,TAMTIPOS,TAMColores,TAMServicio,TAMClientes);
    InicializarTrabajos(trabajos,TAMTrabajos,TRUE);
    opcion =menu_getMenu("1 ALTA MASCOTA\n2 MODIFICAR MASCOTA:\n3 BAJA MASCOTA\n4 LISTAR MASCOTA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 Listado De Mascota por color\n11 Mascotas de un tipo seleccionado.\n12 Mascota Mas joven\n14 Listar de las mascotas separadas por tipo. \n14 Salir","Opcion invalida. Reingrese",1,10,3);
    int id ;
    int idMascota;
    int idMascotaNueva = 4;
    int idServicio;
    int idTrabajo = 5;
    do
    {
        switch(opcion)
        {
        case 1:
            idMascotaNueva++;
            if(!ALTA(mascotas,colores,tipos,clientes,TAMMasc,TAMColores,TAMTIPOS,idMascotaNueva,TAMClientes))
            {
                diAltaPrimero = TRUE;

            }
            else
            {
                printf("Alta invalida \n");
            }
            break;
        case 2:

            if(diAltaPrimero)
            {
                printf("Ingrese Id a modificar \n");
                ListarMascotas(mascotas,tipos,colores,clientes,TAMMasc,TAMTIPOS,TAMColores,TAMClientes);
                scanf("%d",&id);
                if(MODIFICAR(mascotas,colores,tipos,clientes,TAMMasc,TAMColores,TAMTIPOS,id,TAMClientes))
                {
                    printf("Modificacion invalida \n");
                }
            }
            else
            {
                printf("Primero tiene que dar de alta una bicicleta \n");
            }
            break;
        case 3:
            if(diAltaPrimero)
            {
                printf("Ingrese Id a dar de baja \n");
                ListarMascotas(mascotas,tipos,colores,clientes,TAMMasc,TAMTIPOS,TAMColores,TAMClientes);
                scanf("%d",&id);
                if(BAJA(mascotas,colores,tipos,clientes,TAMMasc,TAMColores,TAMTIPOS,id,TAMClientes))
                {
                    printf("BAJA INVALIDA \n");
                }
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 4:
            if(diAltaPrimero)
            {
                printf("che entro \n");
                ListarMascotas(mascotas,tipos,colores,clientes,TAMMasc,TAMTIPOS,TAMColores,TAMClientes);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 5:
            if(diAltaPrimero)
            {
                ListarTipos(tipos,TAMTIPOS);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 6:
            if(diAltaPrimero)
            {
                ListarColores(colores,TAMColores);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 7:
            if(diAltaPrimero)
            {
                listarServicios(servicios,TAMServicio);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 8:
            if(diAltaPrimero)
            {
             do{
                printf("Seleccione el id de la mascota sobre la que se realizara el trabajo\n");
                ListarMascotas(mascotas,tipos,colores,clientes,TAMMasc,TAMTIPOS,TAMColores,TAMClientes);
                scanf("%d",&idMascota);
                printf("Seleccione el id de servicio a realizar \n");
                listarServicios(servicios,TAMServicio);
                scanf("%d",&idServicio);
             } while(!validaciones_ValidarMascota(mascotas,TAMMasc,idMascota) && !validaciones_ValidarServicio(servicios,TAMServicio,idServicio));
                idTrabajo++;
                if(AltaTrabajo(trabajos,idMascota,idServicio,TAMTrabajos,idTrabajo))
                {
                    printf("Alta de trabajo invalida \n");
                }

            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 9:
            if(diAltaPrimero)
            {
                listarTrabajos(trabajos,mascotas,tipos,colores,servicios,clientes,TAMTrabajos,TAMMasc,TAMTIPOS,TAMColores,TAMServicio,TAMClientes);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 10:
           if(diAltaPrimero)
           {
            mostrarColores(color, TAMColores);
            printf("Ingresar ID de Color: ");
            scanf("%d", &idColorMostrar);
            mostrarXColor(mascotas,tipo,TAMMasc,color,TAMColores,TAM_T,idColorMostrar);
           }
            else
            {
                printf("Primero tiene que dar el alta\n");
            }
            break;
        case 11:
            if(diAltaPrimero)
            {
                mascotasTipos(mascotas,TAMMasc,tipos,TAMTIPOS,colores,TAM_COLOR);
            }
            else
            {
                printf("Primero tiene que dar de alta\n");
            }
        case 12:
            if(diAltaPrimero)
            {
                mascotaMasJoven(mascotas,TAMMasc,tipos,TAMTIPOS,colores,TAMColores);
            }
            else
            {
                printf("Primero tiene que dar de alta\n");

            }
        case 13:
            if(diAltaPrimero)
            {
                void separarPorMarca(eAuto autos[],int tam_auto, eMarca marca[], int tam_marca, eColor color[],int tam_color)
            }
            else
            {
                printf("Primero tiene que dar de alta\n");

            }

        case 14:
            printf("El sistema se va a cerrar\n");
            exit = TRUE;
            break;
        }

        if(!exit)
        {
            printf("¿Desea continuar operador? YES 1 NOT 0\n");
            scanf("%d",&exit);
            exit = !exit;
            system("cls");
        }
        if(!exit)
        {
            opcion =menu_getMenu("1 ALTA MASCOTA\n2 MODIFICAR MASCOTA:\n3 BAJA MASCOTA\n4 LISTAR MASCOTA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 Listado De Mascota por color\n11 Mascotas  de un tipo seleccionado\n12 Mascota Mas Joven\n13 Listar de las mascotas separadas por tipo.\n14 SALIR","Opcion invalida. Reingrese",1,10,3);
        }
        system("pause");
    }
    while(!exit && opcion != 10 );
    return 0;
}
