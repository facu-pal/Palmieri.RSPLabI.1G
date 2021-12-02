/*
 * controller.h
 *
 *  Created on: 29 nov 2021
 *      Author: facun
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"


int controller_loadFromText(char* path , LinkedList* pArrayPost);

int controller_saveAsText(char* path , LinkedList* pArrayPost);

int controller_ListPost(LinkedList* pArrayPost);

int controller_sortPost(LinkedList* pArrayPost);

int controller_mapAEstadistica(LinkedList* pArrayPost);

int controller_filterMjPosteo(LinkedList* pArrayPost);

int controller_filterHeaters(LinkedList* pArrayPost);

int controller_ordenarFollow(LinkedList* pArrayPost);

int controller_masPopular(LinkedList *pArrayPost);
#endif /* CONTROLLER_H_ */
