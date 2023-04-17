/******************************************************
 * Project: Graph Data Structure
 * Author: [Your Name]
 * Version: 1.0
 * Date: [Date Created]
 * Description: This project implements a graph data structure
 *              using linked lists. The graph allows users to
 *              add and delete nodes and edges, and to find
 *              the shortest path between two nodes using
 *              Dijkstra's algorithm or the shortest path
 *              that visits all nodes using brute force.
 ******************************************************/

/******************************************************
 * Installation:
 * - Ensure that a C compiler is installed on your machine
 * - Clone the repository from [repository URL]
 * - Navigate to the project directory and run "make" to compile
 * - Run the executable by typing "./graph" in the terminal
 ******************************************************/

/******************************************************
 * Usage:
 * - When running the program, the user will be prompted to
 *   enter a command:
 *   - A: add a new graph
 *   - B: insert a node into an existing graph
 *   - D: delete a node from an existing graph
 *   - S: find the shortest path between two nodes in a graph
 *   - T: find the shortest path that visits all nodes in a graph
 *   - Q: quit the program
 * - To add a new graph, the user will be prompted to enter the
 *   number of nodes in the graph, followed by the edges between
 *   each node and its neighbors.
 * - To insert a node into an existing graph, the user will be
 *   prompted to enter the index of the node to be added, followed
 *   by the edges between the new node and its neighbors.
 * - To delete a node from an existing graph, the user will be
 *   prompted to enter the index of the node to be deleted.
 * - To find the shortest path between two nodes in a graph, the
 *   user will be prompted to enter the indices of the two nodes.
 * - To find the shortest path that visits all nodes in a graph,
 *   the user will be prompted to enter the number of nodes in the
 *   graph, followed by the indices of the nodes.
 ******************************************************/

/******************************************************
 * Examples:
 * - To add a new graph with 3 nodes and the following edges:
 *     - 0 -> 1 (weight 3)
 *     - 0 -> 2 (weight 5)
 *     - 1 -> 2 (weight 1)
 *   the user would input the following command:
 *     A
 *     3
 *     n 0 1 3 2 5
 *     n 1 2 1
 *
 * - To insert a new node with index 3 and the following edges:
 *     - 3 -> 0 (weight 2)
 *     - 3 -> 1 (weight 4)
 *   into an existing graph, the user would input the following command:
 *     B
 *     3
 *     0 2
 *     1 4
 *
 * - To delete node 2 from an existing graph, the user would input the following command:
 *     D
 *     2
 *
 * - To find the shortest path between nodes 0 and 2 in an existing graph, the user would input the following command:
 *     S
 *     0
 *     2
 *
 * - To find the shortest path that visits all nodes in an existing graph with 4 nodes (0, 1, 2, 3), the
