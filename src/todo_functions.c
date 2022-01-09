#include <stdio.h>
#include "todo_functions.h"

void list(FILE* fp){
    printf("Running list...\n");
    char buffer[MAX_LINE_LENGTH];
    char* status = fgets(buffer, MAX_LINE_LENGTH, fp);;
    while (status != NULL){
        printf("%s", buffer);
        status = fgets(buffer, MAX_LINE_LENGTH, fp);
    }
    printf("\n");
}