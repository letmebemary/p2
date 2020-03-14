/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardo
 * AUTHOR 2: Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

#define LNULL -1
#define SIZE 25

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int tPosL;
typedef struct{
    tItemL data[SIZE];
    tPosL lastP;
}tList;


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
