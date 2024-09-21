#include<iostream>
using namespace std;

class Graph {
    int nVertices;
    int **matrix;
    bool directed;//directed->true, undirected->false
public:
    Graph(int n, bool dir){
        nVertices = n;
        directed = dir;
        matrix=new int*[n];//stores the address of each row

        for(int i=0;i<n;i++)
            matrix[i]=new int[n];//each row contains n integers

        //initialize all cell with 0
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = 0;
            }
        }
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
};

int main(){
    Graph g(5, false);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.display();
}




