/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardo
 * AUTHOR 2: , Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#define LNULL NULL

#include <stdbool.h>
#include <stdlib.h>


typedef struct tNode* tPosL; //contenido y siguiente nodo
struct tNode{
    tItemL data;
    tPosL next;
};

typedef tPosL tList; //la propia lista


void createEmptyList (tList*);
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



