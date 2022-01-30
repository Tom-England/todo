struct Node{
	char data[255];
	struct Node* next;
};

// Returns a pointer to a Node struct that has next set to NULL
struct Node* createNode();

// Appends a Node to the end of the linked list with data set to content
// Returns a pointer to head
struct Node* pushNode(struct Node* head, const char* content);

// Removes the Node at the end of the linked list and frees its memory
void popNode(struct Node* head);

// Outputs all Nodes data and next pointer
void printList(struct Node* head);

// Searches for string searchTerm in the list
// Returns 1 for found
// Returns 0 for not found
int seach(struct Node* head, const char* searchTerm);

// Adds a node to the list at the specified index
// Returns 1 if successful
// Returns 0 if unsuccessful
int addNodeAtIndex(struct Node* head, const char* content, const int index);

// Returns the number of nodes in the list
int getLength(struct Node* head);

// Remove a node from the list at the specified index
// Returns 1 if successful
// Returns 0 if unseccessful
int deleteNodeAtIndex(struct Node* head, const int index);

// Returns the data of the node at the specified index
// Returns NULL if index is out of range
char* peek(struct Node* head, const int index);
