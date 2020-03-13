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
    L->lastP = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList* L) {
    if(L->lastP == SIZE - 1)
        return false;
    else {
        L->lastP++;
        if (p == LNULL) {
            L->data[L->lastP] = d;
        } else {
                for (int i = L->lastP; i > p; i--)
                    L->data[i] = L->data[i-1];
                L->data[p] = d;
        }
        return true;
    }
}

bool copyList(tList L, tList* M) {
    tPosL p;
    for (p = 0; p <= L.lastP; p++)
        M->data[p] = L.data[p];
    M->lastP = L.lastP;
    return true;
}

void updateVotes(tNumVotes d, tPosL p, tList* L) {
    L->data[p].numVotes = d;
}

void deleteAtPosition(tPosL p, tList* L) {
    tPosL q;
    L->lastP--;
    for (q = p; q <= L->lastP; q++)
        L->data[q] = L->data[q+1];

}

void deleteList(tList* L) { //acabar

}

tPosL findItem(tPartyName d, tList L) {
    tPosL p;
    if (L.lastP == LNULL)
        return LNULL;
    else {
        for (p = 0; (p < L.lastP) && (strcmp(L.data[p].partyName, d) != 0); p++);
        if (strcmp(L.data[p].partyName, d) == 0)
            return p;
        else
            return LNULL;
    }
}

bool isEmptyList(tList L) {
    return L.lastP == LNULL;
}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

tPosL first(tList L) {
    return 0;
}

tPosL last(tList L) { //mirar que es laspos == iguana
    return L.lastP;
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