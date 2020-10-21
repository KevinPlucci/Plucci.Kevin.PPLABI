#include "Color.h"
#include <stdio.h>
#include <string.h>
#include "Cliente.h"
#include "DataStoreCliente.h"

void inicializarCliente(eCliente clientes[], int tam)
{
    for(int i =0;i<tam ;i++)
    {
        clientes[i].id = vCliente[i].id;
        strcpy(clientes[i].nombre , vCliente[i].nombre);
        clientes[i].sexo = vCliente[i].sexo;
    }
}

char * MostrarUnCliente(eCliente clientes[], int tam, int id)
{
    for(int i =0; i< tam ; i++)
    {
        if(clientes[i].id == id)
        {
            return clientes[i].nombre;
        }
    }
    return "";
}


void ListarClientes(eCliente clientes[],int tam)
{
    printf("\n");
    printf("ID:  Nombre: sexo:\n");
    printf("-------------------------\n");
    for(int i = 0;i < tam; i++)
    {
        printf("%d  %s  %c\n",clientes[i].id,clientes[i].nombre,clientes[i].sexo);
    }
}


int BuscarIndexCliente(eCliente clientes[], int tam, int id)
{
    for(int i = 0; i < tam ; i++)
    {
        if(clientes[i].id == id)
        {
            return i;
        }
    }
    printf("Cliente no se encuentra\n");
    return -1;
}
