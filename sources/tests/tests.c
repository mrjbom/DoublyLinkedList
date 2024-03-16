#include "tests.h"
#include "../sllist/sllist.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

void test_insert_node_to_tail()
{
    // TEST 1: Insert to empty list
    // TEST 2: Insert to not empty list

    // TEST 1
    // Prepare
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    sll_node_t* node = malloc(sizeof(sll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_to_tail(&list, node);
    
    // Check
    // node
    assert(list.count == 1);
    assert(list.head == node);
    assert(list.tail == node);
    assert(node->next == NULL);

    // TEST 2
    // Prepare
    sll_node_t* node1 = malloc(sizeof(sll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_to_tail(&list, node1);

    // Check
    // node <-> node1
    assert(list.count == 2);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node1);
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
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    sll_node_t* node = malloc(sizeof(sll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_to_head(&list, node);

    // Check
    // node
    assert(list.count == 1);
    assert(list.head == node);
    assert(list.tail == node);
    assert(node->next == NULL);

    // TEST 2
    // Prepare
    sll_node_t* node1 = malloc(sizeof(sll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_to_head(&list, node1);

    // Check
    // node1 <-> node
    assert(list.count == 2);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node);
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
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    sll_node_t* node = malloc(sizeof(sll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(sll_node_t));
    sll_insert_node_to_tail(&list, node);
    sll_node_t* node1 = malloc(sizeof(sll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_after_node(&list, list.head, node1);

    // Check
    // node <-> node1
    assert(list.count == 2);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node1);
    assert(node1->next == NULL);

    // TEST 2
    // Prepare
    sll_node_t* node2 = malloc(sizeof(sll_node_t));
    assert(node2 != NULL);
    memset(node2, 0, sizeof(sll_node_t));
    
    // Use
    sll_insert_node_after_node(&list, node, node2);

    // Check
    // node <-> node2 <-> node1
    assert(list.count == 3);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node2);
    assert(node2->next == node1);
    assert(node1->next == NULL);

    // TEST 3
    // Prepare
    sll_node_t* node3 = malloc(sizeof(sll_node_t));
    assert(node3 != NULL);
    memset(node3, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_after_node(&list, node2, node3);

    // Check
    // node <-> node2 <-> node3 <-> node1
    assert(list.count == 4);
    assert(list.head == node);
    assert(list.tail == node1);
    assert(node->next == node2);
    assert(node2->next == node3);
    assert(node3->next == node1);
    assert(node1->next == NULL);

    // TEST 4
    // Prepare
    sll_node_t* node4 = malloc(sizeof(sll_node_t));
    assert(node4 != NULL);
    memset(node4, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_after_node(&list, node1, node4);
    
    // Check
    // node <-> node2 <-> node3 <-> node1 <-> node4
    assert(list.count == 5);
    assert(list.head == node);
    assert(list.tail == node4);
    assert(node->next == node2);
    assert(node2->next == node3);
    assert(node3->next == node1);
    assert(node1->next == node4);
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
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    sll_node_t* node = malloc(sizeof(sll_node_t));
    assert(node != NULL);
    memset(node, 0, sizeof(sll_node_t));
    sll_insert_node_to_tail(&list, node);
    sll_node_t* node1 = malloc(sizeof(sll_node_t));
    assert(node1 != NULL);
    memset(node1, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_before_node(&list, node, node1);
    
    // Check
    // node1 <-> node
    assert(list.count == 2);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node);
    assert(node->next == NULL);

    // TEST 2
    // Prepare
    sll_node_t* node2 = malloc(sizeof(sll_node_t));
    assert(node2 != NULL);
    memset(node2, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_before_node(&list, node, node2);

    // Check
    // node1 <-> node2 <-> node
    assert(list.count == 3);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node2);
    assert(node2->next == node);
    assert(node->next == NULL);

    // TEST 3
    // Prepare
    sll_node_t* node3 = malloc(sizeof(sll_node_t));
    assert(node3 != NULL);
    memset(node3, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_before_node(&list, node2, node3);
    
    // Check
    // node1 <-> node3 <-> node2 <-> node
    assert(list.count == 4);
    assert(list.head == node1);
    assert(list.tail == node);
    assert(node1->next == node3);
    assert(node3->next == node2);
    assert(node2->next == node);
    assert(node->next == NULL);

    // TEST 4
    // Prepare
    sll_node_t* node4 = malloc(sizeof(sll_node_t));
    assert(node4 != NULL);
    memset(node4, 0, sizeof(sll_node_t));

    // Use
    sll_insert_node_before_node(&list, node1, node4);
    
    // Check
    // node4 <-> node1 <-> node3 <-> node2 <-> node
    assert(list.count == 5);
    assert(list.head == node4);
    assert(list.tail == node);
    assert(node4->next == node1);
    assert(node1->next == node3);
    assert(node3->next == node2);
    assert(node2->next == node);
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
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    sll_node_t* nodes = malloc(sizeof(sll_node_t) * 4);
    assert(nodes != NULL);
    // nodes[0] <-> nodes[1] <-> nodes[2] <-> nodes[3]
    sll_insert_node_to_tail(&list, &nodes[0]);
    sll_insert_node_to_tail(&list, &nodes[1]);
    sll_insert_node_to_tail(&list, &nodes[2]);
    sll_insert_node_to_tail(&list, &nodes[3]);

    // Use
    sll_remove_node(&list, &nodes[2]);
    
    // Check
    // nodes[0] <-> nodes[1] <-> nodes[3]
    assert(list.count == 3);
    assert(list.head == &nodes[0]);
    assert(list.tail == &nodes[3]);
    assert(nodes[0].next == &nodes[1]);
    assert(nodes[1].next == &nodes[3]);
    assert(nodes[3].next == NULL);

    // TEST 2:
    // Use
    sll_remove_node(&list, &nodes[3]);

    // Check
    // nodes[0] <-> nodes[1]
    assert(list.count == 2);
    assert(list.head == &nodes[0]);
    assert(list.tail == &nodes[1]);
    assert(nodes[0].next == &nodes[1]);
    assert(nodes[1].next == NULL);

    // TEST 3:
    // Use
    sll_remove_node(&list, &nodes[0]);

    // Check
    // node[1]
    assert(list.count == 1);
    assert(list.head == &nodes[1]);
    assert(list.tail == &nodes[1]);
    assert(nodes[1].next == NULL);

    // TEST 4:
    // Use
    sll_remove_node(&list, &nodes[1]);
    
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
    singly_linked_list_t list;
    memset(&list, 0, sizeof(singly_linked_list_t));
    
    // Use and check
    // empty
    sll_node_t* received_node = sll_get_nth_node(&list, 0);
    assert(received_node == NULL);
    received_node = sll_get_nth_node(&list, 1);
    assert(received_node == NULL);
    received_node = sll_get_nth_node(&list, 2);
    assert(received_node == NULL);

    // TEST 2:
    // Prepare
    sll_node_t* nodes = malloc(sizeof(sll_node_t) * 3);
    assert(nodes != NULL);
    sll_insert_node_to_tail(&list, &nodes[0]);

    // Use and check
    // nodes[0]
    received_node = sll_get_nth_node(&list, 0);
    assert(received_node == &nodes[0]);
    received_node = sll_get_nth_node(&list, 1);
    assert(received_node == NULL);

    // TEST 3:
    // Prepare
    sll_insert_node_before_node(&list, &nodes[0], &nodes[1]);

    // Use and check
    // nodes[1]<->nodes[0]
    received_node = sll_get_nth_node(&list, 0);
    assert(received_node == &nodes[1]);
    received_node = sll_get_nth_node(&list, 1);
    assert(received_node == &nodes[0]);
    received_node = sll_get_nth_node(&list, 2);
    assert(received_node == NULL);

    // TEST 4:
    // Prepare
    sll_insert_node_before_node(&list, &nodes[1], &nodes[2]);

    // Use and check
    // nodes[2]<->nodes[1]<->nodes[0]
    received_node = sll_get_nth_node(&list, 0);
    assert(received_node == &nodes[2]);
    received_node = sll_get_nth_node(&list, 1);
    assert(received_node == &nodes[1]);
    received_node = sll_get_nth_node(&list, 2);
    assert(received_node == &nodes[0]);
    received_node = sll_get_nth_node(&list, 3);
    assert(received_node == NULL);

    // TEST 5:
    // Prepare
    sll_remove_node(&list, &nodes[1]);

    // Use and check
    // nodes[2]<->nodes[0]
    received_node = sll_get_nth_node(&list, 0);
    assert(received_node == &nodes[2]);
    received_node = sll_get_nth_node(&list, 1);
    assert(received_node == &nodes[0]);
    received_node = sll_get_nth_node(&list, 2);
    assert(received_node == NULL);

    free(nodes);
}

// TEST RANDOM STAFF
void do_action(singly_linked_list_t* list);
void add_block(singly_linked_list_t* list);
void remove_block(singly_linked_list_t* list);
void insert_after_or_before_blocks(singly_linked_list_t* list);

uint8_t max_blocks_number = 32;

void test_random()
{
    srand((unsigned int)time(0));
    for (uint32_t j = 0; j < 128; ++j) {
        singly_linked_list_t list;
        memset(&list, 0, sizeof(list));

        for (uint32_t i = 0; i < 512; ++i) {
            //printf("Number of blocks: %u\n", list.count);
            do_action(&list);
        }

        for (size_t i = 0; i < list.count; ++i) {
            size_t random_index = rand() % list.count;
            sll_node_t* node = sll_get_nth_node(&list, random_index);
            sll_remove_node(&list, node);
            free(node);
        }
    }
}

void do_action(singly_linked_list_t* list)
{
    if (list->count == 0) {
        add_block(list);
        return;
    }

    // We can add or insert new blocks?
    if (list->count < max_blocks_number) {
        // We can
        // Add or Insert
        // 0 - add
        // 1 - insert
        // 2-3 - remove
        uint8_t a_or_i_or_r = rand() % 4;
        if (a_or_i_or_r == 0) {
            add_block(list);
            return;
        }
        if (a_or_i_or_r == 1) {
            insert_after_or_before_blocks(list);
            return;
        }
        if (a_or_i_or_r > 1) {
            remove_block(list);
        }
    }
    else {
        // We can't
        // Remove blocks
        remove_block(list);
        return;
    }
}

void add_block(singly_linked_list_t* list)
{
    //printf("ADD\n");
    if (list->count == 0) {
        sll_node_t* node = malloc(sizeof(sll_node_t));
        assert(node);
        sll_insert_node_to_tail(list, node);
        return;
    }
    uint8_t block_add_max = 3;
    // [1; block_add_max]
    uint8_t block_add_number = 1 + (rand() % block_add_max);
    for (uint8_t i = 0; i < block_add_number; ++i) {
        sll_node_t* node = malloc(sizeof(sll_node_t));
        assert(node);
        // 0 - to tail
        // 1 - to head
        uint8_t t_or_h = rand() % 2;
        if (t_or_h == 0) {
            sll_insert_node_to_tail(list, node);
        }
        else {
            sll_insert_node_to_head(list, node);
        }
    }
}

void remove_block(singly_linked_list_t* list)
{
    if (list->count == 0) {
        return;
    }
    //printf("REMOVE\n");

    uint8_t block_free_max = 2;
    if (block_free_max > list->count) {
        block_free_max = (uint8_t)list->count;
    }
    // [1; block_free_max]
    uint8_t block_add_number = 1 + (rand() % block_free_max);
    for (uint8_t i = 0; i < block_add_number; ++i) {
        uint32_t index = rand() % list->count;
        sll_node_t* node = sll_get_nth_node(list, index);
        assert(node);
        sll_remove_node(list, node);
        free(node);
    }
}

void insert_after_or_before_blocks(singly_linked_list_t* list)
{
    //printf("INSERT\n");
    sll_node_t* new_node = malloc(sizeof(sll_node_t));
    assert(new_node);
    uint32_t in_list_index = rand() % list->count;
    sll_node_t* in_list_node = sll_get_nth_node(list, in_list_index);
    // 0 - after
    // 1 - before
    uint8_t a_or_b = rand() % 2;
    if (a_or_b == 0) {
        sll_insert_node_after_node(list, in_list_node, new_node);
    }
    else {
        sll_insert_node_before_node(list, in_list_node, new_node);
    }
}
