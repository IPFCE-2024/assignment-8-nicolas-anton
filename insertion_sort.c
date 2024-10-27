#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "insertion_sort.h"

// Function to sort the list:
node *isort(node *list)
{
    // Creating an empty node pointer:
    node *sorted = NULL;

    // Looping through the list
    while (list != NULL)
    {
        // Saving the current node:
        node *current = list;
        // Moving to the next element in the list:
        list = list->next;

        // Ready to insert at the right spot:
        if (sorted == NULL || current->data <= sorted->data)
        {
            // Current.next points to the first element of the sorted list:
            current->next = sorted;
            // Making current the new head of the sorted list:
            sorted = current;
        }
        // If it is not ready to insert:
        else
        {
            // Make a new pointer:
            node *temp = sorted;

            // Looping until we reach the right spot to insert the node:
            while (temp->next != NULL && temp->next->data < current->data)
            {
                // Moving the temp pointer to the next node:
                temp = temp->next;
            }
            // Setting current.next to point to the node that temp.next points to:
            current->next = temp->next;
            // Setting temp.next pointer to point to the current node:
            temp->next = current;
        }
    }
    // Return the first element of the sorted list:
    return sorted;
}



