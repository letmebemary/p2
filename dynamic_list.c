/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardo
 * AUTHOR 2: , Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

#include <stdio.h>
#include <string.h>
#include "types.h"


// FUNCTIONS

void createEmptyList (tList* L) {
    *L = LNULL;
}

bool createNode (tPosL* p){
    *p = malloc(sizeof(struct tNode));
    return  *p != LNULL;
}

bool insertItem (tItemL d, tPosL p, tList* L){
    tPosL q,r;

    if (!createNode(&q)) {//si no se ha creado nodo previamente
        printf("no fue posible crear el nodo\n");
        return false;
    }
    else{
        q -> data = d; // nodo final con contenido d
        q -> next = LNULL; // y de puntero a siguiente = NULL

        if(*L == LNULL)   //caso lista vacia
            *L = q;       //

        else if (p == LNULL){
            for(r = *L;r->next != LNULL;r = r->next); //recorrer la lista hasta el ultimo puntero a nodo, hasta q sea NULL
            r->next = q; //asignamos entonces al ultimo nodo

        } else if (p == *L) {
            q -> next = *L; //inserta al principio de la lista
            *L = q;

        } else {
            q -> data = p-> data; //para meter por el medio un elemento
            p -> data = d;
            q -> next = p -> next;
            p -> next = q;
        }
    }
    return 1;
}

bool copyList (tList L, tList* M) {
    tPosL p,q,r;

    if (L == LNULL) {
        *M = LNULL;
        return true;

    } else {
        p = L;
        *M = LNULL;
        while (p != LNULL) {
            if (!createNode(&r))
                return false;
            else {
                r ->data = p->data;
                r->next = LNULL;
                if(p==L){
                    *M = r;
                    q = r;
                } else {
                    q->next = r;
                    q = r;
                }
                p = p->next;
            }
        }
        return true;
    }
}

void updateVotes (tNumVotes d, tPosL p, tList* L) {
    p -> data.numVotes = d;
}

void deleteAtPosition (tPosL p, tList* L) {
    tPosL q;

    if (p == *L) // en caso de que sea el primer elemento
        *L = (*L) -> next; // (*L) o p, es lo mismo

    else if (p-> next == LNULL) {
        for(q=*L; q->next!=p; q=q->next); //borrar ultimo de la lista
        q-> next = LNULL;

    } else {
        q = p -> next; //borrar un elemento por el medio
        p -> data = q -> data;
        p -> next = q -> next;
        p = q;
    }
    free(p);
}

void deleteList (tList *L){
    tPosL p;

    while(*L != LNULL) { // borra desde el primer hasta el ultimo apuntando con *L al siguiente
        p = *L;
        *L = (*L) -> next; //(*L) o p
        free(p);
    }
}

tPosL  findItem (tPartyName d, tList L) {
    tPosL q;
    /*(q -> data != d)*/

    for ( q = L;  (q != LNULL) && (strcmp(q -> data.partyName, d) != 0); q = q->next);
    return q;
}

bool isEmptyList (tList L) {
    return L == LNULL;
}

tItemL getItem (tPosL p, tList L) {
    return p -> data;
}

tPosL first (tList L) {
    return L;
}

tPosL  last (tList L) {
    tPosL  q;

    for(q=L; q->next != LNULL; q = q->next);
    return q;
}

tPosL next (tPosL p, tList L) {
    return p -> next;
}

tPosL previous (tPosL p, tList L) {
    tPosL q;

    if (p == L)
        return LNULL;

    else {
        for(q=L; q->next != p; q = q->next);
        return q;
    }
}

