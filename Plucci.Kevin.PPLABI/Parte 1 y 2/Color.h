#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

/** \brief
 * Lista los colores de mascotas disponibles
 * \param colores[] eColor vector colores
 * \param tam int  tamaño vector
 * \return void
 *
 */
void ListarColores(eColor colores[],int tam);

/** \brief
 * Muestra un color de mascota
 * \param colores[] eColor vector colores
 * \param tam int tamaño vector
 * \param id int id color
 * \return char* descripcion del color
 *
 */
char * MostrarColor(eColor colores[],int tam, int id);


#endif // COLOR_H_INCLUDED
