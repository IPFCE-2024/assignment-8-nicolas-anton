#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Making a queue pointer
queue *q;

// Test function to test if we have initialized an empty queue after calling initialize(q);
void initialize_test()
{
    // Allocating memory for the queue:
    q = (queue *)malloc(sizeof(queue));
    // Calling initialize function:
    initialize(q);
    // Checking if the queue is empty:
    assert(empty(q));
}

// Function to test for b.2:
void test_number2()
{
    // Declaring variables:
    int x = 5;
    int y;

    // Making a test pointer to a queue pointing to the queue that q points to:
    queue *test = q;

    // Calling the functions enqueue and dequeue:
    enqueue(q, x);
    y = dequeue(q);

    // Checking if the queue is the same as it was before calling the two functions:
    assert(test == q);

    // Checking if x equals y:
    assert(x == y);
}

// Function to test for b.3:
void test_number3()
{
    // Declaring variables:
    int x0 = 5;
    int x1 = 4;
    int y1;
    int y0;

    // Making a test pointer to a queue pointing to the queue that q points to:
    queue *test = q;

    // Calling the functions enqueue and dequeue with different variables:
    enqueue(q, x0);
    enqueue(q, x1);
    y0 = dequeue(q);
    y1 = dequeue(q);

    // Checking if the queue is the same is it was before calling the functions:
    assert(test == q);
    // Checking if x0 equals y0 and x1 equals y1:
    assert(x0 == y0 && x1 == y1);
}

// Main function:
int main()
{
    // Calling the test functions:
    initialize_test();
    test_number2();
    test_number3();
    // Printing succes message if every law holds:
    printf("Every law holds\n");

    // Freeing the q pointer:
    free(q);

    // Returning from the body and main:
    return 0;
}


