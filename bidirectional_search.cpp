#include<bits/stdc++.h>
using namespace std;


// creating graph
unordered_map<int, list<int>> adj;

// function to add edge in graph
void addEdge(int u ,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool BDS(int start , int end){
    unordered_map<int, bool> startVisited, endVisited;
    queue<int> startQ, endQ;

    // visited the start and end node
    startVisited[start] = true;
    endVisited[end] = true;

    startQ.push(start);
    endQ.push(end);

    while(!startQ.empty() && !endQ.empty()){

        //search from start
        int currentstart = startQ.front();
        startQ.pop();

        for(auto neighbour : adj[currentstart]){
            if(!startVisited[neighbour]){
                startVisited[neighbour] = true;
                startQ.push(neighbour);
            }

            //check meating poin 
            if(endVisited[neighbour] == true){
                 cout << "Found at node  " << neighbour<<endl;
                return true;
            }
        }



        int currentend = endQ.front();
        endQ.pop();

        for(auto neighbour : adj[currentend]){
            if(!endVisited[neighbour]){
                endVisited[neighbour] = true;
                endQ.push(neighbour);
            }


            //check meating poin 
            if(startVisited[neighbour] == true){
                cout << "Found at node  " << neighbour<<endl;
                return true;
            }
        }
    }

    return false;
}

int main(){

    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(3, 4);
    addEdge(2, 4);
    addEdge(3, 5);
    // addEdge(5, 6);
    addEdge(4, 6);
    addEdge(4, 7);
    // addEdge(7, 8);
    addEdge(6, 9);
    addEdge(8, 10);
    addEdge(9, 10);

    if(BDS(1,10)){
        cout << " successfull executed \n";
    }
    else{
        cout << "No path between start and end Node" << endl;
    }

    return 0;
}