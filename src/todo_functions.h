#include <stdio.h>

#define MAX_LINE_LENGTH         255
#define EXTRA_CHARS             4   // 1 for ticked status, 1 for the space after, 1 for the new line, 1 for the \0
#define MAX_MESSAGE_LENGTH      MAX_LINE_LENGTH - EXTRA_CHARS
#define BHGRN "\e[1;92m"

/**
 * @brief Outputs the contents of the todo.list file with formatting and a line counter
 * 
 * @param fp pointer to the opened todo.list file
 */
void list(FILE* fp);

/**
 * @brief Extracts a substring from a provided string
 * 
 * @param msg string to extract substring from
 * @param length length of the desired substring
 * @param offset starting position of the desired substring
 * @return char* substring of provided msg
 */
char* extract_msg(const char* msg, int length, int offset);

/**
 * @brief Adds a user-provided message to the end of the todo.list file along with the tick flag at the start
 * 
 * @param fp pointer to the opened todo.list file
 * @param msg string containing the message to add to the file
 */
void add_line(FILE* fp, const char* msg);

/**
 * @brief Attempts to toggle the status of the ticked flag for a specific line in the todo.list file
 * If the line is within range, function calls toggle_flag() in file_handler.h
 * If this was successful, the new status of the line is then outputted to the user.
 * 
 * @param fp pointer to the opened todo.list file
 * @param id line number of the message to toggle the status of
 */
void set_complete(FILE* fp, int id);

/**
 * @brief Removes the specified line from the todo.list file
 * 
 * @param fp pointer to the opened todo.list file
 * @param id line number of the message to remove from the file
*/
void remove_line(FILE* fp, const int id);