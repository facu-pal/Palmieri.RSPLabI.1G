#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/*


*/

int menu()
{
    int opcion = 0;
    system("cls");
    printf("    ***menu de post ***\n");
    printf("1- Cargar los datos \n");
    printf("2- Listar\n");
    printf("3- asignar estadistica\n");
    printf("4- filtrar por mejor posteos\n");
    printf("5- filtrar por heaters \n");
    printf("6- ordenar\n");
    printf("7- Mas likeado post\n");
    printf("8- Salir\n");
    fflush(stdin);
    utn_getInt(&opcion,"Ingrese opcion: \n", "*ingrese opcion:", 1,8, 20);

    return opcion;
}




