# Doubly Linked List implementation in C
A simple implementation of a doubly-linked list in C.  
It has tests and is generally reliable (but not foolproof).  
No standard library functions are used, so all the code is **freestanding**

## Functions  
The available functions are described in the [dllist.h](dllist/dllist.h).

## How to use
Include **dllist.h** and don't forget to compile **dllist.c**  
Example:
```
#include "dllist/dllist.h"

typedef struct {
    dll_node_t dll_node; // It's worth specifying the node first, it makes life easier
    int some_data; // Or data ptr
} data_t;

doubly_linked_list_t list;
memset(&list, 0, sizeof(doubly_linked_list_t));
data_t* data_array_ptr = (data_t*)malloc(sizeof(data_t) * 2);
if (data_array_ptr == NULL) {
    return -1;
}
data_array_ptr[0].some_data = 1;
data_array_ptr[1].some_data = 2;

dll_insert_node_to_tail(&list, (dll_node_t*)&data_array_ptr[0]); // Or &data_array_ptr[0].dll_node
dll_insert_node_to_tail(&list, (dll_node_t*)&data_array_ptr[1]); // Or &data_array_ptr[1].dll_node

// Get first and second node data
data_t* first_node_data = (data_t*)list.head; // Or (data_t*)dll_get_nth_node(&list, 0);
data_t* second_node_data = (data_t*)list.tail; // Or (data_t*)dll_get_nth_node(&list, 1);
printf("First node data %d\n", first_node_data->some_data);
printf("Second node data %d\n", second_node_data->some_data);

free(data_array_ptr);
```
