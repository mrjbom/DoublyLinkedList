#include "tests/tests.h"

int main(void)
{
    test_insert_node_to_tail();
    test_insert_node_to_head();
    test_insert_node_after_node();
    test_insert_node_before_node();
    test_remove_node();
    return 0;
}
