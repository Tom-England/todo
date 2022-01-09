#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"

int main(int argc, char* argv[]){
    printf("Starting todo...\n");

    const char* filename = "/home/tom/share/todo/bin/todo.list";

    FILE* fp;
    
    if (!file_exists(filename)){
        printf("Creating todo.list...\n");
        create_file(filename);
    }
    
    // Handle args
    printf("%s\n", argv[1]);
    if (argc < 2){
        printf("Please supply arguments, see -help for details\n");
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "list\n")){
        printf("Starting list function\n");
    }

    return EXIT_SUCCESS;
}