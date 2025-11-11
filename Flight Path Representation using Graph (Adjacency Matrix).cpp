/*
------------------------------------------------------------
Algorithm: Flight Path Representation using Graph (Adjacency Matrix)
------------------------------------------------------------
1. Start
2. Read number of cities (n)
3. Read names of all cities
4. Create an n x n adjacency matrix where:
      a) matrix[i][j] = cost/time between city i and j
      b) If no direct flight → 0
5. Input connections (edges) between cities and their cost/time
6. Display adjacency matrix
7. Perform DFS from the first city:
      a) Mark current city as visited
      b) Visit all connected cities recursively
8. After DFS, if all cities are visited → Graph is Connected
   else → Graph is Not Connected
9. Stop
------------------------------------------------------------
*/

#include <iostream>
#include <string>
using namespace std;

class Graph {
    int n;
    string city[10];
    int adj[10][10];
    bool visited[10];
public:
    Graph(int size) {
        n = size;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void readCities() {
        cout << "Enter names of " << n << " cities:\n";
        for (int i = 0; i < n; i++)
            cin >> city[i];
    }

    void addEdge(int u, int v, int cost) {
        adj[u][v] = cost;
        adj[v][u] = cost;
    }

    void createGraph() {
        int e, u, v, cost;
        cout << "Enter number of flight connections: ";
        cin >> e;
        cout << "Enter connections (source_index destination_index cost):\n";
        for (int i = 0; i < e; i++) {
            cin >> u >> v >> cost;
            addEdge(u, v, cost);
        }
    }

    void display() {
        cout << "\nAdjacency Matrix (Flight Costs):\n";
        cout << "\t";
        for (int i = 0; i < n; i++)
            cout << city[i] << "\t";
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << city[i] << "\t";
            for (int j = 0; j < n; j++)
                cout << adj[i][j] << "\t";
            cout << "\n";
        }
    }

    void dfs(int v) {
        visited[v] = true;
        for (int i = 0; i < n; i++)
            if (adj[v][i] != 0 && !visited[i])
                dfs(i);
    }

    bool isConnected() {
        for (int i = 0; i < n; i++) visited[i] = false;
        dfs(0);
        for (int i = 0; i < n; i++)
            if (!visited[i]) return false;
        return true;
    }
};

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    Graph g(n);
    g.readCities();
    g.createGraph();
    g.display();

    if (g.isConnected())
        cout << "\nThe graph is CONNECTED.\n";
    else
        cout << "\nThe graph is NOT CONNECTED.\n";
    return 0;
}

/*
--------------------- Sample Output ---------------------
Enter number of cities: 4
Enter names of 4 cities:
Pune Mumbai Delhi Chennai
Enter number of flight connections: 4
Enter connections (source_index destination_index cost):
0 1 2
1 2 4
2 3 3
3 0 5

Adjacency Matrix (Flight Costs):
        Pune    Mumbai  Delhi   Chennai
Pune    0       2       0       5
Mumbai  2       0       4       0
Delhi   0       4       0       3
Chennai 5       0       3       0

The graph is CONNECTED.
---------------------------------------------------------
*/
