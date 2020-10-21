#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Fecha.h"
#include "Color.h"
#include "Tipo.h"
#include "Fecha.h"
#include "Servicios.h"
#include "Mascota.h"
typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;

} eTrabajo;


/** \brief
 * Muestra trabajo
 * \param trabajos[] eTrabajo vector trabajos
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param servicios[] eServicio vector servicios
 * \param tamTrabajo int tam vector trabajos
 * \param tamMasc int  tam vector mascotas
 * \param tamTipo int  tam vector tipos
 * \param tamColor int tam vector  colores
 * \param tamServ int  tam vector servicios
 * \param pos int posicion en el vector
 * \return int
 *
 */
int mostrarTrabajo(eTrabajo trabajos[],eMascota mascotas[], eTipo tipos[], eColor colores[],eServicio servicios[],int tamTrabajo, int tamMasc, int tamTipo, int tamColor, int tamServ, int pos);

/** \brief
 * Buscar proximo id libre en el vector
 * \param trabajos[] eTrabajo vector trabajos
 * \param tam int tamaño vector
 * \return int posicion libre
 *
 */
int BuscarIdTrabajoLibre(eTrabajo trabajos[], int tam);

/** \brief
 * Busca el id consecutivo al trabajo
 * \param trabajos[] eTrabajo vector trabajos
 * \param tam int tamaño vector
 * \return int  id trabajo
 *
 */
int BuscarProximoId(eTrabajo trabajos[], int tam);

/** \brief
 * Da de alta un trabajo
 * \param trabajos[] eTrabajo vector trabajos
 * \param idMascota int id mascota
 * \param idServicio int id servicio
 * \param tam int tamaño vector masc
 * \param idTrabajo int id del trabajo
 * \return int TRUE error , FALSE todo ok
 *
 */
int AltaTrabajo(eTrabajo trabajos[], int idMascota, int idServicio, int tam, int idTrabajo);

/** \brief
 * Listar trabajos
 * \param trabajos[] eTrabajo vector trabajos
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param servicios[] eServicio vector servicios
 * \param tamTrabajo int tam vector trabajos
 * \param tamMasc int  tam vector mascotas
 * \param tamTipo int  tam vector tipos
 * \param tamColor int tam vector  colores
 * \param tamServ int  tam vector servicios
 * \return void
 *
 */
void listarTrabajos(eTrabajo trabajos[],eMascota mascotas[],eTipo tipos[], eColor colores[],eServicio servicios[], int tamTrabajo,int tamMasc, int tamTipo, int tamColor, int tamServ);

/** \brief
 * Inicializa vector trabajos
 * \param trabajos[] eTrabajo vector trabajo
 * \param tam int tamaño vector
 * \param cardaDatos bandera que indica si se cargan o no los datos harcodeados
 * \return void
 *
 */
void InicializarTrabajos(eTrabajo trabajos[], int tam,int cargaDatos);

#endif // TRABAJO_H_INCLUDED
