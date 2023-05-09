#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &ap, unordered_map<int, list<int>> &adj,unordered_map<int, bool> &vis)
{

    vis[node] = true;

    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {

        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {

            dfs(nbr, node, timer, disc, low, ap, adj, vis);

            low[node] = min(low[node], low[nbr]); // during returning update our low;

            //  check point is articulation are not;
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node][0] = 1;
            }
            child++;
        }

        else
        {

            // back edges ;

            low[node] = min(low[node], disc[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

vector<vector<int>> Articulation(vector<vector<int>> &edges, int v, int e)
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
    vector<int> low(v);
    vector<vector<int>> ap(v, 0);

    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {

        disc[i] = -1;
        low[i] = -1;
    }

    // do dfs ;

    for (int i = 0; i < v; i++)
    {

        if (!vis[i])
        {
            dfs(i, -1, timer, disc, low, ap, adj, vis);
        }
    }
    return ap;
}
int main()
{

    return 0;
}