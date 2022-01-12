#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>

#include "file_handler.h"

char* get_config_location(){
    char* home = (char*)calloc(PATH_MAX, sizeof(char));
    home = getenv("HOME");
    char* config = "/.config/todo/";
    strcat(home, config);
    //printf("Looking in %s...\n", home);
    return home;
}

char* get_list_location(FILE* fp){
    //printf("Getting list location\n");
    char* file_location = (char*) calloc (PATH_MAX, sizeof(char));
    fgets(file_location, PATH_MAX, fp);
    //printf("Found %s\n", file_location);
    fclose(fp);
    file_location[strcspn(file_location, "\n")] = 0;
    return file_location;
}

char* handle_config(){
    char* config_path = get_config_location();
    char* file = "todo.config";
    //printf("Got home: %s\n", config_path);
    strcat(config_path, file);
    //printf("Config path: %s\n", config_path);

    if (file_exists(config_path)){
        //printf("File Exists...\n");
        FILE* fp = fopen(config_path, "r");
        //printf("File open %d\n", fp);
        //free(config_path);
        return get_list_location(fp);
    }

    //free(config_path);
    printf("No config file found, exiting...\n");
    return NULL;
}