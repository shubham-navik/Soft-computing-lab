#include<bits/stdc++.h>
using namespace std;




void dfs(  unordered_map<int, list<int>> &adj,unordered_map<int, bool> &visited,int src){

    cout << src<<" ";
    visited[src] = 1;

    for(auto neighbour:adj[src]){
        if(!visited[neighbour]){
            dfs(adj, visited, neighbour);
        }
    }

}


int main(){
    vector<vector<int>> edges{{1,2},{2,3},{1,3},{4,1},{5,6},{6,1},{3,6},{2,4},{3,5}};
    int n = edges.size();
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    // create graph

    for (int i = 0; i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src;
    cout << "Enter the source \n";
    cin >> src;

    dfs(adj, visited, src);

    return 0;
}