#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "post.h"


int filtrar_MejorPost(void* pelicula)
{
    int todoOk = 0;
    ePost* auxPost = NULL;
    if (pelicula != NULL)
    {
    	auxPost = (ePost*) pelicula;
        if (auxPost->like > 3000)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrar_Heaters(void* pelicula)
{
    int todoOk = 0;
    ePost* auxPost = NULL;
    if (pelicula != NULL)
    {
    	auxPost = (ePost*) pelicula;
        if (auxPost->dislikes > auxPost->like)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
