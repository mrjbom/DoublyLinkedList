#include "tests/tests.h"
#include "stdio.h"

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
    return 0;
}
