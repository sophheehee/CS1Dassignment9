/*******************************************************************************
* Programmer: Sophie Omar
* Assignment: HW 9 - DFS & BFS Part A
* Purpose: Implementing a depth first search using an adjacency list structure.
* Due Date:April 13, 2026
* ******************************************************************************/
#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class AdjGraph{
  private:
    //keeps track of distance
    int totalDistance;

        //hold city name and distance
       struct Edge {
         int city; // goes by the enum index
         int weight;
       };

       vector<Edge> adjList[NUM_CITY];

       bool visited[NUM_CITY]; // check if it was alrady visited
       bool printed[NUM_CITY][NUM_CITY]; // check if printed

    //storre city names
      string cities[NUM_CITY] = {"Seattle", "San Francisco", "Los Angeles", "Denver",
       "Kansas City", "Chicago", "Boston", "New York",
       "Atlanta", "Miami", "Dallas", "Houston"};

       //constant for citites
       static const int NUM_CITY = 12;

       //helper for initializing DFS
       void dfsHelp(int current);



  public:
    //constructor for graph
    adjGraph();

    //adds an edge
    void addEdge(int u, int v, int w);

    //prints list
    void printAdjList();

    // sort
    void sortAdjList();

    void dfs(int start);

};
#endif //DFS_H
