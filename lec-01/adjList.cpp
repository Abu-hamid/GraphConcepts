#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;



class graph
{

public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        //    derection--0--if undirected;
        // direction--1--ifdirected;

        // creation of graph from U-->V;
        adj[u].push_back(v);

        if (direction == 0)
        {

            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {

        for (auto i : adj)
        {
            cout << i.first << "-->";

            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main()
{ int n;
cout<<"Enter the value of Nodes";
cin>>n;

int m;
cout<<"Enter the value of Edges";
cin>>m;

graph g;

for(int i=0;i<m;i++){

    int u,v;
    cin>>u>>v;

    // creating graph;
    g.addEdge(u,v,0);
}
g.printAdjList();

    return 0;
}






// Generic Creation of graph;
/*
template <typename T>
class graph
{

public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        //    derection--0--if undirected;
        // direction--1--ifdirected;

        // creation of graph from U-->V;
        adj[u].push_back(v);

        if (direction == 0)
        {

            adj[v].push_back(u);
        }
    }
    void printAdjList()
    {

        for (auto i : adj)
        {
            cout << i.first << "-->";

            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main()
{ int n;
cout<<"Enter the value of Nodes";
cin>>n;

int m;
cout<<"Enter the value of Edges";
cin>>m;

graph<int> g;

for(int i=0;i<m;i++){

    int u,v;
    cin>>u>>v;

    // creating graph;
    g.addEdge(u,v,0);
}
g.printAdjList();

    return 0;
}
*/