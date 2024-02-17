#include "tests.h"
#include "../dllist/dllist.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

void test_insert_node_to_tail()
{
    // TEST 1: Insert to empty list
    // TEST 2: Insert to not empty list

    // TEST 1
    // Prepare
    doubly_linked_list_t list;
    memset(&list, 0, sizeof(doubly_linked_list_t));
    dll_node_t* node = malloc(sizeof(dll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_to_tail(&list, node);
    
    // Check
    // node
    assert(list.count == 1);
    assert(list.head == node);
    assert(list.tail == node);
    assert(node->next == NULL);
    assert(node->prev == NULL);

    // TEST 2
    // Prepare
    dll_node_t* node1 = malloc(sizeof(dll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_to_tail(&list, node1);

    // Check
    // node <-> node1
    assert(list.count == 2);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node1);
    assert(node1->prev == node);
    assert(node->prev == NULL);
    assert(node1->next == NULL);

    free(node);
    free(node1);
}

void test_insert_node_to_head()
{
    // TEST 1: Insert to empty list
    // TEST 2: Insert to not empty list

    // TEST 1
    // Prepare
    doubly_linked_list_t list;
    memset(&list, 0, sizeof(doubly_linked_list_t));
    dll_node_t* node = malloc(sizeof(dll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_to_head(&list, node);

    // Check
    // node
    assert(list.count == 1);
    assert(list.head == node);
    assert(list.tail == node);
    assert(node->next == NULL);
    assert(node->prev == NULL);

    // TEST 2
    // Prepare
    dll_node_t* node1 = malloc(sizeof(dll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_to_head(&list, node1);

    // Check
    // node1 <-> node
    assert(list.count == 2);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node);
    assert(node->prev == node1);
    assert(node1->prev == NULL);
    assert(node->next == NULL);

    free(node);
    free(node1);
}

void test_insert_node_after_node()
{
    // TEST 1: Insert into list with 1 node
    // TEST 2: Insert into a list with 2 node, after head (into middle)
    // TEST 3: Insert into a list with 3 node, after middle
    // TEST 4: Insert into a list with 4 node, after tail

    // TEST 1
    // Prepare
    doubly_linked_list_t list;
    memset(&list, 0, sizeof(doubly_linked_list_t));
    dll_node_t* node = malloc(sizeof(dll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(dll_node_t));
    dll_insert_node_to_tail(&list, node);
    dll_node_t* node1 = malloc(sizeof(dll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_after_node(&list, list.head, node1);

    // Check
    // node <-> node1
    assert(list.count == 2);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node1);
    assert(node1->prev == node);
    assert(node->prev == NULL);
    assert(node1->next == NULL);

    // TEST 2
    // Prepare
    dll_node_t* node2 = malloc(sizeof(dll_node_t));
    assert(node2 != NULL);
    memset(node2, 0, sizeof(dll_node_t));
    
    // Use
    dll_insert_node_after_node(&list, node, node2);

    // Check
    // node <-> node2 <-> node1
    assert(list.count == 3);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node2);
    assert(node2->prev == node);
    assert(node2->next == node1);
    assert(node1->prev == node2);
    assert(node->prev == NULL);
    assert(node1->next == NULL);

    // TEST 3
    // Prepare
    dll_node_t* node3 = malloc(sizeof(dll_node_t));
    assert(node3 != NULL);
    memset(node3, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_after_node(&list, node2, node3);

    // Check
    // node <-> node2 <-> node3 <-> node1
    assert(list.count == 4);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node2);
    assert(node2->prev == node);
    assert(node2->next == node3);
    assert(node3->prev == node2);
    assert(node3->next == node1);
    assert(node1->prev == node3);
    assert(node->prev == NULL);
    assert(node1->next == NULL);

    // TEST 4
    // Prepare
    dll_node_t* node4 = malloc(sizeof(dll_node_t));
    assert(node4 != NULL);
    memset(node4, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_after_node(&list, node1, node4);
    
    // Check
    // node <-> node2 <-> node3 <-> node1 <-> node4
    assert(list.count == 5);
    assert(list.head == node);
    assert(list.tail == node4);
    assert(node->next == node2);
    assert(node2->prev == node);
    assert(node2->next == node3);
    assert(node3->prev == node2);
    assert(node3->next == node1);
    assert(node1->prev == node3);
    assert(node1->next == node4);
    assert(node4->prev == node1);
    assert(node->prev == NULL);
    assert(node4->next == NULL);

    free(node);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
}

void test_insert_node_before_node()
{
    // TEST 1: Insert into list with 1 node
    // TEST 2: Insert into a list with 2 node, before tail (into middle)
    // TEST 3: Insert into a list with 3 node, before middle
    // TEST 4: Insert into a list with 4 node, before head

    // TEST 1
    // Prepare
    doubly_linked_list_t list;
    memset(&list, 0, sizeof(doubly_linked_list_t));
    dll_node_t* node = malloc(sizeof(dll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(dll_node_t));
    dll_insert_node_to_tail(&list, node);
    dll_node_t* node1 = malloc(sizeof(dll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_before_node(&list, node, node1);
    
    // Check
    // node1 <-> node
    assert(list.count == 2);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node);
    assert(node->prev == node1);
    assert(node1->prev == NULL);
    assert(node->next == NULL);

    // TEST 2
    // Prepare
    dll_node_t* node2 = malloc(sizeof(dll_node_t));
    assert(node2 != NULL);
    memset(node2, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_before_node(&list, node, node2);

    // Check
    // node1 <-> node2 <-> node
    assert(list.count == 3);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node2);
    assert(node2->prev == node1);
    assert(node2->next == node);
    assert(node->prev == node2);
    assert(node1->prev == NULL);
    assert(node->next == NULL);

    // TEST 3
    // Prepare
    dll_node_t* node3 = malloc(sizeof(dll_node_t));
    assert(node3 != NULL);
    memset(node3, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_before_node(&list, node2, node3);
    
    // Check
    // node1 <-> node3 <-> node2 <-> node
    assert(list.count == 4);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node3);
    assert(node3->prev == node1);
    assert(node3->next == node2);
    assert(node2->prev == node3);
    assert(node2->next == node);
    assert(node->prev == node2);
    assert(node1->prev == NULL);
    assert(node->next == NULL);

    // TEST 4
    // Prepare
    dll_node_t* node4 = malloc(sizeof(dll_node_t));
    assert(node4 != NULL);
    memset(node4, 0, sizeof(dll_node_t));

    // Use
    dll_insert_node_before_node(&list, node1, node4);
    
    // Check
    // node4 <-> node1 <-> node3 <-> node2 <-> node
    assert(list.count == 5);
    assert(list.head == node4);
    assert(list.tail == node);
    assert(node4->next == node1);
    assert(node1->prev == node4);
    assert(node1->next == node3);
    assert(node3->prev == node1);
    assert(node3->next == node2);
    assert(node2->prev == node3);
    assert(node2->next == node);
    assert(node->prev == node2);
    assert(node4->prev == NULL);
    assert(node->next == NULL);

    free(node);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
}

void test_remove_node()
{
    // TEST 1: Remove node from list with 4 node, remove middle
    // TEST 2: Remove node from list with 3 node, remove tail
    // TEST 3: Remove node from list with 2 node, remove head
    // TEST 4: Remove node from list with 1 node, remove head

    // TEST 1:
    // Prepare
    doubly_linked_list_t list;
    memset(&list, 0, sizeof(doubly_linked_list_t));
    dll_node_t* nodes = malloc(sizeof(dll_node_t) * 4);
    assert(nodes != NULL);
    // nodes[0] <-> nodes[1] <-> nodes[2] <-> nodes[3]
    dll_insert_node_to_tail(&list, &nodes[0]);
    dll_insert_node_to_tail(&list, &nodes[1]);
    dll_insert_node_to_tail(&list, &nodes[2]);
    dll_insert_node_to_tail(&list, &nodes[3]);

    // Use
    dll_remove_node(&list, &nodes[2]);
    
    // Check
    // nodes[0] <-> nodes[1] <-> nodes[3]
    assert(list.count == 3);
    assert(list.head == &nodes[0]);
    assert(list.tail == &nodes[3]);
    assert(nodes[0].next == &nodes[1]);
    assert(nodes[1].prev == &nodes[0]);
    assert(nodes[1].next == &nodes[3]);
    assert(nodes[3].prev == &nodes[1]);
    assert(nodes[0].prev == NULL);
    assert(nodes[3].next == NULL);

    // TEST 2:
    // Use
    dll_remove_node(&list, &nodes[3]);

    // Check
    // nodes[0] <-> nodes[1]
    assert(list.count == 2);
    assert(list.head == &nodes[0]);
    assert(list.tail == &nodes[1]);
    assert(nodes[0].next == &nodes[1]);
    assert(nodes[1].prev == &nodes[0]);
    assert(nodes[0].prev == NULL);
    assert(nodes[1].next == NULL);

    // TEST 3:
    // Use
    dll_remove_node(&list, &nodes[0]);

    // Check
    // node[1]
    assert(list.count == 1);
    assert(list.head == &nodes[1]);
    assert(list.tail == &nodes[1]);
    assert(nodes[1].prev == NULL);
    assert(nodes[1].next == NULL);

    // TEST 4:
    // Use
    dll_remove_node(&list, &nodes[1]);
    
    // Check
    // empty list
    assert(list.count == 0);
    assert(list.head == NULL);
    assert(list.tail == NULL);

    free(nodes);
}

void test_get_nth_node()
{
    // TEST 1: Get node from empty list
    // TEST 2: Get node from list with 1 node
    // TEST 3: Get nodes from list with 2 nodes (insert node before)
    // TEST 4: Get nodes from list with 3 nodes (insert node before last)
    // TEST 5: Get nodes from list with 2 nodes (remove middle node)

    // TEST 1:
    // Prepare
    doubly_linked_list_t list;
    memset(&list, 0, sizeof(doubly_linked_list_t));
    
    // Use and check
    // empty
    dll_node_t* received_node = dll_get_nth_node(&list, 0);
    assert(received_node == NULL);
    received_node = dll_get_nth_node(&list, 1);
    assert(received_node == NULL);
    received_node = dll_get_nth_node(&list, 2);
    assert(received_node == NULL);

    // TEST 2:
    // Prepare
    dll_node_t* nodes = malloc(sizeof(dll_node_t) * 3);
    assert(nodes != NULL);
    dll_insert_node_to_tail(&list, &nodes[0]);

    // Use and check
    // nodes[0]
    received_node = dll_get_nth_node(&list, 0);
    assert(received_node == &nodes[0]);
    received_node = dll_get_nth_node(&list, 1);
    assert(received_node == NULL);

    // TEST 3:
    // Prepare
    dll_insert_node_before_node(&list, &nodes[0], &nodes[1]);

    // Use and check
    // nodes[1]<->nodes[0]
    received_node = dll_get_nth_node(&list, 0);
    assert(received_node == &nodes[1]);
    received_node = dll_get_nth_node(&list, 1);
    assert(received_node == &nodes[0]);
    received_node = dll_get_nth_node(&list, 2);
    assert(received_node == NULL);

    // TEST 4:
    // Prepare
    dll_insert_node_before_node(&list, &nodes[1], &nodes[2]);

    // Use and check
    // nodes[2]<->nodes[1]<->nodes[0]
    received_node = dll_get_nth_node(&list, 0);
    assert(received_node == &nodes[2]);
    received_node = dll_get_nth_node(&list, 1);
    assert(received_node == &nodes[1]);
    received_node = dll_get_nth_node(&list, 2);
    assert(received_node == &nodes[0]);
    received_node = dll_get_nth_node(&list, 3);
    assert(received_node == NULL);

    // TEST 5:
    // Prepare
    dll_remove_node(&list, &nodes[1]);

    // Use and check
    // nodes[2]<->nodes[0]
    received_node = dll_get_nth_node(&list, 0);
    assert(received_node == &nodes[2]);
    received_node = dll_get_nth_node(&list, 1);
    assert(received_node == &nodes[0]);
    received_node = dll_get_nth_node(&list, 2);
    assert(received_node == NULL);

    free(nodes);
}
