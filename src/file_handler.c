#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "file_handler.h"

bool file_exists(const char* filepath){
    FILE *file;
    if (file = fopen(filepath, "r"))
    {
        fclose(file);
        return true;
    }

    return false;   
}

void create_file(const char* filepath){
    FILE* fp;
    fp = fopen(filepath, "w");
    fclose(fp);
}

int toggle_flag(FILE* fp){
    fpos_t position;
    char to_write = '1';
    fgetpos(fp, &position);
    char c = fgetc(fp);
    if (c == 255) { return EXIT_FAILURE;} // Handling for if user enters a line that has nothing on it
    if (c == '1') { to_write = '0'; }
    fsetpos(fp, &position);
    fputc(to_write, fp);
    fsetpos(fp, &position);
    return EXIT_SUCCESS;
}