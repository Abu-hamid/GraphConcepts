#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

bool isCycleDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{

    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycledetected = isCycleDFS(neighbour, node, visited, adj);
            if (cycledetected)
                return true;
        }
        else if (neighbour != parent)
        {

            // cycle presnt;
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < n; i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //  to handle the disconnected component ;

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            bool ans = isCycleDFS(i, -1 , visited, adj);

            if (ans == 1)
                return " Yes";
        }
    }
    return "No";
}













int main(){
    return 0;
}