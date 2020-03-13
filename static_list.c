/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"

void createEmptyList (tList* L) {                       //función que crea una lista vacía
    L->lastP = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList* L) {          //función que inserta un elemento en la lista
    if(L->lastP == SIZE - 1)                            //caso lista llena
        return false;
    else {
        L->lastP++;
        if (p == LNULL) {                                //caso posición nula
            L->data[L->lastP] = d;
        } else {                                         //caso de inserción en el medio
            for (int i = L->lastP; i > p; i--)
                L->data[i] = L->data[i-1];
            L->data[p] = d;
        }
        return true;
    }
}

bool copyList(tList L, tList* M) {                      //función que copia una lista
    tPosL p;
    for (p = 0; p <= L.lastP; p++)
        M->data[p] = L.data[p];
    M->lastP = L.lastP;
    return true;
}

void updateVotes(tNumVotes d, tPosL p, tList* L) {      //función que actualiza los votos de cada partido
    L->data[p].numVotes = d;
}

void deleteAtPosition(tPosL p, tList* L) {              //función que elimina una posición
    tPosL q;
    L->lastP--;
    for (q = p; q <= L->lastP; q++)
        L->data[q] = L->data[q+1];

}

void deleteList(tList* L) { //acabar

}

tPosL findItem(tPartyName d, tList L) {                 //función que devuelve la posición de un partido en la lista
    tPosL p;
    if (L.lastP == LNULL)                               //caso lista vacía
        return LNULL;
    else {
        for (p = 0; (p < L.lastP) && (strcmp(L.data[p].partyName, d) != 0); p++);
        if (strcmp(L.data[p].partyName, d) == 0)
            return p;
        else
            return LNULL;
    }
}

bool isEmptyList(tList L) {                         //función que comprueba que una lista está vacía
    return L.lastP == LNULL;
}

tItemL getItem(tPosL p, tList L) {                  //función que devuelve el contenido de una posición de la lista
    return L.data[p];
}

tPosL first(tList L) {                              //función que devuelve la primera posición de la lista
    return 0;
}

tPosL last(tList L) {                               //función que devuelve la última posición no vacía de la lista
    return L.lastP;
}

tPosL previous(tPosL p, tList L) {                  //función que devuelve la posición anterior a una dada
    return --p;
}

tPosL next(tPosL p, tList L) {                      //función que devuelve la posición siguiente a una dada
    if (p == last(L))                               //caso del último de la lista
        return LNULL;
    else
        return ++p;
}
