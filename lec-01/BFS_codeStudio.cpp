#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
using namespace std;

class bfstraversal
{

public:
    void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges) // first of all we create an adjLIst;
    {

        for (int i = 0; i < edges.size(); i++)
        {

            int u = edges[i].first;
            int v = edges[i].second;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
    {

        queue<int> q;
        q.push(node);      // initialised the queue with node value;
        visited[node] = 1; // and mark as visited;

        while (!q.empty())
        {

            int frontNode = q.front(); // remove front element from queue and store in frontNOde var;;
            q.pop();

            //    store frontNode value into ans;
            ans.push_back(frontNode);

            //  traverse all neighbour of frontNode;

            for (auto i : adjList[frontNode])
            {

                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

    vector<int> BFS(int vertex, vector<pair<int, int>> edges)
    {

        unordered_map<int, list<int>> adjList;
        vector<int> ans;
        unordered_map<int, bool> visited;

        prepareAdjList(adjList, edges);

        //    traversing all the component of graph;

        for (int i = 0; i < vertex; i++)
        {

            if (!visited[i])
            {

                bfs(adjList, visited, ans, i);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}