#include <stdio.h>

#define MAX_LINE_LENGTH         255
#define MAX_MESSAGE_LENGTH      MAX_LINE_LENGTH - 2

// Layout of a list entry
// done_flag message

void list(FILE* fp);

char* extract_msg(const char* msg, int length, int offset);

void add_line(FILE* fp, const char* msg);