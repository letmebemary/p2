/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardo
 * AUTHOR 2: Maria Martinez Sotelo LOGIN 2: maria.martinezs
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
//{ Objetivo: Crea una lista vacía.
//Entradas: puntero.
//Salidas: lista vacía creada.
//Precondición:
//Poscondición: La lista queda inicializada y no contiene elementos.
//}

bool insertItem(tItemL, tPosL, tList*);
//{ Objetivo: Inserta un elemento en la lista antes de la posición indicada.
//Si la posición es LNULL,entonces se añade al final. Devuelve un valor true
//si el elemento fue insertado; false en caso contrario.
//Entradas: lista, elemento a insertar y posición donde se quiere insertar.
//Salidas: lista modificada y un valor: verdadero si se insertó el elemento, falso en caso contrario.
//Precondición: La lista debe estar previamente inicializada. La posición indicada es una posición válida en la lista o bien nula (LNULL).
//Poscondición: Las posiciones de los elementos de la lista posteriores al insertado pueden cambiar de valor.
//}


void updateVotes(tNumVotes, tPosL, tList*);
//{ Objetivo: Modifica el número de votos del elemento situado en la posición indicada.
//Entradas: lista, posición y votos que actualizar.
//Salidas: Lista actualizada.
//Precondición: La lista debe estar previamente inicializada. La posición indicada es una posición válida en la lista.
//Poscondición: El orden de los elementos de la lista no se ve modificado.
//}

void deleteAtPosition(tPosL, tList*);
//{ Objetivo: Elimina de la lista el elemento que ocupa la posición indicada.
//Entradas: lista y posición a eliminar.
//Salidas: Lista con elemento ya eliminado.
//Precondición: La lista debe estar previamente inicializada. La posición indicada es una posición válida en la lista.
//Poscondición: Tanto la posición del elemento eliminado como aquellas de los elementos de la lista a continuación del mismo pueden cambiar de valor.
//}

void deleteList(tList* L);
tPosL findItem(tPartyName, tList);
//{ Objetivo: Devuelve la posición del primer elemento de la lista cuyo nombre de partido se
//corresponda con el indicado (o LNULL si no existe tal elemento).
//Entradas: Lista y nombre de partido.
//Salidas: Posición donde se corresponda el nombre de partido.
//Precondición: La lista debe estar previamente inicializada.
//Poscondición:
//}

bool isEmptyList(tList);
//{ Objetivo: Determina si la lista está vacía.
//Entradas: lista.
//Salidas: verdadero si está vacía, falso si no lo está.
//Precondición: La lista debe estar previamente inicializada.
//Poscondición:
//}

tItemL getItem(tPosL, tList);
//{ Objetivo: Devuelve el contenido del elemento de la lista que ocupa la posición indicada.
//Entradas: Lista y posición de la que se quiere obtener el contenido.
//Salidas: elemento deseado.
//Precondición: La lista debe estar previamente inicializada. La posición indicada es una posición válida en la lista.
//Poscondición:
//}

tPosL first(tList);
//{ Objetivo: Devuelve la posición del primer elemento de la lista.
//Entradas: lista
//Salidas: posición correspondiente al primer elemento.
//Precondición: La lista debe estar previamente inicializada.  La lista no está vacía.
//Poscondición:
//}

tPosL last(tList);
//{ Objetivo: Devuelve la posición del último elemento de la lista.
//Entradas: lista.
//Salidas: posición correspondiente al último elemento de la lista.
//Precondición: La lista debe estar previamente inicializada. La lista no está vacía.
//Poscondición:
//}

tPosL previous(tPosL, tList);
//{ Objetivo:Devuelve la posición en la lista del elemento anterior al de la posición indicada (o
//LNULL si la posición no tiene anterior).
//Entradas: lista y una posición en la misma.
//Salidas: posición anterior a la indicada.
//Precondición: La lista debe estar previamente inicializada. La posición indicada es una posición válida en la lista.
//Poscondición:
//}

tPosL next(tPosL, tList);
//{ Objetivo:  Devuelve la posición en la lista del elemento siguiente al de la posición indicada (o
//LNULL si la posición no tiene siguiente).
//Entradas: lista y una posición en la misma.
//Salidas: posición siguiente a la indicada.
//Precondición: La lista debe estar previamente inicializada. La posición indicada es una posición válida en la lista.
//Poscondición:
//}



#endif



