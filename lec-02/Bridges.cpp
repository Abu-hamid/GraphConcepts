#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis)
{

    vis[node] = true;

    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {

        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {

            dfs(nbr , node, timer, disc, low, result, adj, vis);

            low[node] = min(low[node], low[nbr]); // during returning update our low;

            //  check edges are bridges are not;
            if (low[node] > disc[nbr])
            {

                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }

        else
        {

            // back edges ;

            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> FindBridge(vector<vector<int>> &edges, int v, int e)
{

    // create an adj list;

    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    int parent = -1;
    vector<int> low(v);

    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {

        disc[i] = -1;
        low[i] = -1;
    }

    // do dfs ;
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {

        if (!vis[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, vis);
        }
    }
    return result;
}
int main()
{

    return 0;
}