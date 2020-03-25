/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardo
 * AUTHOR 2: Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#include "static_list.h"

void createEmptyList (tList* L) {                   //funcion que crea una lista vacia
    L->lastP = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList* L) {    //funcion que inserta un elemento en la lista
    if(L->lastP == SIZE - 1)                      //caso lista llena
        return false;
    else {
        L->lastP++;
        if (p == LNULL) {                        //caso posicion nula
            L->data[L->lastP] = d;
        } else {                                //caso de insercion en el medio
                for (int i = L->lastP; i > p; i--)
                    L->data[i] = L->data[i-1];
                L->data[p] = d;
        }
        return true;
    }
}

bool copyList(tList L, tList* M) {           //funcion que copia una lista
    tPosL p;
    for (p = 0; p <= L.lastP; p++)
        M->data[p] = L.data[p];
    M->lastP = L.lastP;
    return true;
}

void updateVotes(tNumVotes d, tPosL p, tList* L) {   //funcion que actualiza los votos de cada partido
    L->data[p].numVotes = d;
}

void deleteAtPosition(tPosL p, tList* L) {          //funcion que elimina una posicion
    tPosL q;
    L->lastP--;
    for (q = p; q <= L->lastP; q++)
        L->data[q] = L->data[q+1];

}


tPosL findItem(tPartyName d, tList L) {          //funcion que devuelve la posicion de un partido en la lista
    tPosL p;
    if (L.lastP == LNULL)                        //caso lista vacia
        return LNULL;
    else {
        for (p = 0; (p < L.lastP) && (strcmp(L.data[p].partyName, d) != 0); p++);
        if (strcmp(L.data[p].partyName, d) == 0)
            return p;
        else
            return LNULL;
    }
}

bool isEmptyList(tList L) {                  //funcion que comprueba que una lista esta vacia
    return L.lastP == LNULL;
}

tItemL getItem(tPosL p, tList L) {          //funcion que devuelve el contenido de una posicion de la lista
    return L.data[p];
}

tPosL first(tList L) {                     //funcion que devuelve la primera posicion de la lista
    return 0;
}

tPosL last(tList L) {                     //funcion que devuelve la ultima posicion no vacia de la lista
    return L.lastP;
}

tPosL previous(tPosL p, tList L) {       //funcion que devuelve la posicion anterior a una dada
    return --p;
}

tPosL next(tPosL p, tList L) {           //funcion que devuelve la posicion siguiente a una dada
    if (p == last(L))                    //caso del ultimo de la lista
        return LNULL;
    else
        return ++p;
}
