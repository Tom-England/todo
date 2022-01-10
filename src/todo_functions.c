#include <stdio.h>
#include "todo_functions.h"
#include <stdbool.h>
#include <stdlib.h>

char* extract_msg(const char* msg, int length, int offset){
    char* new_string = (char*)malloc(length * sizeof(char));
    for (int c = 0; c < length; c++){
        new_string[c] = msg[offset + c];
    }
    return new_string;
}

void list(FILE* fp){
    //printf("Running list...\n");
    char* done = "[ ]";
    char buffer[MAX_LINE_LENGTH];
    char* status = fgets(buffer, MAX_LINE_LENGTH, fp);
    int counter = 0;
    while (status != NULL){
        if (buffer[0] == '1') {done = "[x]";}
        else { done = "[ ]";}
        char* msg = extract_msg(buffer, MAX_MESSAGE_LENGTH, 2);
        printf("%d| %s %s", counter, done, msg);
        free(msg);
        counter++;
        status = fgets(buffer, MAX_LINE_LENGTH, fp);
    }
    printf("\n");
}

void add_line(FILE* fp, const char* msg){
    return;
}