#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"
#include "todo_functions.h"

int main(int argc, char* argv[]){
    printf("Starting todo...\n");

    const char* filename = "/home/tom/share/todo/bin/todo.list";

    FILE* fp;
    
    if (!file_exists(filename)){
        printf("Creating todo.list...\n");
        create_file(filename);
    }
    
    // Handle args

    if (argc < 2){
        printf("Please supply arguments, see -help for details\n");
        return EXIT_FAILURE;
    }
    //printf("%s\n", argv[1]);
    if (strcmp(argv[1], "list\n")){
        //printf("Starting list function\n");
        fp = fopen(filename, "r");
        list(fp);
        fclose(fp);
    }

    return EXIT_SUCCESS;
}