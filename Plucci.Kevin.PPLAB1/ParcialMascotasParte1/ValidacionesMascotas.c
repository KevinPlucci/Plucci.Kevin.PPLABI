#include "ValidacionesMascotas.h"
#include "Color.h"
#include "Tipo.h"
#include "Servicios.h"
#include "Mascota.h"
#define TRUE 1
#define FALSE 0

int validaciones_validarEdad(float edad)
{
    return (edad > 0);

}

int validaciones_ValidarServicio(eServicio servicios[], int tam, int idServicio)
{
    if(BuscarServicioPosById(servicios,tam,idServicio) >= 0)
    {
        return TRUE;
    }
    return FALSE;
}

int validaciones_ValidarMascota(eMascota masc[], int tam, int idMascota)
{
    if(BuscarPosById(masc,tam,idMascota)>= 0)
    {
        return TRUE;
    }
    return FALSE;
}


int validaciones_ValidarColorValido(eColor colores[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(colores[i].id == id)
        {
            return TRUE;
        }
    }

    return FALSE;
}

int validaciones_ValidarTipoValido(eTipo tipos[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(tipos[i].id == id)
        {
            return TRUE;
        }
    }

    return FALSE;
}
