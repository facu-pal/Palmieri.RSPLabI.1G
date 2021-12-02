/*
 * post.h
 *
 *  Created on: 2 dic 2021
 *      Author: facun
 */

#ifndef POST_H_
#define POST_H_


typedef struct
{
    int id;
    char user[50];
    int like;
    int dislikes;
    int followers;

}ePost;

#endif /* POST_H_ */

//constructores
ePost* nueva_post();
ePost* post_newParametros(char* idStr,char* user, char* like,char* dislike,char* followers);
void eliminar_post(ePost* post);

//setters
int post_setId(ePost* post,int id);
int post_setUser(ePost* post,char* user);
int post_setLike(ePost* post,int like);
int post_setDislike(ePost* post,int disklike);
int post_setFollowers(ePost* post,int follow);

//getters
int post_getId(ePost* post,int* id);
int post_getUser(ePost* post,char* user);
int post_getLike(ePost* post,int* like);
int post_getDislike(ePost* post,int* disklike);
int post_getFollowers(ePost* post,int* follow);

//parcial
int mostrarPost(ePost* pPost);
void* asignarEstadisticaLike(void* post);
void* asignarEstadisticaDisLike(void* post);
void* asignarEstadisticaFollowers(void* post);
int compararostFollow(void* pPostA,void* pPostB);
