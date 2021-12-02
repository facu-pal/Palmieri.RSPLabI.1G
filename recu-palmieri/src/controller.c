#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "menu.h"
#include "utn.h"
#include "post.h"
#include "filtros.h"



int controller_loadFromText(char* path , LinkedList* pArrayPost){
	int retorno = -1;
	int auxParser;
	FILE *pArchivoTexto;

	pArchivoTexto = fopen(path, "r");

	if (pArchivoTexto == NULL) {
		printf("Este archivo no existe");
	} else {

		auxParser = parser_PeliculasFromText(pArchivoTexto,pArrayPost);
		printf("%d", auxParser);

		if (auxParser == 0) {
			fclose(pArchivoTexto);
			printf("Se lleyo correctamenta el archivo, y se cerro\n");
			retorno = 0;
		}
	}
	return retorno;
}





int controller_saveAsText(char* path , LinkedList* pArrayListEmer){
	int retorno = -1;
	int lenArrayPost = 0;
	char auxuser[1024];
	int auxid;
	int auxLike;
	int auxDisLike;
	int auxFollowers;




	FILE* pFileTexto;
	pFileTexto = fopen(path, "w");
	ePost* pPost=NULL;

	if(pArrayListEmer!=NULL && path != NULL)
	{
		lenArrayPost = ll_len(pArrayListEmer);

		if(pFileTexto != NULL)
		{
			fprintf(pFileTexto,"id,user,like,dislike,followers\n");
			for(int i = 0 ; i < lenArrayPost; i++)
			{
				pPost = ll_get(pArrayListEmer,i);
				post_getId(pPost,& auxid);
				post_getUser(pPost, auxuser);
				post_getLike(pPost,& auxLike);
				post_getDislike(pPost,&auxDisLike);
				post_getFollowers(pPost,& auxFollowers);

				fprintf(pFileTexto,"%d,%s,%d,%d,%d\n",auxid,auxuser,auxLike,auxDisLike,auxFollowers);
			}
			printf("EL archivo se guardo exitosamente\n");
			retorno = 0;
	        }else
	        {
	        	printf("Hubo un error al guardar el archivo\n");
	        }
	}
	fclose(pFileTexto);
	return retorno;
}



int controller_ListPost(LinkedList* pArrayPost)
{
    int todoOk = 0;
    ePost* auxEmer = NULL;

    if(ll_isEmpty(pArrayPost)== 0)
    {
        printf("****************************************************************************************************************************************************\n");
        printf("ID                           user                                   like                       dislike                       followers\n");
        printf("****************************************************************************************************************************************************\n");
        for( int i = 0; i < ll_len(pArrayPost); i++)
        {
        	auxEmer = (ePost*) ll_get(pArrayPost, i);
            mostrarPost(auxEmer);
        }
        printf("\n\n");
        todoOk = 1;
    }
    else
    {
        printf("LA LISTA ESTA VACIA\n");
    }
    return todoOk;
}

int controller_mapAEstadistica(LinkedList* pArrayPost)
{
    int todoOk = 0;
    pArrayPost = ll_map(pArrayPost, asignarEstadisticaLike);
    pArrayPost = ll_map(pArrayPost, asignarEstadisticaDisLike);
    pArrayPost = ll_map(pArrayPost, asignarEstadisticaFollowers);

    if(pArrayPost != NULL)
    {
    	controller_ListPost(pArrayPost);
        printf("GENEROS ASIGNADOS CON EXITO\n");
        todoOk = 1;
    }
    return todoOk;
}

int controller_filterMjPosteo(LinkedList* pArrayPost)
{
    int todoOk = 0;
    if (pArrayPost != NULL)
    {
       pArrayPost = ll_filter(pArrayPost, filtrar_MejorPost);

        if(pArrayPost != NULL)
        {
        	controller_ListPost(pArrayPost);
            system("pause");
            controller_saveAsText("MejorPost.csv", pArrayPost);
            todoOk = 1;
        }

    }
    return todoOk;
}

int controller_filterHeaters(LinkedList* pArrayPost)
{
	printf("1\n");
    int todoOk = 0;
    if (pArrayPost != NULL)
    {
    	printf("2\n");
       pArrayPost = ll_filter(pArrayPost, filtrar_Heaters);
       printf("3\n");
        if(pArrayPost != NULL)
        {
        	printf("4\n");
        	controller_ListPost(pArrayPost);
            system("pause");
            controller_saveAsText("HeartersPost.csv", pArrayPost);
            todoOk = 1;
        }

    }
    return todoOk;
}

int controller_ordenarFollow(LinkedList* pArrayPost)
{
    int todoOk = 0;

    if (pArrayPost != NULL)
    {
       ll_sort(pArrayPost, compararostFollow, 0);
        system("cls");
        controller_ListPost(pArrayPost);
        printf("post ordenados con exito\n");
        todoOk = 1;
    }
    return todoOk;
}
int controller_masPopular(LinkedList *pArrayPost) {

	int todoOk = 0;
	int masLike = -1;
	void *elemento = NULL;
	int like=0;
	char user[50];

	if (pArrayPost != NULL) {
		for (int i = 0; i < ll_len(pArrayPost) ; i++) {

			elemento = ll_get(pArrayPost, i);
			post_getLike(elemento, &like);
			if (i == 0 || like > masLike) {
				masLike = like;
			}
		}

		for (int i = 0; i < ll_len(pArrayPost) ; i++) {
			elemento = ll_get(pArrayPost, i);
			post_getLike(elemento, &like);
			post_getUser(elemento, user);
			if ( like == masLike) {
				printf("Los user con mas likeado son:\n %s",user);
			}
		}
			printf("\n con una cantidad de %d likes\n",masLike);

		todoOk = 1;
	}

	return todoOk;

}
