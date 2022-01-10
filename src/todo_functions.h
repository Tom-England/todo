#include <stdio.h>

#define MAX_LINE_LENGTH         255
#define EXTRA_CHARS             4   // 1 for ticked status, 1 for the space after, 1 for the new line, 1 for the \0
#define MAX_MESSAGE_LENGTH      MAX_LINE_LENGTH - EXTRA_CHARS
#define BHGRN "\e[1;92m"

// Layout of a list entry
// done_flag message

void list(FILE* fp);

char* extract_msg(const char* msg, int length, int offset);

void add_line(FILE* fp, const char* msg);