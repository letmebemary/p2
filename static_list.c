/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"

/* Write your code here... */
void createEmptyList (tList* l) {
    l->lastpos = LNULL
}

bool insertItem(tItemL d, tPosL p, tList* l) {
    if(l->lastpos == MAX-1)
        return false;
    else {
        l->lastpos++
        if (p == LNULL) {
            L->dato[lastpos] = d;
            else {
                for (int i = l->lastpos; i > p; i--) {
                    l->dato[i] = l->dato[i-1];
                }
            }
        }
    }
    return true;
}

bool copyList(tList l, tList* m) {
    tPosL p;
    for (p = 0; p < l.lastpos; p++) {
        m->dato[p] = l->dato[p];
    }
    m->lastpos = l.lastpos;
    return true;
}

void updateVotes(tNumVotes d, tPosL p, tList* l) {
    l->dato[p] = d;
}

void deleteAtPosition(tPosL p, tList* l) {
    tPosL q;
    l->lastpos--;
    for (q = p; q <= l->lastpos; q++) {
        l.dato[q] = l.dato[q++];
    }
}

void deleteList(tList*l) { //acabar

}

tPosL findItem(tPartyName d, tList l) {
    tPosL p;
    if (l.lastpos == LNULL)
        return LNULL;
    else {
        for (p = 0; p < l.lastpos && (l.dato[p] != d); p++) {
            if (l.dato[p] == d)
                return p;
            else
                return LNULL;
        }
    }
}

bool isEmptyList(tList l) {
    return l.lastpos == LNULL;
}

tItemL getItem(tPosL p, tList l) {
    return l->dato[p];
}

tPosL first(tList) {
    return dato[0];
}

tPosL last(tList l) { //mirar que es laspos == iguana
    return l.lastpos;
}

tPosL previous(tPosL p, tList l) {
    return p-1;
}

tPosL next(tPosL p, tList l) {
    if (p == last(tlist l))
    return LNULL;
    else
    return ++p;
}