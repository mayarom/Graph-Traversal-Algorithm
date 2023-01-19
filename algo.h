#ifndef GRAPH_
#define GRAPH_

#include "nodes.h"
#include "edges.h"


void build_graph(pnode *head);
void insert_node(pnode *head);
void delete_node(pnode *head);
void delete_graph(pnode *head);
void shortsPath(pnode head);
int shortsPathFun(pnode head, int, int);
int min(int, int);
void TheShortestPath(pnode head);
void permutation(pnode, int *, int, int, int*, int*);
int calcArray(pnode, int[], int);
void swap(int *, int *);
int factorial(int);
int find_minimum(int[], int);

void choice(char, pnode *head);


#endif
