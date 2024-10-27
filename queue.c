#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void initialize(queue *q)
{
    // Set the front and rear node to NULL:
    q->rear = NULL;
    q->front = NULL;
    // Set the size to 0
    q->size = 0;
}

bool empty(const queue *q)
{
    // Returning true if the size is 0 and the front and rear node are empty:
    return q->size == 0 && q->rear == NULL && q->front == NULL;
}

bool full(const queue *q)
{
    return false;
    // hahahahha
}

void enqueue(queue *q, int x)
{
    // Create a new node:
    node *n = (node *)malloc(sizeof(node));

    // Set the data in the node to x:
    n->data = x;

    // Make it a single node:
    n->next = NULL;

    // Checks if the list is empty:
    if (empty(q))
    {
        // Setting both the front and the back to the node n:
        q->rear = n;
        q->front = n;
    }
    // If the list is not empty:
    else
    {
        // Setting the node to next element after the rearest element:
        q->rear->next = n;
        // Setting the new node to the new rear:
        q->rear = n;
    }
    // Increment the size of the queue:
    q->size++;
}

int dequeue(queue *q)
{
    // Checks if the queue is empty:
    assert(!empty(q));

    // Making a temporary pointer to point to the front node:
    node *temp = q->front;
    // Saving the data at the front node in an integer variable:
    int dequeued = temp->data;

    // Moving the front element to the second front position:
    q->front = temp->next;

    // Checks if the queue only had one node:
    if (q->front == NULL)
    {
        // Set the rear to NULL also:
        q->rear = NULL;
    }

    // Freeing the temporary note:
    free(temp);
    q->size--;

    // Returning the data of the dequeued node:
    return dequeued;
}

// Opgave 4:
// The function takes a double pointer because we have to modify the head of the function as we are inserting a node at the beginning of the list:
void push(int element, node **head)
{
    // Allocate memory for new node:
    node *n = (node *)malloc(sizeof(node));

    // Setting the data in the node to element:
    n->data = element;

    // Inserts the node at the beginning of the list with its next pointer to the current head:
    n->next = *head;

    // Updating the head to point to the new node (the new node is now the start of the list):
    *head = n;
}

// Double pointer allowing to change the head of the list:
int pop(node **head)
{
    // Temporary node pointer pointing to the head of the list:
    node *temp = *head;
    // Node pointer to keep track of the node just before the node that temp points to:
    node *before = NULL;

    // Lopping until reaching the last node:
    while (temp->next != NULL)
    {
        // Before pointer pointing to the node just before the node that temp points to:
        before = temp;
        // Moving through the list:
        temp = temp->next;
    }

    // Storing the data of the last node before popping it:
    int element = temp->data;

    // Checking if there is only one node in the list:
    // If there is more than one node:
    if (before != NULL)
    {
        // If there is more than one node then the next node after the before node is set to NULL. Meaning that it is being removed (the last node is being removed):
        before->next = NULL;
    }
    // If there was only one node in the list:
    else
    {
        // Setting the head to NULL meaning the queue is now empty:
        *head = NULL;
    }

    // Freeing the removed node from memory:
    free(temp);
    // Returning the data of the popped node:
    return element;
}

void enqueueStack(queue *q, int x)
{
    // Enqueueing the stack using push function:
    push(x, &q->front);
    // Increment the queue size:
    q->size++;
}

int dequeueStack(queue *q)
{
    // Dequeueing the stack using pop function saving the returned element in an integer variable:
    int element = pop(&q->front);
    // Decrementing the queue size:
    q->size--;
    // Returning the element:
    return element;
}
