/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Jeronimo Pardo Rodriguez LOGIN 1: j.pardor
 * AUTHOR 2: Maria Martinez Sotelo LOGIN 2: maria.martinezs
 * GROUP: 4.3
 * DATE: 26 / 03 / 20
 */

#include <stdio.h>
#include <string.h>
#include "types.h"

#define CODE_LENGTH 2

#ifdef STATIC_LIST
#include "static_list.h"
#endif

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif

#ifdef TEST_LIST
#include "list/list.h"
#endif

void deleteList(tList *list) {                                //funcion que elimina la lista
    tPosL p = last(*list), q;                                 //desde la ultima posicion

    while (p != LNULL) {
        q = p;
        p = previous(p, *list);
        deleteAtPosition(q, &*list);
    }
}


void new(char param[NAME_LENGTH_LIMIT + 1], tList *list) {             //funcion que crea un nuevo partido
    tItemL item1;

    if (findItem(param, *list) == LNULL) {                    //comprobacion de que el partido no exista ya
        strcpy(item1.partyName, param);                     //introduccion de param en item1.partyname
        item1.numVotes = 0;
        if (!insertItem(item1, LNULL, &*list))              //introducion de item1 en la lista
            printf("+ Error: New not possible\n");
        else
            printf("* New: party %s\n", item1.partyName);

    } else
        printf("+ Error: New not possible\n");

}


void stats(int param_int, tList list, int vote_null,
           int total_votes) {             //funcion que muestra los votos de cada partido y la participacion
    tItemL item1;
    tPosL pos;

    if (!isEmptyList(list)) {                         //comprobacion de lista vacia
        item1 = getItem(first(list), list);             //item1 toma el valor del primer elemento de la lista
        pos = first(list);
        printf("Party %s numvotes %d (%.2f%%)\n", item1.partyName, item1.numVotes,
               (total_votes + vote_null) == 0 || item1.numVotes == 0 ? 0 : (float) item1.numVotes / (total_votes) *
                                                                           100);

        while (next(pos, list) != LNULL) {                 //muestra las stats de cada partido si hay segundo
            item1 = getItem(next(pos, list), list);
            pos = next(pos, list);
            printf("Party %s numvotes %d (%.2f%%)\n", item1.partyName, item1.numVotes,
                   (total_votes + vote_null) == 0 || item1.numVotes == 0 ? 0 : (float) item1.numVotes / (total_votes) *
                                                                               100);
        }
    } else {
        printf("+ Error: none parties found\n");         //mensaje de error en caso de lista vacia
    }
    printf("Null votes %d\n", vote_null);
    printf("Participation: %d votes from %d voters (%.2f%%)\n", (total_votes + vote_null), param_int,
           ((float) (total_votes + vote_null) / param_int) * 100);
}


void vote(char param[NAME_LENGTH_LIMIT + 1], tList *list, int *vote_null,
          int *total_votes) {           //funcion que toma nota de los votos
    tItemL item1;

    if (findItem(param, *list) == LNULL) {                //en el caso de que ese partido no exista: voto nulo
        printf("+ Error: Vote not possible. Party %s not found. NULLVOTE\n", param);
        *vote_null += 1;

    } else {
        item1 = getItem(findItem(param, *list), *list);
        updateVotes(item1.numVotes + 1, findItem(param, *list), &*list);                   //suma 1 voto a un partido
        printf("* Vote: party %s numvotes %d\n", item1.partyName, item1.numVotes + 1);
        *total_votes += 1;                              //aumento de votos totales
    }
}


void illegal(char param[NAME_LENGTH_LIMIT + 1], tList *list, int *vote_null,
             int *total_votes) {  //funcion que ilegaliza un partido
    tPosL pos;
    tItemL item;
    pos = findItem(param, *list);      //obtencion de la posicion en la lista del partido

    if (pos != LNULL) {
        item = getItem(pos, *list);
        *vote_null += item.numVotes;
        *total_votes = *total_votes - item.numVotes;
        deleteAtPosition(pos, &*list);                      //elimina el partido de la lista
        if (findItem(param, *list) == LNULL)                //no lo encuentra
            printf("* Illegalize: party %s\n", param);      //lo ilegaliza
        else
            printf("+ Error: Illegalize not possible\n");
    } else
        printf("+ Error: Illegalize not possible\n");
}


void processCommand(char command_number[CODE_LENGTH + 1], char command,
                    char param[NAME_LENGTH_LIMIT + 1], tList *list, int *vote_null,
                    int *total_votes) {      //funcion que determina la accion a llevar a cabo
    printf("********************\n");                 //separador de intrucciones
    switch (command) {
        case 'N': {     //crear un partido
            printf("%s %c: party %s\n", command_number, command, param);
            new(param, &*list);
            break;
        }
        case 'S': {     //actualizar estadisticas
            int param_int;
            sscanf(param, "%d", &param_int);
            printf("%s %c: totalvoters %d\n", command_number, command, param_int);
            stats(param_int, *list, *vote_null, *total_votes);
            break;
        }
        case 'V': {     //actualizar votos
            printf("%s %c: party %s\n", command_number, command, param);
            vote(param, &*list, &*vote_null, &*total_votes);
            break;
        }
        case 'I': {      //ilegalizar un partido
            printf("%s %c: party %s\n", command_number, command, param);
            illegal(param, &*list, &*vote_null, &*total_votes);
            break;
        }
        default: {
            break;
        }
    }
}


void readTasks(char *filename) {
    tList list;                     //declaracion lista de tipo tList
    createEmptyList(&list);         //creacion de la lista vacia
    FILE *df;
    int vote_null = 0, total_votes = 0;         //votos nulos y votos totales

    char command_number[CODE_LENGTH + 1], command, param[NAME_LENGTH_LIMIT + 1];

    df = fopen(filename, "r");                 //abre filename y lo lee
    if (df != NULL) {
        while (!feof(df)) {
            char format[16];
            sprintf(format, "%%%is %%c %%%is", CODE_LENGTH, NAME_LENGTH_LIMIT);
            fscanf(df, format, command_number, &command, param);
            processCommand(command_number, command, param, &list, &vote_null,
                           &total_votes);     //llamada a la funcion encargada de repartir tareas
        }
        fclose(df);                                  //cierre del fichero
    } else {
        printf("Cannot open file %s.\n", filename);  //error si no lee el archivo
    }
    deleteList(&list);
}


int main(int nargs, char **args) {

    char *file_name;

    if (nargs > 1) {                         //selecciona el archivo elegido en config.cmake si no esta ya inicializado
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }


    readTasks(file_name);           //llamada a la funcion encargada de leer el fichero

    return 0;
}
