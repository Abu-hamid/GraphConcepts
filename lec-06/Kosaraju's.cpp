#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {

            dfs(nbr, vis, st, adj);
        }
    }
    // topo Sort logic;
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;

    for (auto nbr : adj[node])
    {

        if (!vis[nbr])
        {

            revDfs(nbr, vis, adj);
        }
    }
}

int StronglyConnectedComp(int v, vector<vector<int>> &edges)
{

    // create adj list;

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // topo Sort;

    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {

        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    // create transpose graph ;

    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < v; i++)
    {

        vis[i] = 0;
        for (auto nbr : adj[i])
        {

            transpose[nbr].push_back(i);
        }
    }

    // dfs call using above tranpose graph;

    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;

            revDfs(top, vis, transpose);
        }
    }
    return count;
}
int main()
{

    return 0;
}