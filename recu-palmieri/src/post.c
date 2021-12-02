#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "post.h"
#include "LinkedList.h"


ePost* nueva_post()
{
    ePost* nuevaPost= (ePost*) malloc(sizeof(ePost));

    if(nuevaPost != NULL)
    {
    	nuevaPost->id= 0;
        strcpy(nuevaPost->user, "");
        nuevaPost->like= 0;
        nuevaPost->dislikes = 0;
        nuevaPost->followers = 0;

    }

    return nuevaPost;
}

ePost* post_newParametros(char* idStr,char* user, char* like,char* dislike,char* followers)
 {
	ePost *nuevaEmer = nueva_post();
	if(nuevaEmer !=NULL){
		post_setId(nuevaEmer, atoi(idStr));
		post_setUser(nuevaEmer, user);
		post_setLike(nuevaEmer, atoi(like));
        post_setDislike(nuevaEmer, atoi(dislike));
        post_setFollowers(nuevaEmer, atoi(followers));


	}
	return nuevaEmer;
}

void eliminar_post(ePost* post){
    free(post);
}

//setter
int post_setId(ePost* post,int id){
	int retorno = 0;

	if (post != NULL && id > 0) {
		post->id = id;
		retorno = 1;
	}

	return retorno;
}
int post_setUser(ePost* post,char* user){
	int retorno = 0;
		if (post != NULL && user != NULL && strlen(user) > 0
				&& strlen(user) < 49) {

			strcpy(post->user, user);

			retorno = 1;
		}

		return retorno;
}
int post_setLike(ePost* post,int like){
	int retorno = 0;

	if (post != NULL && like > 0) {
		post->like = like;
		retorno = 1;
	}

	return retorno;
}
int post_setDislike(ePost* post,int disklike){
	int retorno = 0;

	if (post != NULL && disklike > 0) {
		post->dislikes = disklike;
		retorno = 1;
	}

	return retorno;
}
int post_setFollowers(ePost* post,int follow){
	int retorno = 0;

	if (post != NULL && follow > 0) {
		post->followers = follow;
		retorno = 1;
	}

	return retorno;
}
//geter

int post_getId(ePost* post,int* id){
    int retorno= 0;
    if ( post != NULL && id != NULL)
    {
        (*id) = post->id;
        retorno = 1;
    }
    return retorno;
}
int post_getUser(ePost* post,char* user){
	   int retorno= 0;
	    if ( post != NULL && user != NULL)
	    {
	        strcpy( user,post->user);
	        retorno = 1;
	    }
	    return retorno;
}
int post_getLike(ePost* post,int* like){
    int retorno= 0;
    if ( post != NULL && like != NULL)
    {
        (*like) = post->like;
        retorno = 1;
    }
    return retorno;
}
int post_getDislike(ePost* post,int* disklike){
    int retorno= 0;
    if ( post != NULL && disklike != NULL)
    {
        (*disklike) = post->dislikes;
        retorno = 1;
    }
    return retorno;
}
int post_getFollowers(ePost* post,int* follow){
    int retorno= 0;
    if ( post != NULL && follow != NULL)
    {
        (*follow) = post->followers;
        retorno = 1;
    }
    return retorno;
}

//cosas para parcial
int mostrarPost(ePost* pPost){
	int retorno = 0;
	char auxuser[1024];
	int auxid;
	int auxLike;
	int auxDisLike;
	int auxFollowers;

	    if(pPost != NULL)
	    {
	        if(		post_getId(pPost,& auxid)&&
			post_getUser(pPost, auxuser)&&
			post_getLike(pPost,& auxLike)&&
			post_getDislike(pPost,&auxDisLike)&&
			post_getFollowers(pPost,& auxFollowers))
	        {
	        	printf("%2d              %28s                     %5d                     %5d                     %5d\n", auxid,auxuser, auxLike, auxDisLike,auxFollowers);

	            retorno =1;
	        }
	    }
	    return retorno;
}


void* asignarEstadisticaLike(void* post)
{
    ePost* auxPost = NULL;
    int like;


    if (post != NULL)
    {
        auxPost = (ePost*) post;
        like = 50 + rand()%(500-5000);


        auxPost->like=like;


    }
    return auxPost;

}

void* asignarEstadisticaDisLike(void* post){
    ePost* auxPost = NULL;
    int disLike;


    if (post != NULL)
    {
        auxPost = (ePost*) post;
        disLike = 50 + rand()%(300-3500);

        auxPost->dislikes=disLike;


    }
    return auxPost;

}
void* asignarEstadisticaFollowers(void* post){
    ePost* auxPost = NULL;
    int follow;


    if (post != NULL)
    {
        auxPost = (ePost*) post;
        follow = rand() % 10000 + 10000;


        auxPost->followers=follow;


    }
    return auxPost;

}


int compararostFollow(void* pPostA,void* pPostB)
{
    int todoOk= 0;

    if(  (  ((ePost*)pPostA)->followers >((ePost*)pPostB)->followers  )
           )
    {
        todoOk = 1;
    }
    if(  (  ((ePost*)pPostA)->followers<  ((ePost*)pPostB)->followers    )
          )
    {
        todoOk = -1;
    }
    return todoOk;

}


