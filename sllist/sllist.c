#include "sllist.h"
#include <stdbool.h>

void sll_insert_node_to_tail(singly_linked_list_t* list, sll_node_t* new_node)
{
    if (list == NULL || new_node == NULL) {
        return;
    }
    if (list->count == 0) {
        list->count++;
        list->head = new_node;
        list->tail = new_node;
        new_node->next = NULL;
    }
    else {
        list->count++;
        sll_node_t* old_tail = list->tail;
        old_tail->next = new_node;
        new_node->next = NULL;
        list->tail = new_node;
        list->tail->next = NULL;
    }
}

void sll_insert_node_to_head(singly_linked_list_t* list, sll_node_t* new_node)
{
    if (list == NULL || new_node == NULL) {
        return;
    }
    if (list->count == 0) {
        sll_insert_node_to_tail(list, new_node);
    }
    else {
        list->count++;
        sll_node_t* old_head = list->head;
        new_node->next = old_head;
        list->head = new_node;
    }
}

void sll_insert_node_after_node(singly_linked_list_t* list, sll_node_t* node_in_list, sll_node_t* new_node)
{
    if (list == NULL || node_in_list == NULL || new_node == NULL || list->count == 0) {
        return;
    }
    if (list->count == 1) {
        list->count++;
        list->head->next = new_node;
        list->tail = new_node;
        list->tail->next = NULL;
    }
    else /* count > 1 */ {
        list->count++;
        if (node_in_list == list->tail) {
            list->tail->next = new_node;
            list->tail = new_node;
            list->tail->next = NULL;
        }
        else {
            sll_node_t* node_in_list_next = node_in_list->next;
            node_in_list->next = new_node;
            new_node->next = node_in_list_next;
        }
    }
}

void sll_insert_node_before_node(singly_linked_list_t* list, sll_node_t* node_in_list, sll_node_t* new_node)
{
    if (list == NULL || node_in_list == NULL || new_node == NULL || list->count == 0) {
        return;
    }
    if (list->count == 1) {
        list->count++;
        new_node->next = node_in_list;
        list->head = new_node;
    }
    else /* count > 1 */ {
        list->count++;
        if (node_in_list == list->head) {
            new_node->next = list->head;
            list->head = new_node;
        }
        else {
            bool is_found = false;
            sll_node_t* current_node = list->head->next;
            sll_node_t* before_current_node = list->head;
            for (size_t i = 1; i < list->count - 1; ++i) {
                // Find node before
                if (current_node == node_in_list) {
                    is_found = true;
                    break;
                }
                else {
                    before_current_node = current_node;
                    current_node = current_node->next;
                }
            }
            if (is_found) {
                before_current_node->next = new_node;
                new_node->next = current_node;
            }
        }
    }
}

void sll_remove_node(singly_linked_list_t* list, sll_node_t* node)
{
    if (list == NULL || node == NULL || list->count == 0) {
        return;
    }
    if (list->count == 1) {
        list->count--;
        list->head = NULL;
        list->tail = NULL;
    }
    else /* count > 1 */ {
        list->count--;
        if (node == list->head) {
            list->head = list->head->next;
        }
        else {
            bool is_found = false;
            sll_node_t* current_node = list->head->next;
            sll_node_t* before_current_node = list->head;
            for (size_t i = 1; i < list->count + 1; ++i) {
                // Find node before
                if (current_node == node) {
                    is_found = true;
                    break;
                }
                else {
                    before_current_node = current_node;
                    current_node = current_node->next;
                }
            }
            if (is_found) {
                if (node == list->tail) {
                    before_current_node->next = NULL;
                    list->tail = before_current_node;
                }
                else {
                    before_current_node->next = current_node->next;
                }
            }
        }
    }
}

sll_node_t* sll_get_nth_node(singly_linked_list_t* list, size_t index)
{
    if (list == NULL) {
        return NULL;
    }
    if (index >= list->count) {
        return NULL;
    }
    if (index == 0) {
        return list->head;
    }
    if (index == (list->count - 1)) {
        return list->tail;
    }
    sll_node_t* current_node = list->head->next;
    for (size_t i = 1; i < list->count - 1; ++i) {
        if (i == index) {
            return current_node;
        }
        else {
            current_node = current_node->next;
        }
    }
    // Unreachable
    return NULL;
}
