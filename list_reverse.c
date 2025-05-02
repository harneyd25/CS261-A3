/*
 * This is the file in which you'll write a function to reverse a linked list.
 * Make sure to add your name and @oregonstate.edu email address below:
 *
 * Name: David Harney
 * Email: harneyd@oregonstate.edu
 */

#include <stdio.h>

#include "list_reverse.h"

/*
 * In this function, you will be passed a pointer to the first node of a singly-linked list.
 * You should reverse the linked list and return the new "first" pointer.  The reversal
 * must be done in place, and you may not allocate any new memory in this
 * function.
 *
 * Params:
 *   first - a pointer to the first node of a singly-linked list to be reversed
 *
 * Return:
 *   Should return the new first of the reversed list.  If first is NULL, this
 *   function should return NULL.
 */
struct node* list_reverse(struct node* first) {
	// in case of linked list length 0
	if (first == NULL) {
		return NULL;
	}

	// in case of linked list length 1
	if (first->next == NULL) {
		return first;
	}

	// in case of linked list length > 1
	
	struct node* prev_node = NULL;	// so reversed list ends in NULL
	struct node* mid_node = first;
	struct node* next_node = first->next;
	
	do {
		// reversing pointer	
		mid_node->next = prev_node;

		// incrementing pointers up through list
		prev_node = mid_node;
		mid_node = next_node;
		next_node = next_node->next; 

	} while (next_node != NULL);
	
	// reversing last pointer
	mid_node->next = prev_node;

	// returning new head 
	return mid_node;
}
