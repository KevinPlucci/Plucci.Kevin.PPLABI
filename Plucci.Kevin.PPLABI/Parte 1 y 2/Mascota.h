#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "Servicios.h"
#include "Color.h"
#include "Cliente.h"
#include "Tipo.h"


typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int idCliente;
    float edad;
    int isEmpty;
} eMascota;

/** \brief
 * Inicializa un vector
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param servicios[] eServicio vector servicio
 * \param tamM int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \param tamS int tama�o vector servicios
 * \return void
 *
 */
void inicializarVectores(eMascota mascotas[],eTipo tipos[],eColor colores[],eServicio servicios[],eCliente clientes[],int tamM, int tamT, int tamC, int tamS, int tamClientes);

/** \brief
 * Da de alta una mascota
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param tamMasc int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \return int False alta correcta, TRUE error
 *
 */
int ALTA(eMascota mascotas[],eColor colores[], eTipo tipos[], eCliente clientes[],int tamMasc, int tamC, int tamT, int id,int tamClientes);

/** \brief
 * Da de baja una mascota
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param tamMasc int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \param id int id mascota
 * \return int False alta correcta, TRUE error
 *
 */
int BAJA(eMascota mascotas[],eColor colores[], eTipo tipos[], eCliente clientes[],int tamMasc, int tamC, int tamT,int id, int tamCliente);

/** \brief
 * Modifica una mascota
* \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param tamMasc int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \param id int id mascota
 * \return int False alta correcta, TRUE error
 *
 */
int MODIFICAR(eMascota mascotas[],eColor colores[], eTipo tipos[], eCliente clientes[], int tamMasc, int tamC, int tamT,int id, int tamCliente);

/** \brief
 *  Inicializa una mascota
 * \param mascotas[] eMascota vector mascota
 * \param tam  tama�o vector mascotas
 * \return void
 *
 */
void InicializarMascotas(eMascota mascotas[], int tam);

/** \brief
 * Busca posicion en en el vector segun id
 * \param mascotas[] eMascota vector mascotas
 * \param tam int tama�o vector mascotas
 * \param id int id mascota
 * \return int posicion en el vector
 *
 */
int BuscarPosById(eMascota mascotas[], int tam, int id);

/** \brief
 * Muestra mascota
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param index int  posicion en el vector
* \param tamMasc int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \return void
 *
 */
void MOSTRARMASCOTA(eMascota mascotas[],eTipo tipos[], eColor colores[], eCliente clientes[],int index, int tam, int tamT, int tamC, int tamCliente);

/** \brief
 * Busca la proxima posicion libre en el vector
 * \param mascotas[] eMascota  vector mascotas
 * \param tam int tama�o vector mascotas
 * \return int posicion libre en el vector
 *
 */
int BuscarIdLibre(eMascota mascotas[], int tam);

/** \brief
 * Lista masctotas
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param tamM int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \return void
 *
 */
void ListarMascotas(eMascota mascotas[],eTipo tipos[], eColor colores[],eCliente clientes[],int tamM, int tamT, int tamC, int tamClientes);

/** \brief
 * Intercambia informacion en el vector
 * \param mascotas[] eMascota
 * \param i int
 * \param j int
 * \return void
 *
 */
void makeSwap(eMascota  mascotas[], int i, int j);

/** \brief
 * Ordena vector mascotas con ordenamiento burbuja
 * \param mascotas[] eMascota vector mascota
 * \param tam int tama�o vector
 * \return void
 *
 */
void OrdenarVectorBurbuja(eMascota mascotas[], int tam);


/** \brief
 * Muestra mascota s/ id
 * \param mascotas[] eMascota vector mascotas
 * \param tipos[] eTipo  vector tipos de mascotas
 * \param colores[] eColor vector colores de mascotas
 * \param tam int tama�o vector mascotas
 * \param tamT int tama�o vector tipos
 * \param tamC int tama�o vector colores
 * \return void
 *
 */
void MOSTRARMASCOTABYID (eMascota mascotas[],eTipo tipos[], eColor colores[],eCliente clientes[],int id, int tam, int tamT, int tamC, int tamClientes);
#endif // MASCOTA_H_INCLUDED
