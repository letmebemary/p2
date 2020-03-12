/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

#define LNULL NULL
#define MAX 23

#include <stdbool.h>
#include <stdlib.h>


typedef struct tNode* tPosL; //contenido y siguiente nodo
struct tNode{
    tItemL dato;
    tPosL lastpos;
};

typedef tPosL tList; //la propia lista


void createEmptyList (tList*);
bool createNode(tPosL*);
bool insertItem(tItemL, tPosL, tList*);
bool copyList(tList, tList*);
void updateVotes(tNumVotes, tPosL, tList*);
void deleteAtPosition(tPosL, tList*);
void deleteList(tList*);
tPosL findItem(tPartyName, tList);
bool isEmptyList(tList);
tItemL getItem(tPosL, tList);
tPosL first(tList);
tPosL last(tList);
tPosL previous(tPosL, tList);
tPosL next(tPosL, tList);



#endif
