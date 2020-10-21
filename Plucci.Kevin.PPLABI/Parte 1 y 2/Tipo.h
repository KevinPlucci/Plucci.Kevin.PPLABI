#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];

} eTipo;

/** \brief
 * Lista tipos de mascotas
 * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \return void
 *
 */
void ListarTipos(eTipo tipos[],int tam);
/** \brief
 *
  * \param tipos[] eTipo vector tipos
 * \param tam int tamaño vector
 * \param id int id tipo
 * \return char* descripcion del tipo de mascota
 *
 */
char * MostrarTipo(eTipo tipos[],int tam, int id);


#endif // TIPO_H_INCLUDED
