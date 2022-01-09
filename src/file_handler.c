#include <stdio.h>
#include <stdbool.h>

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