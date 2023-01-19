#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"
#include "graph.h"

int main()
{
    char answer;
    pnode graph = NULL;
    while (scanf(" %c", &answer) != EOF){
        choice(answer, &graph);
    }
    delete_graph(&graph);
    return 0;
}