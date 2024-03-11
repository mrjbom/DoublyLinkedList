#include "tests/tests.h"
#include "stdio.h"
#include "sllist/sllist.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    sll_node_t sll_node; // It's worth specifying the node first, it makes life easier
    int some_data; // Or data ptr
} data_t;

int main(void)
{
    printf("test_insert_node_to_tail\n");
    test_insert_node_to_tail();
    printf("test_insert_node_to_head\n");
    test_insert_node_to_head();
    printf("test_insert_node_after_node\n");
    test_insert_node_after_node();
    printf("test_insert_node_before_node\n");
    test_insert_node_before_node();
    printf("test_remove_node\n");
    test_remove_node();
    printf("test_get_nth_node\n");
    test_get_nth_node();
    printf("test_random\n");
    test_random();

    // Example
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    data_t* data_array_ptr = (data_t*)malloc(sizeof(data_t) * 2);
    if (data_array_ptr == NULL) {
        return -1;
    }
    data_array_ptr[0].some_data = 1;
    data_array_ptr[1].some_data = 2;

    sll_insert_node_to_tail(&list, (sll_node_t*)&data_array_ptr[0]); // Or &data_array_ptr[0].dll_node
    sll_insert_node_to_tail(&list, (sll_node_t*)&data_array_ptr[1]); // Or &data_array_ptr[1].dll_node

    // Get first and second node data
    data_t* first_node_data = (data_t*)list.head; // Or (data_t*)sll_get_nth_node(&list, 0);
    data_t* second_node_data = (data_t*)list.tail; // Or (data_t*)sll_get_nth_node(&list, 1);
    printf("First node data %d\n", first_node_data->some_data);
    printf("Second node data %d\n", second_node_data->some_data);

    free(data_array_ptr);
    return 0;
}
