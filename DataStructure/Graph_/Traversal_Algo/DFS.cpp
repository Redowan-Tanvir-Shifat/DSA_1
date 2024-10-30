#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define white 1
#define gray 2
#define black 3
#define inf INT_MAX

class Graph
{
    int nVertices;
    int **matrix;
    bool directed; // directed->true, undirected->false
    int *color, *d, *f, *parent;
    int time;

public:
    Graph(int n, bool dir)
    {
        nVertices = n;
        directed = dir;
        matrix = new int *[n]; // stores the address of each row

        for (int i = 0; i < n; i++)
            matrix[i] = new int[n]; // each row contains n integers

        // initialize all cell with 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        color = new int[n];
        d = new int[n];
        f = new int[n];
        parent = new int[n];
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
            return;

        matrix[u][v] = 1;
        if (!directed)
            matrix[v][u] = 1;
    }

    bool isEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= nVertices || v >= nVertices)
            return false;
        if (matrix[u][v] == 1)
            return true;
        else
            return false;
    }

    void display() {
        cout << "Displaying Graph:" << endl;

        for (int u = 0; u < nVertices; u++) {
            cout << u << " : ";
            for (int v = 0; v < nVertices; v++) {
                if (isEdge(u, v)) {
                    cout << v << ", ";
                }
            }
            cout << endl;
        }
    }

    void path(int src, int dest) {
        DFS(src); 

        if (d[dest] == inf) {
            cout << "no path exists between " << src << " and " << dest << endl;
        }
        else {
            cout << "distance from " << src << " to " << dest << ":   " << endl;
            printPath(src, dest);
        }
    }

    // this function will print path from source to destination   
    void printPath(int src, int dest) {
        int d = dest; 
        stack<int> s;
        while(d != -1) {
            s.push(d);
            d = parent[d];
        }

        while (!s.empty()) {
            d = s.top();
            s.pop();
            cout << d << "-> ";
        }
        cout << endl;
    }


    // add necessary codes here
    void DFS(int src) {
        for (int i = 0; i < nVertices; i++) {
            color[i] = white;
            d[i] = inf;
            parent[i] = -1;
        }
        time = 0;

        DFS_visit(src);
    }

    void DFS_visit(int u) {
        color[u] = gray;
        time++;
        d[u] = time;

        for (int v = 0; v < nVertices; v++) {
            if (isEdge(u, v)) {
                if (color[v] == white) {
                    parent[v] = u;
                    DFS_visit(v);
                }
            }
        }
        color[u] = black;
        time++;
        f[u] = time;
    }
};


int main() {
    Graph g(8, false);
    
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,6);
    g.addEdge(3,4);
    g.addEdge(3,2);
    g.addEdge(4,5);
    g.addEdge(6,7);

    g.path(0, 7);
}