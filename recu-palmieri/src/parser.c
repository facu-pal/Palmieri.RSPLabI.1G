#include <stdio.h>
#include "post.h"

#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */




int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPeliculas)
{
	int retorno = -1;
	int cantLeido;
	char buffer[5][128];
	ePost *pAuxPelis = NULL;

	if (pFile != NULL && pArrayListPeliculas != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3], buffer[4]);
		do {
			cantLeido = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],	buffer[1], buffer[2], buffer[3], buffer[4]);
			if (cantLeido < 4) {
				eliminar_post(pAuxPelis);
				retorno = -1;
				break;
			} else {
				pAuxPelis = post_newParametros(buffer[0], buffer[1],	buffer[2], buffer[3], buffer[4]);
				if (pAuxPelis != NULL) {
					ll_add(pArrayListPeliculas, pAuxPelis);
					retorno = 0;
				}
			}
		} while (!feof(pFile));
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int parser_PeliculasFromBinary(FILE *pFile, LinkedList *pArrayListPeliculas) {
	int retorno = -1;
	int cantLeido;
	ePelicula *AuxPelis = NULL;

	if (pFile != NULL && pArrayListPeliculas != NULL) {
		do {
			AuxPelis = nueva_pelicula();
			if (AuxPelis != NULL) {
				cantLeido = fread(AuxPelis, sizeof(ePelicula), 1, pFile);
				if (cantLeido != 1) {
					eliminar_pelicula(AuxPelis);
					break;
				} else {
					ll_add(pArrayListPeliculas, AuxPelis);
					retorno = 0;
				}
			}
		} while (!feof(pFile));
	}
	return retorno;
}*/
