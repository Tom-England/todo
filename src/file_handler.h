#include <stdio.h>
#include <stdbool.h>

bool file_exists(const char* filepath);

// Creates the .list file
void create_file();

int toggle_flag(FILE* fp);