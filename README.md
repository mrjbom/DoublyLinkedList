# Singly Linked List implementation in C
A simple implementation of a singly-linked list in C.  
The implementation is based on the main implementation of a doubly-linked list from the master branch
It has tests and is generally reliable (but not foolproof).  
No standard library functions are used, so all the code is **freestanding**

## Functions  
The available functions are described in the [sllist.h](sllist/sllist.h).

## How to use
Include **sllist.h** and don't forget to compile **sllist.c**  
Example:
```
#include "sllist/dllist.h"

typedef struct {
    sll_node_t sll_node; // It's worth specifying the node first, it makes life easier
    int some_data; // Or data ptr
} data_t;

singly_linked_list_t list;
memset(&list, 0, sizeof(singly_linked_list_t));
data_t* data_array_ptr = (data_t*)malloc(sizeof(data_t) * 2);
if (data_array_ptr == NULL) {
    return -1;
}
data_array_ptr[0].some_data = 1;
data_array_ptr[1].some_data = 2;

sll_insert_node_to_tail(&list, (sll_node_t*)&data_array_ptr[0]); // Or &data_array_ptr[0].sll_node
sll_insert_node_to_tail(&list, (sll_node_t*)&data_array_ptr[1]); // Or &data_array_ptr[1].sll_node

// Get first and second node data
data_t* first_node_data = (data_t*)list.head; // Or (data_t*)sll_get_nth_node(&list, 0);
data_t* second_node_data = (data_t*)list.tail; // Or (data_t*)sll_get_nth_node(&list, 1);
printf("First node data %d\n", first_node_data->some_data);
printf("Second node data %d\n", second_node_data->some_data);

free(data_array_ptr);
```
