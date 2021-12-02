#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"
#include "parser.h"
#include "controller.h"
#include "utn.h"
#include "menu.h"
#include "post.h"

int main(void) {
	setbuf(stdout, NULL);
	 srand(time(NULL));

	char seguir = 's';

	LinkedList* listaPost = ll_newLinkedList();

	 do
	    {
	        switch(menu())
	        {
	        case 1:
				if (controller_loadFromText("posts.csv", listaPost)) {
					printf("Error durante la llamada\n");
				}
			break;
	        case 2:
	            if(!controller_ListPost(listaPost)){
	               printf("Lista vacia\n");
	            }
	            break;
	        case 3:
	        	if(!controller_mapAEstadistica(listaPost)){
		         printf("Error a generar las estadisticas\n");

	        	}
	            break;

	        case 4:
	        	if(!controller_filterMjPosteo(listaPost)){
			         printf("Error a filtrar por mejores posteos\n");

	        	}
	        	break;
	        case 5:
	        	if(!controller_filterHeaters(listaPost)){
			         printf("Error a filtrar mas hearters\n");
	        	}
	        	break;
	        case 6:
	        	if(!controller_ordenarFollow(listaPost)){
			         printf("Error al ordenar\n");

	        	}

	        	break;
	        case 7:
	        	if(!controller_masPopular(listaPost)){
			         printf("Error al buscar al o mas populares\n");

	        	}

	        	break;
	        case 8:
	        	if (utn_getConfirm() == 0) {
	        		seguir = 'n';
	        	}
	            break;
	        default:
	            printf("Opcion invalida\n");
	            printf("Ingrese otra opcion:\n");
	            break;
	        }

	        system("pause");
	    }while(seguir == 's');


	return EXIT_SUCCESS;
}
