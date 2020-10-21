#include "Fecha.h"
#include <stdio.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
void MostrarFecha(eFecha fecha)
{
    printf("%d/%d/%d \n",fecha.anio,fecha.mes,fecha.dia);
}

eFecha crearFecha()
{

    eFecha f;
    printf("Ingrese anio \n");
    scanf("%d",&f.anio);

    while(f.anio < 1900)
    {
        printf("Anio invalido. reingrese \n");
        scanf("%d",&f.anio);
    }

    printf("Ingrese mes \n");
    scanf("%d",&f.mes);

    while(f.mes < 1 || f.mes > 12)
    {
        printf("Mes invalido, reingrese\n");
        scanf("%d",&f.mes);

    }

    printf("Ingrese dia \n");
    scanf("%d",&f.dia);

    while(f.dia < 1 || f.dia > 31)
    {
        printf("Dia invalido, reingrese\n");
        scanf("%d",&f.dia);

    }

    return f;
}
