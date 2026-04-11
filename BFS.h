// File : BFS.h
// Author : Aiman Pashtun

#ifndef BFS_H
#define BFS_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Graph
{
private:
    // total number of cities in the graph
    static const int SIZE = 12;

    // represents no connection
    static const int INF = 999999;

    // adjacency matrix to store mileages between cities
    int adjMatrix[SIZE][SIZE];

    // array storing the city names
    string cities[SIZE];

    // keeps track of whether a city has been visited during BFS
    bool visited[SIZE];

    // keeps track of whether an edge has already been printed
    bool edgePrinted[SIZE][SIZE];

public:
    // constructor to initialize the graph
    Graph();

    // adds an edge between two cities with the given mileage
    void addEdge(int from, int to, int weight);

    // prints the adjacency matrix
    void printAdjacencyMatrix() const;

    // performs BFS starting at the given city index
    void bfs(int startIndex);

    // returns the total number of cities
    int getSize() const;

    // returns the city name at a given index
    string getCityName(int index) const;
};

#endif