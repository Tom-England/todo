#include <stdio.h>
#include "todo_functions.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* extract_msg(const char* msg, int length, int offset){
    char* new_string = (char*)calloc(length, sizeof(char));
    for (int c = 0; c < length; c++){
        new_string[c] = msg[offset + c];
    }
    return new_string;
}

void list(FILE* fp){
    //printf("Running list...\n");
    printf("\n");
    char* done = "[ ]";
    char buffer[MAX_LINE_LENGTH];
    char* status = fgets(buffer, MAX_LINE_LENGTH, fp);
    int counter = 0;
    while (status != NULL){
        if (buffer[0] == '1') {done = "[x]";}
        else { done = "[ ]";}
        char* msg = extract_msg(buffer, MAX_MESSAGE_LENGTH + 2, 2);
        printf("%4d| %s %s", counter, done, msg);
        free(msg);
        counter++;
        status = fgets(buffer, MAX_LINE_LENGTH, fp);
    }
    printf("\n");
}

void add_line(FILE* fp, const char* msg){
    if (strlen(msg) > MAX_MESSAGE_LENGTH - 2){
        //printf("Msg too long...\nCutting to %d\n", MAX_MESSAGE_LENGTH);
        char* buffer;
        char new_msg[MAX_MESSAGE_LENGTH + 2];
        buffer = extract_msg(msg, MAX_MESSAGE_LENGTH, 0);
        strcpy(new_msg, buffer);
        new_msg[MAX_MESSAGE_LENGTH] = '\n';
        new_msg[MAX_MESSAGE_LENGTH + 1] = '\0';
        //printf("Adding: %s", new_msg);
        fprintf(fp, "0 %s", new_msg);
    } else {
        fprintf(fp, "0 %s\n", msg);
    }
    
}