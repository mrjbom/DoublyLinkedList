#ifndef _SLLIST_H_
#define _SLLIST_H_

#include <stdint.h>

// Singly-linked list

typedef struct {
    void* next;
} sll_node_t;

typedef struct {
    sll_node_t* head;
    sll_node_t* tail;
    size_t count;
} singly_linked_list_t;

/*
 * Insert node to the end of the list (new tail)
 * (adds node to the list)
 */
extern void sll_insert_node_to_tail(singly_linked_list_t* list, sll_node_t* new_node);

/*
 * Insert node to the start of the list (new head)
 * (adds node to the list)
 */
extern void sll_insert_node_to_head(singly_linked_list_t* list, sll_node_t* new_node);

/*
 * Insert node after the node in the list
 * Insert new_node after node_in_list
 * (adds node to the list)
 */
extern void sll_insert_node_after_node(singly_linked_list_t* list, sll_node_t* node_in_list, sll_node_t* new_node);

/*
 * Insert node before the node in the list
 * Insert new_node before node_in_list
 * (adds node to the list)
 */
extern void sll_insert_node_before_node(singly_linked_list_t* list, sll_node_t* node_in_list, sll_node_t* new_node);

/*
 * Remove node from the list
 */
extern void sll_remove_node(singly_linked_list_t* list, sll_node_t* node);

/*
 * Get node by index
 * Returns NULL if the node failed to be get
 */
extern sll_node_t* sll_get_nth_node(singly_linked_list_t* list, size_t index);

#endif
