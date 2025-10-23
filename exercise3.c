/*
 * Exercise 3: Queue Implementation using Singly-Linked Lists
 * Assignment 8 - IPFCE 2025
 * 
 * Implement a queue using singly-linked lists.
 * The queue should maintain FIFO (First-In, First-Out) order.
 */

#include "exercise3.h"

/* 
 * Initialize an empty queue
 * q: pointer to the queue structure
 * 
 * Post-condition: queue is empty with front and rear set to NULL
 */
void initialize(queue *q) {
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

/* 
 * Insert item x at the back of queue q
 * q: pointer to the queue structure
 * x: item to be inserted
 * 
 * Pre-condition: queue is not full
 * Post-condition: x is added to the rear of the queue
 */
void enqueue(queue *q, int x) {
    node *new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        // not enough available memory
        abort();
    }
    new->data = x;
    new->next = NULL;

    if (empty(q)) {
        q->front = new;
        q->rear = new;
    }
    else {
    q->rear->next = new;
    q->rear = new;
    }

    q->count += 1;
}

/* 
 * Return (and remove) the front item from queue q
 * q: pointer to the queue structure
 * 
 * Pre-condition: queue must not be empty
 * Post-condition: front item is removed and returned
 */
int dequeue(queue *q) {
    assert(!empty(q));

    // grab data
    int x = q->front->data;

    // update front and free node
    q->front = q->front->next;
    free(q->front);

    // update count
    q->count -= 1;

    // unique case where the dequeued node was the last one in the queue
    if (empty(q)) {
        q->rear = NULL;
    }

    return x;  
}

/* 
 * Check if the queue is empty
 * q: pointer to the queue structure
 * Returns: true if queue is empty, false otherwise
 */
bool empty(const queue *q) {
    return q->count == 0; 
}

/* 
 * Check if the queue is full
 * q: pointer to the queue structure
 * Returns: true if queue is full, false otherwise
 */
bool full(const queue *q) {
    // lists are never full
    return false;
}

/* Helper function to print the queue */
void print_queue(const queue *q) {
    printf("Queue (front to rear): ");
    node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <- ");
        }
        current = current->next;
    }
    printf("\n");
}

