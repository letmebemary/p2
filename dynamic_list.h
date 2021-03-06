/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardor
 * AUTHOR 2: Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: 26 / 03 / 20
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"

#define LNULL NULL

#include <stdbool.h>
#include <stdlib.h>


typedef struct tNode *tPosL; //contenido y siguiente nodo
struct tNode {
    tItemL data;
    tPosL next;
};

typedef tPosL tList; //la propia lista


void createEmptyList(tList *);
//{ Objetivo: Crea una lista vacia.
//Entradas: puntero.
//Salidas: lista vacia creada.
//Precondicion:
//Poscondicion: La lista queda inicializada y no contiene elementos.
//}

bool insertItem(tItemL, tPosL, tList *);
//{ Objetivo: Inserta un elemento en la lista antes de la posicion indicada.
//Si la posicion es LNULL,entonces se anhade al final. Devuelve un valor true
//si el elemento fue insertado; false en caso contrario.
//Entradas: lista, elemento a insertar y posicion donde se quiere insertar.
//Salidas: lista modificada y un valor: verdadero si se inserto el elemento, falso en caso contrario.
//Precondicion: La lista debe estar previamente inicializada. La posicion indicada es una posicion valida en la lista o bien nula (LNULL).
//Poscondicion: Las posiciones de los elementos de la lista posteriores al insertado pueden cambiar de valor.
//}

void updateVotes(tNumVotes, tPosL, tList *);
//{ Objetivo: Modifica el numero de votos del elemento situado en la posicion indicada.
//Entradas: lista, posicion y votos que actualizar.
//Salidas: Lista actualizada.
//Precondicion: La lista debe estar previamente inicializada. La posicion indicada es una posicion valida en la lista.
//Poscondicion: El orden de los elementos de la lista no se ve modificado.
//}

tPosL findItem(tPartyName, tList);
//{ Objetivo: busca en la lista un partido.
//Entradas: nombre del partido y la lista.
//Salidas: posición en la que se encuentra o nulo si no existe en la lista.
//Precondicion: que la lista esté inicializada.
//Poscondicion: 
//}

void deleteAtPosition(tPosL, tList *);
//{ Objetivo: Elimina de la lista el elemento que ocupa la posicion indicada.
//Entradas: lista y posicion a eliminar.
//Salidas: Lista con elemento ya eliminado.
//Precondicion: La lista debe estar previamente inicializada. La posicion indicada es una posicion valida en la lista.
//Poscondicion: Tanto la posicion del elemento eliminado como aquellas de los elementos de la lista a continuacion del mismo pueden cambiar de valor.
//}

bool isEmptyList(tList);
//{ Objetivo: Determina si la lista esta vacia.
//Entradas: lista.
//Salidas: verdadero si esta vacia, falso si no lo esta.
//Precondicion: La lista debe estar previamente inicializada.
//Poscondicion:
//}

tItemL getItem(tPosL, tList);
//{ Objetivo: Devuelve el contenido del elemento de la lista que ocupa la posicion indicada.
//Entradas: Lista y posicion de la que se quiere obtener el contenido.
//Salidas: elemento deseado.
//Precondicion: La lista debe estar previamente inicializada. La posicion indicada es una posicion valida en la lista.
//Poscondicion:
//}

tPosL first(tList);
//{ Objetivo: Devuelve la posicion del primer elemento de la lista.
//Entradas: lista
//Salidas: posicion correspondiente al primer elemento.
//Precondicion: La lista debe estar previamente inicializada.  La lista no esta vacia.
//Poscondicion:
//}

tPosL last(tList);
//{ Objetivo: Devuelve la posicion del ultimo elemento de la lista.
//Entradas: lista.
//Salidas: posicion correspondiente al ultimo elemento de la lista.
//Precondicion: La lista debe estar previamente inicializada. La lista no esta vacia.
//Poscondicion:
//}

tPosL previous(tPosL, tList);
//{ Objetivo: Devuelve la posicion en la lista del elemento anterior al de la posicion indicada (o
//LNULL si la posicion no tiene anterior).
//Entradas: lista y una posicion en la misma.
//Salidas: posicion anterior a la indicada.
//Precondicion: La lista debe estar previamente inicializada. La posicion indicada es una posicion valida en la lista.
//Poscondicion:
//}

tPosL next(tPosL, tList);
//{ Objetivo:  Devuelve la posicion en la lista del elemento siguiente al de la posicion indicada (o
//LNULL si la posicion no tiene siguiente).
//Entradas: lista y una posicion en la misma.
//Salidas: posicion siguiente a la indicada.
//Precondicion: La lista debe estar previamente inicializada. La posicion indicada es una posicion valida en la lista.
//Poscondicion:
//}


#endif



