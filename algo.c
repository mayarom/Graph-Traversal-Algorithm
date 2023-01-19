#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "algo.h"
#include "nodes.h"
#include "edges.h"

#define MAX 1000000

void build_graph(pnode *head);
void insert_node(pnode *head);
void delete_node(pnode *head);
void delete_graph(pnode *head);
void shortsPath(pnode head);
int shortsPathFun(pnode head, int, int);
int min(int, int);
void TheShortestPath(pnode head);
void permutation(pnode, int *, int, int, int *, int *);
int calcArray(pnode, int[], int);
void swap(int *, int *);
int factorial(int);
int find_minimum(int[], int);

void choice(char answer, pnode *graph)
{
    switch (answer)
    {
    case 'A':
        build_graph(graph);
        break;

    case 'B':
        insert_node(graph);
        break;

    case 'D':
        delete_node(graph);
        break;

    case 'S':
        shortsPath(*graph);
        break;

    case 'T':
        TheShortestPath(*graph);
        break;

    default:
        if (answer == EOF)
        {
            return;
        }
    }
}

void build_graph(pnode *head)
{
    int count = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        insertLastN(i, head);
    }
    char c = 0;
    while (scanf(" %c", &c) != 0)
    {
        if (c == 'n')
        {
            int src = -1;
            scanf("%d", &src);
            int dest, weight;
            while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
            {
                if (isalpha(dest))
                {
                    break;
                }
                addEdge(src, dest, weight, head);
            }
        }
        else
        {
            break;
        }
    }
    choice(c, head);
}

void insert_node(pnode *head)
{
    int ind;
    scanf("%d", &ind);
    int dest, weight;
    pnode newNode = getNode(head, ind);
    if (newNode == NULL)
    {
        insertLastN(ind, head);
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest))
            {
                break;
            }
            addEdge(ind, dest, weight, head);
        }
    }
    else
    {
        pedge *pe = &(newNode->edges);
        freeEdges(pe);
        newNode->edges = NULL;
        while (scanf("%d", &dest) != 0 && scanf("%d", &weight) != 0)
        {
            if (isalpha(dest))
            {
                break;
            }
            addEdge(ind, dest, weight, head);
        }
    }
    choice(getchar(), head);
}

/**
 * Deletes a graph represented by a linked list of nodes.
 * @param head the head of the list
 */
void delete_graph(pnode *head)
{
    // Check if the head pointer is null or if the pointer it points to is null,
    // return immediately if true
    if (!head || !*head)
    {
        return;
    }
    // Initialize a temporary pointer "temp" to the head of the list
    pnode temp = *head;
    // Iterate through the list of nodes
    while (temp)
    {
        // Initialize a pointer "nodeEdges" to the edges of the current node
        pedge nodeEdges = temp->edges;
        // Iterate through the edges of the current node
        while (nodeEdges)
        {
            // Save a pointer to the current edge
            pedge edge = nodeEdges;
            // Move to the next edge in the list
            nodeEdges = nodeEdges->next;
            // Free the memory of the current edge
            free(edge);
        }
        // Save a pointer to the current node
        pnode node = temp;
        // Move to the next node in the list
        temp = temp->next;
        // Free the memory of the current node
        free(node);
    }
    // Set the head pointer to NULL
    *head = NULL;
}

/**
 * Deletes a node with the given index from a graph represented by a linked list of nodes.
 * @param head the head of the list
 */
void delete_node(pnode *head)
{
    // Read the index of the node to be deleted
    int ind;
    scanf("%d", &ind);

    // Initialize a temporary pointer "temp" to the head of the list
    pnode temp = *head;
    // Iterate through the list of nodes
    while (temp)
    {
        // Initialize a pointer "tempEdge" to the edges of the current node
        pedge *tempEdge = &(temp->edges);
        // remove the edges that are connected to the node with the given index from the current node
        deleteFromListE(ind, tempEdge, head);
        // Move to the next node in the list
        temp = temp->next;
    }
    // remove the node with the given index from the list
    deleteFromListN(ind, head);
    // calls another function choice
    choice(getchar(), head);
}

void shortsPath(pnode head)
{
    int src = 0, dst = 0;
    scanf("%d", &src);
    scanf("%d", &dst);
    printf("Dijsktra shortest path: %d \n", shortsPathFun(head, src, dst));
}
/**

    This function finds the shortest path between two given nodes in a graph represented by a linked list of nodes.
    @param head the head of the list of nodes
    @param source the starting node of the path
    @param target the ending node of the path
    @return the weight of the shortest path between the two given nodes, or -1 if there is no path between the two nodes
    */

int shortsPathFun(pnode head, int source, int target)
{
    if (!head)
    {
        return -1;
    }
    pnode curr = head;
    int N = 0;
    while (curr)
    {
        if (N < curr->id)
        {
            N = curr->id;
        }
        curr = curr->next;
    }
    N += 1;
    int mat[N][N];

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            mat[k][i] = MAX;
        }
    }
    curr = head;
    while (curr)
    {
        pedge ed = curr->edges;
        while (ed)
        {
            mat[curr->id][ed->endpoint->id] = ed->weight;
            ed = ed->next;
        }
        curr = curr->next;
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    mat[i][i] = 0;
                }
                else if (i == k || j == k)
                {
                    mat[i][j] = mat[i][j];
                }
                else
                {
                    int val = mat[i][k] + mat[k][j];
                    if (mat[i][k] == 0 || mat[k][j] == 0)
                    {
                        val = 0;
                    }
                    mat[i][j] = min(mat[i][j], val);
                }
            }
        }
    }
    if (mat[source][target] == MAX)
    {
        return -1;
    }
    return mat[source][target];
}
// function to find the minimum value
int min(int a, int b)
{
    return (a == 0) ? b : (b == 0) ? a
                      : (a < b)    ? a
                                   : b;
}
// TheShortestPath function is used to find the shortest path between all the cities
// using :
// the permutation function- to find all the permutations of the cities
// and the find_minimum function - to find the minimum value in the array
// and the calcArray function - to calculate the sum of the distances between the cities
// and the factorial function - to find the factorial of the number of cities
// and the swap function - to swap the values of the cities

void TheShortestPath(pnode head)
{
    int count;
    scanf("%d", &count);
    if (count == 0)
    {
        return;
    }
    int cities[count];
    for (size_t i = 0; i < count; i++)
    {
        scanf("%d", &cities[i]);
    }
    int fac = factorial(count);
    int perm[fac];
    int temp = 0;
    permutation(head, cities, 0, count - 1, perm, &temp);
    int ind = find_minimum(perm, fac);
    if (perm[ind] == MAX)
    {
        printf("TSP shortest path: %d \n", -1);
    }
    else
    {
        printf("TSP shortest path: %d \n", perm[ind]);
    }
}
// calcArray function is used to calculate the sum of the distances between the cities
int calcArray(pnode head, int cities[], int size)
{
    int distance = 0;
    for (size_t i = 0; i < size - 1; i++)
    {
        int path = shortsPathFun(head, cities[i], cities[i + 1]);
        if (path == -1)
        {
            return MAX;
        }
        distance += path;
    }
    return distance;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(pnode head, int *cities, int start, int end, int *perm, int *ind)
{
    if (start == end)
    {
        perm[(*ind)++] = calcArray(head, cities, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        swap((cities + i), (cities + start));
        permutation(head, cities, start + 1, end, perm, ind);
        swap((cities + i), (cities + start));
    }
}

int find_minimum(int arr[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[index])
        {
            index = i;
        }
    return index;
}

int factorial(int num)
{
    if (num == 0)
        return 1;
    if (num < 0)
        return 0;
    return factorial(num - 1) * num;
}