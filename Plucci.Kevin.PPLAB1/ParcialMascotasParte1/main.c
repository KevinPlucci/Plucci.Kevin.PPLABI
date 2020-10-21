#include <stdio.h>
#include <stdlib.h>
#include "Mascota.h"
#include "Color.h"
#include "Tipo.h"
#include "Trabajo.h"
#include "Servicios.h"
#include "ValidacionesMascotas.h"
#include "Menu.h"
#define TAMMasc 20
#define TAMColores 5
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
    int exit= FALSE;
    int diAltaPrimero = FALSE;
    inicializarVectores(mascotas,tipos,colores,servicios,TAMMasc,TAMTIPOS,TAMColores,TAMServicio);
    InicializarTrabajos(trabajos,TAMTrabajos,TRUE);
    opcion =menu_getMenu("1 ALTA MASCOTA\n2 MODIFICAR MASCOTA:\n3 BAJA MASCOTA\n4 LISTAR MASCOTA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 SALIR","Opcion invalida. Reingrese",1,10,3);
    int id ;
    int idMascota;
    int idMascotaNueva = 4; // arranca en 4 porque ya hay 4 harcodeados
    int idServicio;
    int idTrabajo = 5;
    do
    {
        switch(opcion)
        {
        case 1:
            idMascotaNueva++;
            if(!ALTA(mascotas,colores,tipos,TAMMasc,TAMColores,TAMTIPOS,idMascotaNueva))
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
                ListarMascotas(mascotas,tipos,colores,TAMMasc,TAMTIPOS,TAMColores);
                scanf("%d",&id);
                if(MODIFICAR(mascotas,colores,tipos,TAMMasc,TAMColores,TAMTIPOS,id))
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
                ListarMascotas(mascotas,tipos,colores,TAMMasc,TAMTIPOS,TAMColores);
                scanf("%d",&id);
                if(BAJA(mascotas,colores,tipos,TAMMasc,TAMColores,TAMTIPOS,id))
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
                ListarMascotas(mascotas,tipos,colores,TAMMasc,TAMTIPOS,TAMColores);
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
                ListarMascotas(mascotas,tipos,colores,TAMMasc,TAMTIPOS,TAMColores);
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
                listarTrabajos(trabajos,mascotas,tipos,colores,servicios,TAMTrabajos,TAMMasc,TAMTIPOS,TAMColores,TAMServicio);
            }
            else
            {
                printf("Primero tiene que dar el alta \n");
            }
            break;
        case 10:
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
            opcion =menu_getMenu("1 ALTA MASCOTA\n2 MODIFICAR MASCOTA:\n3 BAJA MASCOTA\n4 LISTAR MASCOTA\n5 LISTAR TIPOS\n6 LISTAR COLORES\n7 LISTAR SERVICIOS\n8 ALTA TRABAJO\n9 LISTAR TRABAJOS\n10 SALIR","Opcion invalida. Reingrese",1,10,3);
        }
        system("pause");
    }
    while(!exit && opcion != 10 );
    return 0;
}
