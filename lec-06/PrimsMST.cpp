#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

vector<pair<pair<int, int>, int>> CalculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    // create adj list ;

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < g.size(); i++)
    {

        int u = g[i].first.first;

        int v = g[i].first.second;

        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<int> mst(n + 1);
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    // let's start our algo;

    key[1] = 0;
    parent[1] = -1;

    for (int i = 0; i <= n; i++)
    {

        int mini = INT_MAX;
        int u;

        // find minimum value node;

        for (int v = 1; v <= n; v++)
        {

            if (mst[v] == false && key[i] < mini)
            {

                u = v;
                mini = key[i];
            }
        }

        // marks min. node is true;

        mst[u] = true;

        // check its adj list;

        for (auto it : adj[u])
        {

            int v = it.first;

            int w = it.second;

            if (mst[v] == false && w < key[v])
            {

                parent[v] = u;

                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;

    for (int i = 2; i <= n; i++)
    {

        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{

    return 0;
}