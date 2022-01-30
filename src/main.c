#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_handler.h"
#include "todo_functions.h"
#include "config.h"

int main(int argc, char* argv[]){
    //printf("Starting todo...\n");

    const char* filename = handle_config();
    
    if (filename == NULL) {
        return EXIT_FAILURE;
    }

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
    
    //printf("Argv[1]: %s\n", argv[1]);
    if (strcmp(argv[1], "list\n") == 0 || strcmp(argv[1], "list") == 0){
        //printf("Starting list function\n");
        fp = fopen(filename, "r");
        list(fp);
    }
    else if (strcmp(argv[1], "add" ) == 0|| strcmp(argv[1], "add\n") == 0){
        if (argc != 3) {
            printf("No message supplied, exiting...\n");
            return EXIT_FAILURE;
        }
        fp = fopen(filename, "a");
        add_line(fp, argv[2]);
    }
    else if (strcmp(argv[1], "tick" ) == 0|| strcmp(argv[1], "tick\n") == 0){
        if (argc != 3) {
            printf("No Line ID supplied, exiting...\n");
            return EXIT_FAILURE;
        }
        fp = fopen(filename, "r+");
        int id = strtol(argv[2], NULL, 10);
        set_complete(fp, id );
    }
    else if (strcmp(argv[1], "remove" ) == 0|| strcmp(argv[1], "remove\n") == 0){
        if (argc != 3) {
            printf("No Line ID supplied, exiting...\n");
            return EXIT_FAILURE;
        }
        fp = fopen(filename, "r");
        int id = strtol(argv[2], NULL, 10);
        remove_line(fp, id, filename);
    }
    else if (strcmp(argv[1], "-h" ) == 0|| strcmp(argv[1], "-h\n") == 0 ||strcmp(argv[1], "--help" ) == 0|| strcmp(argv[1], "--help\n" ) == 0){
        printf("-h, --help  :   prints this menu\n\
add <message>   :   adds an item to the list\n\
list    :   Shows all list items\n\
tick <id>   :   Toggles the items ticked state\n");
        return EXIT_SUCCESS;
    }
    else {
        printf("Unknown Command, use -h or --help for more\n");
        return EXIT_FAILURE;
    }
    fclose(fp);
    
    return EXIT_SUCCESS;
}