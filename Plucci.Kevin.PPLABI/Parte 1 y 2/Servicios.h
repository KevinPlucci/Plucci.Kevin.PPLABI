#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
int id;
    char descripcion[20];
    float precio;
}eServicio;

/** \brief
 *  Lista servicios
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \return void
 *
 */
void listarServicios(eServicio servicios[], int tam);
/** \brief
 * Muestra servicio
 * \param servicios[] eServicio vector servicios
 * \param pos en el vector
 * \return void
 *
 */
void mostrarServicio(eServicio servicios[], int pos);
/** \brief
 * Muestra servicio
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
  * \param id int id del servicio
 * \return void
 *
 */
void mostrarServicioById(eServicio servicios[],int tam, int id);
/** \brief
 * Busca proxima posicion libre
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector
 * \param id int id del servicio
 * \return int
 *
 */
int BuscarServicioPosById(eServicio servicios[], int tam , int id);

#endif // SERVICIOS_H_INCLUDED
