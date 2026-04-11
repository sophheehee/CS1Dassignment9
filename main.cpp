// File : main.cpp
// Author : Aiman Pashtun
/* Program Description: This program uses an adjacency matrix to represent the city graph,
   performs a BFS starting at Dallas by always choosing the smallest mileage edge first, 
   labels discovery and cross edges, and calculates the total distance of the discovery edges.
*/

#include "BFS.h"

int main()
{
    cout << "************************************************************************************\n";
    cout << "* Author     : Aiman Pashtun                                                       *\n";
    cout << "* Class      : CS1D - Data Structures                                              *\n";
    cout << "* Assignment : #9 - DFS and BFS                                                    *\n";
    cout << "* Part       : B                                                                   *\n";
    cout << "* Due Date   : 04/13/2026                                                          *\n";
    cout << "************************************************************************************\n\n";

    Graph g;

    // Seattle
    g.addEdge(0, 1, 807);
    g.addEdge(0, 3, 1331);
    g.addEdge(0, 4, 2097);

    // San Francisco
    g.addEdge(1, 2, 381);
    g.addEdge(1, 3, 1267);

    // Los Angeles
    g.addEdge(2, 3, 1015);
    g.addEdge(2, 5, 1663);
    g.addEdge(2, 6, 1435);

    // Denver
    g.addEdge(3, 4, 1003);
    g.addEdge(3, 5, 599);

    // Chicago
    g.addEdge(4, 5, 533);
    g.addEdge(4, 10, 787);
    g.addEdge(4, 11, 983);

    // Kansas City
    g.addEdge(5, 6, 496);
    g.addEdge(5, 8, 864);
    g.addEdge(5, 10, 1260);

    // Dallas
    g.addEdge(6, 7, 239);
    g.addEdge(6, 8, 781);

    // Houston
    g.addEdge(7, 8, 810);
    g.addEdge(7, 9, 1187);

    // Atlanta
    g.addEdge(8, 9, 661);
    g.addEdge(8, 10, 888);

    // New York
    g.addEdge(10, 11, 214);

    g.printAdjacencyMatrix();
    g.bfs(6);   // Dallas

    return 0;
}