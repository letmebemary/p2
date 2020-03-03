/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
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

tList list;                         //declaramos la lista de tipo tList
int vote_null, total_votes;         //declaramos dos variables de tipo entero


void new(char param[NAME_LENGTH_LIMIT+1]) {             //función que crea un nuevo partido
    tItemL item1;                                       //declaramos una variable de tipo tItemL
    strcpy(item1.partyName, param);                     //copiamos el nombre del partido en item1.partyname
    item1.numVotes = 0;                                 //inicializamos los votos del partido a cero
    insertItem(item1, LNULL, &list);                    //introducimos el item(nombre y votos) en la lista
    printf("* New: party %s\n", item1.partyName);       //muestra un texto conforme se ha creado dicho partido
}

void stats (int param_int) {                            //función que muestra los votos y la participación (porcentaje)
    tItemL item1;
    tPosL pos;                                          //declaramos variable de tipo tPosL
    if (first(list) != LNULL) {                         //bucle cuando la primera posición de la lista no es nula
        item1 = getItem(first(list), list);             //item1 toma el valor del primer elemento de la lista
        pos = first(list);
        printf("Party %s numvotes %d (%.2f %%)\n", item1.partyName, item1.numVotes,((float)item1.numVotes/param_int)*100);

        while(next(pos,list) != LNULL){                 //mientras no sea el ultimo elemento de la lista
            item1 = getItem(next(pos,list),list);       //item toma el valor de ese elemento de la lista
            pos = next(pos,list);                       //pasa al siguiente elemento
            printf("Party %s numvotes %d (%.2f %%)\n", item1.partyName, item1.numVotes,((float)item1.numVotes/param_int)*100);
        }
    }else{
        printf("+ Error: none parties found");
    }
    printf("Null votes %d\n", vote_null);
    printf("Participation: %d votes from 10 voters (%.2f %%)\n", total_votes+vote_null,((float)(total_votes+vote_null)/param_int)*100);
}

void vote (char param[NAME_LENGTH_LIMIT+1]) {           //función que toma nota de los votos a cada partido, incluidos nulos
    tItemL item1;
    if (findItem(param,list) == LNULL) {                //en el caso de que ese partido no exista
        printf("+ Error: Vote not possible. Party %s not found. NULLVOTE\n", param);    //voto nulo
        vote_null += 1;
    }else {
        item1 = getItem(findItem(param, list), list);
        updateVotes(item1.numVotes + 1, findItem(param, list),&list);                   //suma un voto a determinado partido
        printf("* Vote: party %s numvotes %d\n", item1.partyName, item1.numVotes + 1);
        total_votes += 1;
    }
}

void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1]) {      //funcion que determina
                                                                                                              // la acción a llevar a cabo
    printf("********************\n");
    switch(command) {
        case 'N': {     //crear un partido
            printf("%s %c: party %s\n", command_number, command, param);
            new(param);
            break;
        }
        case 'S': {     //actualizar estadisticas
            int param_int;
            sscanf(param, "%d", &param_int);
            printf("%s %c: totalvoters %d\n", command_number, command, param_int);
            stats(param_int);
            break;
        }
        case 'V': {     //actualizar votos
            printf("%s %c: party %s\n", command_number, command, param);
            vote(param);
        }
        default: {
            break;
        }
    }
}

void readTasks(char *filename) {        //funcion que lee el archivo
    FILE *df;
    char command_number[CODE_LENGTH+1], command, param[NAME_LENGTH_LIMIT+1];

    df = fopen(filename, "r");          //abre filename y lo lee
    if (df != NULL) {
        while (!feof(df)) {             //mientras no llega al final del archivo
            char format[16];
            sprintf(format, "%%%is %%c %%%is", CODE_LENGTH, NAME_LENGTH_LIMIT);
            fscanf(df,format, command_number, &command, param);
            processCommand(command_number, command, param);     //llamada a la funcion encargada de repartir tareas
        }
        fclose(df);                     //cierre del fichero
    } else {
        printf("Cannot open file %s.\n", filename);
    }
}

int main(int nargs, char **args) {

    char *file_name;

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

/*
    tItemL item1, item2;
    strcpy(item1.partyName, "prueba");
    item1.numVotes = 5;
    insertItem(item1,LNULL,&list);
    item2 = getItem(first(list),list);
    printf("%s %d",item2.partyName, item2.numVotes);
*/

    createEmptyList(&list);         //creación de la lista vacía
    readTasks(file_name);           //llamada a la función encargada de leer el fichero

    return 0;
}
