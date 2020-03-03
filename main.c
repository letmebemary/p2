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

tList list;
int vote_null, total_votes;


void new(char param[NAME_LENGTH_LIMIT+1]) {
    tItemL item1;
    strcpy(item1.partyName, param);
    item1.numVotes = 0;
    insertItem(item1, LNULL, &list);
    printf("* New: party %s\n", item1.partyName);
}

void stats (int param_int) {
    tItemL item1;
    tPosL pos;
    if (first(list) != LNULL) {
        item1 = getItem(first(list), list);
        pos = first(list);
        printf("Party %s numvotes %d (%.2f)\n", item1.partyName, item1.numVotes,((float)item1.numVotes/param_int)*100);

        while(next(pos,list) != LNULL){
            item1 = getItem(next(pos,list),list);
            pos = next(pos,list);
            printf("Party %s numvotes %d (%.2f)\n", item1.partyName, item1.numVotes,((float)item1.numVotes/param_int)*100);
        }
    }else{
        printf("+ Error: none parties found");
    }
    printf("Null votes %d\n", vote_null);
    printf("Participation: %d votes from 10 voters (%.2f)\n", total_votes+vote_null,((float)(total_votes+vote_null)/param_int)*100);
}

void vote (char param[NAME_LENGTH_LIMIT+1]) {
    tItemL item1;
    if (findItem(param,list) == LNULL) {
        printf("+ Error: Vote not possible. Party %s not found. NULLVOTE\n", param);
        vote_null += 1;
    }else {
        item1 = getItem(findItem(param, list), list);
        updateVotes(item1.numVotes + 1, findItem(param, list),&list);
        printf("* Vote: party %s numvotes %d\n", item1.partyName, item1.numVotes + 1);
        total_votes += 1;
    }
}

void processCommand(char command_number[CODE_LENGTH+1], char command, char param[NAME_LENGTH_LIMIT+1]) {
    printf("********************\n");
    switch(command) {
        case 'N': {
            printf("%s %c: party %s\n", command_number, command, param);
            new(param);
            break;
        }
        case 'S': {
            int param_int;
            sscanf(param, "%d", &param_int);
            printf("%s %c: totalvoters %d\n", command_number, command, param_int);
            stats(param_int);
            break;
        }
        case 'V': {
            printf("%s %c: party %s\n", command_number, command, param);
            vote(param);
        }
        default: {
            break;
        }
    }
}

void readTasks(char *filename) {
    FILE *df;
    char command_number[CODE_LENGTH+1], command, param[NAME_LENGTH_LIMIT+1];

    df = fopen(filename, "r");
    if (df != NULL) {
        while (!feof(df)) {
            char format[16];
            sprintf(format, "%%%is %%c %%%is", CODE_LENGTH, NAME_LENGTH_LIMIT);
            fscanf(df,format, command_number, &command, param);
            processCommand(command_number, command, param);
        }
        fclose(df);
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


    createEmptyList(&list);
    readTasks(file_name);

    return 0;
}


