/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardo
 * AUTHOR 2: Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

#include <stdio.h>
#include <string.h>
#include "types.h"


// FUNCTIONS

void createEmptyList (tList* L) {       //funcion que crea una lista vacia
    *L = LNULL;
}

bool createNode (tPosL* p){            //funcion que crea un nodo
    *p = malloc(sizeof(struct tNode));
    return  *p != LNULL;
}

bool insertItem (tItemL d, tPosL p, tList* L){         //funcion que crea un elemento en la lista
    tPosL q,r;

    if (!createNode(&q)) {                //si no se ha creado nodo previamente
        return false;
    }
    else{
        q -> data = d; // nodo final con contenido d
        q -> next = LNULL; // y de puntero a siguiente = NULL

        if(*L == LNULL)   //caso lista vacia
            *L = q;

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

bool copyList (tList L, tList* M) {     //funcion que copia una lista
    tPosL p,q,r;

    if (L == LNULL) {           //caso lista vacia
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

void updateVotes (tNumVotes d, tPosL p, tList* L) {   //funcion que actualiza los votos de un partido
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



tPosL  findItem (tPartyName d, tList L) {      //funcion que localiza un elemento en la lista
    tPosL q;

    for ( q = L;  (q != LNULL) && (strcmp(q -> data.partyName, d) != 0); q = q->next);
    return q;
}

bool isEmptyList (tList L) {     //funcion que comprueba si la lista esta vacia
    return L == LNULL;
}

tItemL getItem (tPosL p, tList L) {     //funcion que devuelve un elemento de la lista
    return p -> data;
}

tPosL first (tList L) {          //funcion que devuelve el primer elemento de la lista
    return L;
}

tPosL  last (tList L) {         //funcion que devuelve el ultimo elemento de la lista
    tPosL  q;

    for(q=L; q->next != LNULL; q = q->next); //recorre la lista hasta apuntar a LNULL: ultima posicion
    return q;
}

tPosL next (tPosL p, tList L) {    //funcion que devuelve la posicion siguiente a una dada
    return p -> next;
}

tPosL previous (tPosL p, tList L) {    //funcion que devuelve la posicion anterior a una dada
    tPosL q;

    if (p == L)  //caso inicio de la lista
        return LNULL;

    else {
        for(q=L; q->next != p; q = q->next);
        return q;
    }
}

