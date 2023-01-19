#ifndef edgesh
#define edgesh

typedef struct node_ node, *pnode;

// Edge struct
typedef struct edge_
{
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


void addEdge(int , int , int , pnode *);
void insertLastE(pnode, int , pnode *);
void deleteFromListE(int, pedge *, pnode *);
void freeEdges(pedge *);
edge *newEdge(int , pnode);

#endif