#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> Dijkstra(vector<vector<int>> &vec, int vertice, int edges, int source)
{

    //   create a adj list;

    unordered_map<int, list<pair<int, int>>> adj;

    for (int i = 0; i < edges; i++)
    {

        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }


// create the disance arrry with initially infinity value;
    vector<int> dis(vertice);
    for (int i = 0; i < vertice; i++)

        dis[i] = INT_MAX;


// create the set on the basis of (distance ,node);
        set<pair<int ,int>>st;



//  initially distance and set with source node;
        dis[source]=0;

        st.insert(make_pair(0 , source));

        while(!st.empty()){

            // fetch the top record;

            auto top = *(st.begin());

            int nodeDistance =top.first;
            int topNode =top.second;

            // erase the top set value;

            st.erase(st.begin());


            // traverse the top of neighbour;

            for(auto neighbour:adj[topNode]){

                if(nodeDistance+neighbour.second <dis[neighbour.first]){

                    auto record =st.find(make_pair(dis[neighbour.first] ,neighbour.first));

                    // if record is found , then erase it;

                    if(record!=st.end()){

                        st.erase(record);
                    }

                    // update the distance vector;

                    dis[neighbour.first]= nodeDistance+neighbour.second;


                    // record pudh in set ;

                    st.insert(make_pair(dis[neighbour.first], neighbour.first));


                }
            }
        }


        return dis;
}

  

/*




time compexity is o(E log V);

space complexity is O(N +E);

*/







int main()
{

    return 0;
}