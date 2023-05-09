#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;


bool cycleDFS(int node ,unordered_map<int, bool> &visited ,unordered_map<int, bool> &dfsVisited ,unordered_map<int, list<int>> &adj){
 
  
   visited[node] =true; 
   dfsVisited[node]=true;

   for(auto neighbour:adj[node]){

       if(!visited[neighbour]){

           bool cycledetected =cycleDFS(neighbour ,visited,dfsVisited,adj);
           if(cycledetected)
           return true;
       }
       else if(dfsVisited[neighbour]){
           return true;
       }
   }


// reset the dfsVisited ;

   dfsVisited[node] =false;

   return false;

}













int cycledirectedgraph(int n, vector<pair<int, int>> &edges)
{

    // create  adj list;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    //  call dfs for all the componenet;

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            bool cycleFound = cycleDFS(i, visited, dfsVisited, adj);

            if (cycleFound)
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}