struct Node{
	char data[255];
	struct Node* next;
};

/**
 * @brief Creates a new empty node
 * 
 * @return Pointer to a Node struct that has next set to NULL
*/
struct Node* createNode();

/**
 * @brief Appends a Node to the end of the linked list with data set to content
 * @param head First node in the list
 * @param content String containing the content to add to the node
 * @return a pointer to the head of the list
*/
struct Node* pushNode(struct Node* head, const char* content);

/**
 * @brief Removes the Node at the end of the linked list and frees its memory
 * @param head First node in the list
*/
void popNode(struct Node* head);

/**
 * @brief Outputs all Nodes data and next pointer
 * @param head First node in the list
*/
void printList(struct Node* head);

/**
 * @brief Searches for string searchTerm in the list
 * @param head First node in the list
 * @param searchTerm string to search for in the list
 * @return 1 if string is found, 0 if not
*/
int search(struct Node* head, const char* searchTerm);

/**
 * @brief Adds a node to the list at the specified index
 * @param head First node in the list
 * @param content String containing the content to add to the node
 * @param index Position in the list to insert the new node
 * @return 1 if inserted successfully, 0 otherwise
*/
int addNodeAtIndex(struct Node* head, const char* content, const int index);

/**
 * @brief gets the number of nodes in the list
 * @param head First node in the list
 * @return Number of nodes in the list
*/
int getLength(struct Node* head);

/**
 * @brief Removes the node at the specified index
 * @param head First node in the list
 * @param index index of the node to delete
 * @return 1 if deleted successfully, 0 otherwise
*/
int deleteNodeAtIndex(struct Node* head, const int index);

/**
 * @brief Peeks at the content of the node at the specified index
 * @param head First node in the list
 * @param index index in the list to peek
 * @return Data from the specified node
*/
char* peek(struct Node* head, const int index);
