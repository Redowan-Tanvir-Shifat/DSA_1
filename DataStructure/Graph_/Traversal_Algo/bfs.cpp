#include<iostream>
#include<stack>
#include<queue>
using namespace std;
#define white 1
#define gray 2
#define black 3
#define infinity INT_MAX

class Graph{
    int nVertices;
    int **matrix;
    bool directed;  //directed->true, undirected->false
    int *color, *distance, *parent;
public:
    Graph(int n, bool dir){
        nVertices = n;
        directed = dir;
        matrix=new int*[n];  //stores the address of each row

        for(int i=0;i<n;i++)
            matrix[i]=new int[n];  //each row contains n integers

        //initialize all cell with 0
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = 0;
            }
        }

        color = new int[n];
        distance = new int[n];
        parent = new int[n];
    }

    void addEdge(int u, int v){
        if(u<0 || v<0 || u>=nVertices || v>=nVertices) return;

        matrix[u][v] = 1;
        if( ! directed ) matrix[v][u] = 1;

    }

    bool isEdge(int u, int v){
        if(u<0 || v<0 || u>=nVertices || v>=nVertices) return false;
        if(matrix[u][v] == 1) return true;
        else return false;
    }

    void display(){
        cout<<"Displaying Graph:"<<endl;
        for(int u=0; u<nVertices; u++){
            cout<<u<<" : ";
            for(int v=0; v<nVertices ;v++){
                if ( isEdge(u,v) ){
                    cout<<v<<", ";
                }
            }
            cout<<endl;
        }
    }

    void BFS(int src) {
        for(int i = 0; i < nVertices; i++) {
            color[i] = white;
            distance[i] = infinity;
            parent[i] = -1;
        }

        distance[src] = 0;
        color[src] = gray;

        queue<int> q;
        q.push(src);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v = 0; v < nVertices; v++) {
                if(isEdge(u, v)) {
                    if(color[v] == white) {
                        q.push(v);
                        parent[v] = u;
                        distance[v] = distance[u] + 1;
                        color[v] = gray;
                    }
                }
            }
            color[u] = black;
        }

        // for(int i = 0; i < nVertices; i++) {
        //     cout << i << "-> d:" << distance[i] << "  p:" << parent[i] << endl;
        // }

    }

    void path(int src, int des) {
        BFS(src);

        if(distance[des] == infinity) {
            cout << "No path exists between " << src << " and " << des << endl; 
        }
        else {
            cout << "Distance from " << src << " to " << des << ":" << distance[des] << endl;
            printPath(src, des);
        }
    }

    void printPath(int src, int des) {
        int d = des;
        stack<int> s;

        while(d != -1) {
            s.push(d);
            d = parent[d];
        }

        while(!s.empty()) {
            d = s.top();
            s.pop();
            cout << d << "-> ";
        }
        cout << endl;
    }
};

int main(){
    Graph g(9, false);

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,6);
    g.addEdge(3,4);
    g.addEdge(3,2);
    g.addEdge(4,5);
    g.addEdge(6,7);
    g.addEdge(6,8);

    // g.display();
    // g.BFS(0);
    // g.path(0, 5);
    g.path(0, 8);
}