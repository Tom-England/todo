#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Gets the absolute path to the users todo .config folder
 * 
 * @return char* absolute path to the config file
 */
char* get_config_location();

/**
 * @brief Verifies that the config file found by get_config_location() actually exists
 * then attempts to open it before passing onto get_list_location()
 * 
 * @return char* filepath for the desired list location
 */
char* handle_config();

/**
 * @brief Extracts the filepath from the provided config file
 * 
 * @param fp file pointer to the open config file
 * @return char* filepath for the desired list location
 */
char* get_list_location(FILE* fp);