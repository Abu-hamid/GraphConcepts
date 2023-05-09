#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;


void toposort(int node ,vector<bool>&visited ,stack<int>&s ,unordered_map<int,list<int>>&adj ){


    visited[node]=1;

    for(auto nieghbour:adj[node]){
        if(!visited[nieghbour])
        toposort(nieghbour ,visited ,s ,adj);
    }

    // important;

    s.push(node);
}

vector<int>topologicalsort(vector<vector<int>>&edges , int v,int e){

    // create an adj list;
    unordered_map<int,list<int>>adj;

    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topological sort util function for all component;

    vector<bool>visited;

    stack<int>s;
    for(int i=0;i<v;i++){

        if(!visited[i])

        toposort(i ,visited ,s ,adj);
    }
    vector<int>ans;


    while(!s.empty()){

        ans.push_back(s.top());

        s.pop();
    }
    return ans;
}










int main(){

return 0;
}