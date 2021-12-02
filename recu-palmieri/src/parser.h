/*
 * parser.h
 *
 *  Created on: 29 nov 2021
 *      Author: facun
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"


int parser_PeliculasFromText(FILE* pFile , LinkedList* pArrayListPeliculas);
int parser_PeliculasFromBinary(FILE* pFile , LinkedList* pArrayListPeliculas);


#endif /* PARSER_H_ */
