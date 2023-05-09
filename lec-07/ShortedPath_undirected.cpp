#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    //   create adj list;

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //   call bfs ;

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;

    parent[s] = -1;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {

        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {

            if (!visited[i])
            {

                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    //  prepaire shortest path;

    vector<int> ans;
    int currNode = t;
    ans.push_back(t);

    while (currNode != s)
    {

        currNode = parent[currNode];
        ans.push_back(currNode);
    }


    // before return the ans first we reverse the ans vector;

    reverse (ans.begin(),ans.end());

    return ans;
}






int main()
{

    return 0;
}