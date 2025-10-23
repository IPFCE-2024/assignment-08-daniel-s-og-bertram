/*
 * Exercise 2: Insertion Sort for Singly Linked List
 * Assignment 8 - IPFCE 2025
 * 
 * Implement insertion sort for a singly linked list of integers.
 * The list should be sorted in-place from smallest to largest.
 * No new nodes should be allocated - only pointers should be changed.
 */

#include "./include/exercise2.h"

/* 
 * Sort a singly linked list in-place using insertion sort
 * list: pointer to the first node of the list
 * 
 * The function should sort the list by rearranging pointers,
 * not by creating new nodes or swapping data values.
 */
node* isort(node* list) {
    node *sorted = NULL;
    node *cursor;
    node *crawler;

    while (list != NULL) {
        cursor = list;
        list = list->next;

        if (sorted == NULL) {
            sorted = cursor;
            sorted->next = NULL;
            continue;
        }
        
        crawler = sorted;

        while((crawler->next != NULL) | (crawler->next->data < cursor->data)) {
            crawler = crawler->next;
        }
        if (crawler->next = NULL) {
            crawler->next = cursor;
            crawler->next->next = NULL;
        }
        else {
            cursor->next = crawler->next;
            crawler->next = crawler;
        }
    }
    return sorted;
}

/* Helper function to create a node */
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Helper function to free the list */
void free_list(node* list) {
    node *current = list;
    node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

/* Helper function to print the list (for testing) */
void print_list(node* list) {
    node *current = list;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
