#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

int  cycleDetectedInDirected(int n ,vector<pair<int ,int>> &edges)
{

    // create adj list;

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first-1;
        int v = edges[i].second-1;

        adj[u].push_back(v);
    }

    // find all indegree of node/vertex;

    vector<int> indegree(n);

    for (auto i : adj)
    {

        for (auto j : i.second)
        {

            indegree[j]++;
        }
    }
    // 0 indegree ko queue me push kr do;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {

        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //  do bfs call;

    int count=0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        // inc count;

        count++;

        // neighbour indegree update;

        for(auto neighbour: adj[front]){

            indegree[neighbour]--;

            if(indegree[neighbour]==0)
            q.push(neighbour);
        }
    }

    if(count==n)
    return false;

    else 
    {
        return true;
    }
}
int main()
{

    return 0;
}