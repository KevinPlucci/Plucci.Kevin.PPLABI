#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

/** \brief
 * Muestra una fecha
 * \param fecha eFecha
 * \return void
 *
 */
void MostrarFecha(eFecha fecha);
/** \brief
 * Crea una fecha
 * \return eFecha estructura fecha
 *
 */
eFecha crearFecha();
#endif // FECHA_H_INCLUDED
