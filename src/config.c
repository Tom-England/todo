#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>

#include "config.h"
#include "file_handler.h"

char* get_config_location(){
    char* config_path = (char*)calloc(PATH_MAX, sizeof(char));
    char* home_path = getenv("HOME");
    char* config_tail = "/.config/todo/todo.config";
    strcat(config_path, home_path);
    strcat(config_path, config_tail);
    return config_path;
}

char* get_list_location(FILE* fp){
    //printf("Getting list location\n");
    char* file_location = (char*) calloc (PATH_MAX, sizeof(char));
    fgets(file_location, PATH_MAX, fp);
    rewind(fp);
    char id = get_list_id(fp);
    fclose(fp);
    file_location[strcspn(file_location, "\n")] = id;
    //printf("Found %s\n", file_location);
    return file_location;
}

char* handle_config(){
    char* config_path = get_config_location();

    if (file_exists(config_path)){
        //printf("File Exists...\n");
        FILE* fp = fopen(config_path, "r");
        //printf("File open %d\n", fp);
        //free(config_path);
        return get_list_location(fp);
    }
    free(config_path);
    printf("No config file found, exiting...\n");
    return NULL;
}

char get_list_id(FILE* fp){
    char id;
    char buffer[PATH_MAX];
    fgets(buffer, PATH_MAX, fp);

    id = fgetc(fp);
    return id;
}