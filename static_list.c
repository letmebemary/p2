/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"

void createEmptyList (tList* L) {
    L->lastp = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList* L) {
    if(L->lastp == SIZE-1)
        return false;
    else {
        L->lastp++;
        if (p == LNULL) {
            L->data[L->lastp] = d;
        } else {
                for (int i = L->lastp; i > p+1; i--)
                    L->data[i] = L->data[i-1];
                L->data[p] = d;
        }
        return true;
    }
}

bool copyList(tList L, tList* M) {
    tPosL p;
    for (p = 0; p <= L.lastp; p++)
        M->data[p] = L.data[p];
    M->lastp = L.lastp;
    return true;
}

void updateVotes(tNumVotes d, tPosL p, tList* L) {
    L->data[p].numVotes = d;
}

void deleteAtPosition(tPosL p, tList* L) {
    tPosL q;
    L->lastp--;
    for (q = p; q <= L->lastp; q++)
        L->data[q] = L->data[q+1];

}

void deleteList(tList* L) { //acabar

}

tPosL findItem(tPartyName d, tList L) {
    tPosL p;
    if (L.lastp == LNULL)
        return LNULL;
    else {
        for (p = 0; (p < L.lastp) && (strcmp(L.data->partyName[p], d) != 0); p++) {
            if (strcmp(L.data->partyName[p], d) == 0)
                return p;
            else
                return LNULL;
        }
    }
}

bool isEmptyList(tList L) {
    return L.lastp == LNULL;
}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

tPosL first(tList L) {
    return 0;
}

tPosL last(tList L) { //mirar que es laspos == iguana
    return L.lastp;
}

tPosL previous(tPosL p, tList L) {
    return --p;
}

tPosL next(tPosL p, tList L) {
    if (p == last(L))
        return LNULL;
    else
        return ++p;
}