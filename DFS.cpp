/*******************************************************************************
* Programmer: Sophie Omar
* Assignment: HW 9 - DFS & BFS Part A
* Purpose: Implementing a depth first search using an adjacency list structure.
* Due Date:April 13, 2026
* ******************************************************************************/
#include "DFS.h"

 //initialize everything do that a city isn't visited or printed
 AdjGraph::AdjGraph(){
  totalDistance = 0;

  for(int i =0; i < NUM_CITY; i++){
    visited[i] = false;
    for(int j =0; j < NUM_CITY; j++){
      printed[i][j] = false;

    }
  }
 };

 void AdjGraph::addEdge(int u, int v, int w){
     adjList[u].push_back({v, w});
     adjList[v].push_back({u, w});
 }


 // sorting with bubble sort
 void AdjGraph::sortAdjList(){
   for(int i = 0; i < NUM_CITY; i++){
     for(int j =0; j < adjList[i].size(); j++){
       for(int k =j+1; k < adjList[i].size(); k++){
         if(adjList[i][j].weight > adjList[i][k].weight){
           Edge temp = adjList[i][j];
           adjList[i][j] = adjList[i][k];
           adjList[i][k] = temp;
         }

       }
     }
   }
 }


 //print
void AdjGraph::printAdjList() {
   for (int i = 0; i < NUM_CITY; i++) {
     cout << cities[i] << ": ";
     for (int j = 0; j < adjList[i].size(); j++) {
       cout << "(" << cities[adjList[i][j].city]
            << ", " << adjList[i][j].weight << ") ";
     }
     cout << endl;
   }
 }
 // dfs
 void AdjGraph::dfs(int start){
   // reset the visit and print
   for (int i = 0; i < NUM_CITY; i++) {
     visited[i] = false;
     for (int j = 0; j < NUM_CITY; j++) {
       printed[i][j] = false;
     }
   }
   totalDistance = 0;
   dfsHelp(start); // actual traversal  here
   cout << "\nTotal Discovery Distance: "
         << totalDistance << endl;
 }

void AdjGraph::dfsHelp(int current) {
   visited[current]= true;

   for (int i = 0; i < adj[current].size(); i++) {
     int neighbor =adjList[current][i].city;
     int weight = adjList[current][i].weight;

     if (!visited[neighbor]) {
       if (!printed[current][neighbor]) { //discovery edge
         cout << cities[current] << " -> "
            << cities[neighbor] << " (Discovery Edge)" << endl;

         printed[current][neighbor] = true;
         printed[neighbor][current] = true;
       }
       totalDistance += weight;
       dfsHelp(neighbor);
     }
     else { // back edge
       if (!printed[current][neighbor]) {
         cout << cities[current] << " -> "
             << cities[neighbor] << " (Back Edge)" << endl;

         printed[current][neighbor] = true;
         printed[neighbor][current] = true;
       }

   }
 }