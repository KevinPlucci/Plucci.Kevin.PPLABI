#ifndef VALIDACIONESMASCOTAS_H_INCLUDED
#define VALIDACIONESMASCOTAS_H_INCLUDED
#include "Servicios.h"
#include "Mascota.h"
#include "Color.h"
#include "Tipo.h"
#include "Cliente.h"

/** \brief
 * Valida edad
 * \param edad float edad
 * \return int TRUE / FALSE
 *
 */
int validaciones_validarEdad(float edad);

/** \brief
 * Valida color
 * \param colores[] eColor vector colores
 * \param tam int tamaño vector
 * \param id int id color
 * \return int TRUE / FALSE
 *
 */
int validaciones_ValidarColorValido(eColor colores[], int tam, int id);

/** \brief
 * Valida tipo de mascota
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param id int id mascota
 * \return int TRUE / FALSE
 *
 */
int validaciones_ValidarTipoValido(eTipo tipos[], int tam, int id);

/** \brief
 * valida mascota
 * \param masc[] eMascota vector mascota
 * \param tam int tamaño vector
 * \param idMascota int id mascota
 * \return int TRUE / FALSE
 *
 */
int validaciones_ValidarMascota(eMascota masc[], int tam, int idMascota);

/** \brief
 * vaida un servicio
 * \param servicios[] eServicio vector servicios
 * \param tam int tamaño vector serv
 * \param idServicio int id servicio
 * \return int TRUE / FALSE
 *
 */
int validaciones_ValidarServicio(eServicio servicios[], int tam, int idServicio);

int validaciones_ValidarCliente(eCliente clientes[], int tam, int id);

#endif // VALIDACIONESMASCOTAS_H_INCLUDED
