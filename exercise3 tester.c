#include "exercise3.h"

int main() {
    queue *testQueue;
    initialize(testQueue);

    if (empty(testQueue)) {
        printf("Empty test passed.\n");
    }
    else {
        printf("Queue doesn't initialize as empty.");
    }
    
    int n0 = 5, n1 = 7;
    
    enqueue(testQueue, n0);
    enqueue(testQueue, n1);
    int r0 = dequeue(testQueue);
    int r1 = dequeue(testQueue);
    
    if (empty(testQueue)) {
        printf("Sameness test passed.\n");
    }
    else {
        printf("The queue isn't the same as before it was manipulated.");
    }

    if (r0 == n0 && r1 == n1) {
        printf("The dequeued values are correct.");
    }
    else {
        printf("The dequeued values are wrong.");
    }

    return 0;
}