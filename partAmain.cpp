/*******************************************************************************
* Programmer: Sophie Omar
* Assignment: HW 9 - DFS & BFS Part A
* Purpose: Implementing a depth first search using an adjacency list structure.
* Due Date:April 13, 2026
* ******************************************************************************/
#include <iostream>
#include <vector>
#include "DFS.h"
using namespace std;



int main() {

  AdjGraph g;

  // add all the edges

  // dallas
  g.addEdge(10, 11, 239);
  g.addEdge(10, 4, 496);
  g.addEdge(10, 8, 781);
  g.addEdge(10, 2, 1435);

  // houston
  g.addEdge(11, 8, 810);
  g.addEdge(11, 9, 1187);

  //atl
  g.addEdge(8, 9, 661);
   g.addEdge(8, 4, 864);
  g.addEdge(8, 7, 888);

  //ny
    g.addEdge(7, 6, 214);
    g.addEdge(7, 5, 787);
    g.addEdge(7, 4, 1260);

  // boston
   g.addEdge(6, 5, 983);

   // kansas city
    g.addEdge(4, 5, 533);
    g.addEdge(4, 3, 599);
    g.addEdge(4, 2, 1663);

    //chicago
    g.addEdge(5, 3, 1003);
    //denve
    g.addEdge(3, 2, 1015);
    g.addEdge(3, 1, 1267);
    g.addEdge(3, 0, 1331);

    // sna fran
    g.addEdge(1, 2, 381);

    //seattle
    g.addEdge(0, 1, 807);

    //total should be like 7314 miles
    g.sortAdjList();
    g.dfs(10); //starts at dallas
    //g.printAdjList();
    return 0;


}