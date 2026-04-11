// File : BFS.cpp
// Author : Aiman Pashtun

#include "BFS.h"

// sets up city names and initializes the matrix and helper arrays
Graph::Graph()
{
    // store all city names in order by index
    cities[0] = "Seattle";
    cities[1] = "San Francisco";
    cities[2] = "Los Angeles";
    cities[3] = "Denver";
    cities[4] = "Chicago";
    cities[5] = "Kansas City";
    cities[6] = "Dallas";
    cities[7] = "Houston";
    cities[8] = "Atlanta";
    cities[9] = "Miami";
    cities[10] = "New York";
    cities[11] = "Boston";

    // initialize the adjacency matrix and helper arrays
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // distance from a city to itself is 0
            if (i == j)
                adjMatrix[i][j] = 0;
            else
                // otherwise, start with INF to mean no direct connection yet
                adjMatrix[i][j] = INF;

            // no edge has been printed yet
            edgePrinted[i][j] = false;
        }

        // no city has been visited yet
        visited[i] = false;
    }
}

// adds an undirected edge between two cities with the given mileage
void Graph::addEdge(int from, int to, int weight)
{
    adjMatrix[from][to] = weight;
    adjMatrix[to][from] = weight;
}

// returns the total number of cities
int Graph::getSize() const
{
    return SIZE;
}

// returns the city name at the given index
string Graph::getCityName(int index) const
{
    return cities[index];
}

// prints the adjacency matrix in table form
void Graph::printAdjacencyMatrix() const
{
    // Short names so the matrix fits nicely in the console
    string shortCities[SIZE] =
    {
        "SEA", "SF", "LA", "DEN",
        "CHI", "KC", "DAL", "HOU",
        "ATL", "MIA", "NY", "BOS"
    };

    cout << "\n******************************* ADJACENCY MATRIX *******************************\n\n";

    // Print top header row
    cout << setw(6) << "";
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << shortCities[i];
    }
    cout << endl;

    // Print each row
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(6) << shortCities[i];

        for (int j = 0; j < SIZE; j++)
        {
            if (adjMatrix[i][j] == INF)
                cout << setw(6) << "-";
            else
                cout << setw(6) << adjMatrix[i][j];
        }

        cout << endl;
    }

    cout << "\nCity abbreviations:\n";
    cout << "SEA = Seattle, SF = San Francisco, LA = Los Angeles, DEN = Denver\n";
    cout << "CHI = Chicago, KC = Kansas City,   DAL = Dallas,     HOU = Houston\n";
    cout << "ATL = Atlanta, MIA = Miami,        NY = New York,    BOS = Boston\n\n";
}

// performs BFS starting from the given city index
void Graph::bfs(int startIndex)
{
    // Reset visited and printed edges before starting BFS
    for (int i = 0; i < SIZE; i++)
    {
        visited[i] = false;
        for (int j = 0; j < SIZE; j++)
        {
            edgePrinted[i][j] = false;
        }
    }

    vector<int> currentLevel;
    vector<int> nextLevel;
    int totalDiscoveryDistance = 0;
    int level = 0;

    // Start BFS at the given starting city
    visited[startIndex] = true;
    currentLevel.push_back(startIndex);

    cout << "\n\n******************************* BFS TRAVERSAL *******************************\n";
    cout << "Starting Vertex: " << cities[startIndex] << "\n\n";

    while (!currentLevel.empty())
    {
        cout << "-------------------- Level " << level << " --------------------\n";
        cout << "Cities in this level: ";

        for (int i = 0; i < currentLevel.size(); i++)
        {
            cout << cities[currentLevel[i]];
            if (i < currentLevel.size() - 1)
                cout << ", ";
        }
        cout << "\n\n";

        nextLevel.clear();

        // Process vertices in the exact order they appear in this level
        for (int i = 0; i < currentLevel.size(); i++)
        {
            int current = currentLevel[i];
            vector<int> neighbors;

            // Collect all adjacent cities
            for (int j = 0; j < SIZE; j++)
            {
                if (adjMatrix[current][j] != INF && adjMatrix[current][j] != 0)
                {
                    neighbors.push_back(j);
                }
            }

            // Sort neighbors by smallest mileage first
            for (int a = 0; a < neighbors.size() - 1; a++)
            {
                for (int b = a + 1; b < neighbors.size(); b++)
                {
                    if (adjMatrix[current][neighbors[a]] > adjMatrix[current][neighbors[b]])
                    {
                        int temp = neighbors[a];
                        neighbors[a] = neighbors[b];
                        neighbors[b] = temp;
                    }
                }
            }

            cout << "From " << cities[current] << ":\n";

            for (int j = 0; j < neighbors.size(); j++)
            {
                int neighbor = neighbors[j];

                // Only output each undirected edge once
                if (!edgePrinted[current][neighbor] && !edgePrinted[neighbor][current])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        nextLevel.push_back(neighbor);
                        totalDiscoveryDistance += adjMatrix[current][neighbor];

                        cout << "   Discovery Edge -> "
                            << cities[current] << " -> " << cities[neighbor] << "\n";
                    }
                    else
                    {
                        cout << "   Cross Edge     -> "
                            << cities[current] << " -> " << cities[neighbor] << "\n";
                    }

                    edgePrinted[current][neighbor] = true;
                    edgePrinted[neighbor][current] = true;
                }
            }

            cout << "\n";
        }

        currentLevel = nextLevel;
        level++;
    }

    cout << "--------------------------------------------------\n";
    cout << "Total Distance on Discovery Edges: "
        << totalDiscoveryDistance << " miles\n";
}