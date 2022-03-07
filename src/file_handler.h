#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Verifies if the provided file exists
 * 
 * @param filepath location of the file to verify
 * @return true if file exists
 * @return false 
 */
bool file_exists(const char* filepath);

/**
 * @brief Creates the todo.list file
 * 
 * @param filepath
 */
void create_file(const char* filepath);

/**
 * @brief Toggles the character at the current file pointer location between a 1 or a 0 if it is one or the other already
 * 
 * @param fp pointer to the open todo.list file
 * @return int success of method
 */
int toggle_flag(FILE* fp);

/**
 * @brief Toggles the current list to read
 * 
 * @param id of the list to read
 */
void switch_list(FILE* fp, const char id);