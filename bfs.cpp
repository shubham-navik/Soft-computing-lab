#include<bits/stdc++.h>
using namespace std;
#define ll long long



void bfs(  unordered_map<int, list<int>> &adj,unordered_map<int, bool> &visited,queue<int> &que,int src){

    cout << src<<" ";
    visited[src] = 1;
    que.push(src);

    while(!que.empty()){
        
        int top = que.front();
        que.pop();

        for(auto neighbour:adj[top]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                cout << neighbour << " ";
                que.push(neighbour);
            }
        }
    }
}


int main(){
    vector<vector<int>> edges{{1,2},{2,3},{1,3},{4,1},{5,6},{6,1},{3,6},{2,4},{3,5}};
    int n = edges.size();
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    queue<int> que;

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

    bfs(adj, visited, que, src);

    return 0;
}