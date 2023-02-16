#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * @brief Creates a new linked list.
 * @return The new empty list
 */
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

/**
 * @brief Prints the data stored in each node of the given linked list.
 * @param self Pointer to the linked list to print.
 */
void print_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

/**
 * @brief Inserts a new node at the start of the linked list.
 * @param self Pointer to the linked list to insert into.
 * @param data The int value to be inserted
 */
void insert_at_front(List* self, int data) {
	ListNodePtr new_node = malloc(sizeof * new_node);

	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;
}

/**
 * @brief Inserts a new node in numerical order.
 * @param self Pointer to the linked list to insert into.
 * @param data The int value to be inserted
 */
void insert_in_order(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->data = data;
	new_node->next = NULL;

	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}

/**
 * @brief deletes a value from the linked list.
 * @param self Pointer to the linked list to delete from.
 * @param data The int value to be deleted
 */
void delete_list(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->data == data) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

/**
 * @brief Deletes all values from the linked list (freeing all memory).
 * @param self Pointer to the linked list to destroy.
 */
void destroy_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}