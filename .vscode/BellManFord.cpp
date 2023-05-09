#include <iostream>
#include <vector>

using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    vector<int> dis(n + 1, 1e9);

    dis[src] = 0;

    // n-1 times check formula of updation;
    for (int i = 1; i <= n; i++)
    {

        // traverse on edges;
        for (int j = 0; j < m; j++)
        {

            int u = edges[j][0];
            int v = edges[j][1];

            int wt = edges[j][2];

            if (dis[u] != 1e9 && ((dis[u] + wt) < dis[v]))
            {

                dis[v] = dis[u] + wt;
            }
        }
    }

    // check for negativ cycle int the given graph;

    bool flage = 0;

    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dis[u] != 1e9 && ((dis[u] + wt) < dis[v]))
        {

            flage = 1;
        }
    }

    if (flage == 0)
    {

        return dis[dest];
    }

    return -1;
}
int main()
{

    return 0;
}