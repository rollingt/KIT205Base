#pragma once

/**
 * @struct listNode
 * @brief Linked list node for a list of ints
 * @var data The value stored in the node
 * @var next The next node in the list
 */
typedef struct listNode {
	int data;
	struct listNode *next;
}* ListNodePtr;

/**
 * @struct List
 * @brief Wrapper for a linked list
 * @var head The first node in the linked list
 */
typedef struct list {
	ListNodePtr head;
} List;

/**
 * @brief Creates a new linked list.
 * @return The new empty list
 */
List new_list();

/**
 * @brief Prints the data stored in each node of the given linked list.
 * @param self Pointer to the linked list to print.
 */
void print_list(List* self);

/**
 * @brief Inserts a new node at the start of the linked list.
 * @param self Pointer to the linked list to insert into.
 * @param data The int value to be inserted
 */
void insert_at_front(List* self, int data);

/**
 * @brief Inserts a new node in numerical order.
 * @param self Pointer to the linked list to insert into.
 * @param data The int value to be inserted
 */
void insert_in_order(List* self, int data);

/**
 * @brief deletes a value from the linked list.
 * @param self Pointer to the linked list to delete from.
 * @param data The int value to be deleted
 */
void delete_list(List* self, int data);

/**
 * @brief Deletes all values from the linked list (freeing all memory).
 * @param self Pointer to the linked list to destroy.
 */
void destroy_list(List* self);
