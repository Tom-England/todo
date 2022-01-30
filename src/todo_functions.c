#include <stdio.h>
#include "todo_functions.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"

#include "linkedlist.h"

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
        if (buffer[0] == '1') {done = "[\e[1;92m✓\e[0;37m]";}
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
        free(buffer);
        new_msg[MAX_MESSAGE_LENGTH] = '\n';
        new_msg[MAX_MESSAGE_LENGTH + 1] = '\0';
        //printf("Adding: %s", new_msg);
        fprintf(fp, "0 %s", new_msg);
    } else {
        fprintf(fp, "0 %s\n", msg);
    }
}

void set_complete(FILE* fp, int id){
    if (id < 0) {
        printf("Invalid line entered\n");
    }
    char* status;
    char buffer[MAX_LINE_LENGTH];
    if (id > 0) {
        status = fgets(buffer, MAX_LINE_LENGTH, fp);
        int counter = 1;
        while (status != NULL && counter < id){
            //printf("buffer: %s\n", buffer);
            counter++;
            status = fgets(buffer, MAX_LINE_LENGTH, fp);
        }
        char empty[MAX_LINE_LENGTH];
    }
    
    if (toggle_flag(fp) == EXIT_SUCCESS){
        char* done = "[ ]";
        fgets(buffer, MAX_LINE_LENGTH, fp);
        if (buffer[0] == '1') {done = "[\e[1;92m✓\e[0;37m]";}
        else { done = "[ ]";}
        char* msg = extract_msg(buffer, MAX_MESSAGE_LENGTH + 2, 2);
        printf("\n%4d| %s %s\n", id, done, msg);
    }
}

void remove_line(FILE* fp, const int id, const char* filepath){
    // To Remove a line from a file with C,
    // The prevailing idea seems to be reading the whole
    // file into an array, except the line to be removed
    // Then writing the array back into the file, overwriting what
    // used to be there...
    // Sounds legit

    struct Node* head = NULL;
    head = pushNode(head, "");

    unsigned int line_count = 0;
    char buffer[MAX_LINE_LENGTH];
    char* status = "";
    while (status != NULL){
        //printf("Line Count: %d\n", line_count);
        status = fgets(buffer, MAX_LINE_LENGTH, fp);
        //printf("Buffer: %s\n", buffer);
        if (line_count != id){
            if (head == NULL){
                head = pushNode(head, buffer);
            } else {
                pushNode(head, buffer);
            }
        }
        line_count++;
    }
    printf("%p\n", head);
    printList(head);
    // Reopen the file for writing to clear it
    freopen(filepath, "w", fp);
    // Reopen it again for appending
    freopen(filepath, "a", fp);
    for (int i = 0; i < getLength(head) - 1; i++){
        char* buffer2 = peek(head, i);
        //printf("Writing %s\n", buffer2);
        fprintf(fp, "%s", buffer2);
    }
    //count_lines(fp);
}