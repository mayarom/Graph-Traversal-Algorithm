#include <stdio.h>
#include <stdlib.h>
#include "edges.h"
#include "nodes.h"
#include "algo.h"

node *newNode(int);
void insertLastN(int, pnode *);
void deleteFromListN(int, node **);
pnode getNode(pnode *, int);
void deleteGraph(pnode *);

node *newNode(int id)
{
    pnode p = (pnode)malloc(sizeof(node));
    if (p == NULL)
    {
        return NULL;
    }
    p->id = id;
    p->next = NULL;
    p->edges = NULL;
    return p;
}

pnode getNode(pnode *head, int id)
{
    pnode h = *head;
    while (h)
    {
        if (h->id == id)
        {
            return h;
        }
        h = h->next;
    }
    return NULL;
}

/**
 * Inserts a new node with a specified ID at the end of the linked list of nodes.
 * @param id The ID of the new node
 * @param head The head pointer of the linked list of nodes
 */
void insertLastN(int id, pnode *head)
{
    // Initialize the pointer to traverse the list
    pnode *curr = head;

    // Iterate through the list until the end
    while (*curr)
    {
        curr = &((*curr)->next);
    }

    // Allocate memory for the new node and insert it at the end of the list
    *curr = newNode(id);
}

/**
 * Removes a node with a specified ID from the linked list of nodes.
 * @param id The ID of the node to remove
 * @param head The head pointer of the linked list of nodes
 */
void deleteFromListN(int id, pnode *head)
{
    pnode curr = *head;
    pnode prev = NULL;

    // Iterate through the list of nodes to find the node with the specified ID
    for ( curr = *head; curr; prev = curr, curr = curr->next)
    {
        if (curr->id == id)
        {
            if (prev)
            {
                prev->next = curr->next;
            }
            else
            {
                *head = curr->next;
            }
            // Remove the node's edges
            freeEdges(&(curr->edges));
            // Free the memory used by the node
            free(curr);
            return;
        }
    }
    printf("Error: Node with ID %d not found in the list.\n", id);
}
