/*
  Cycle detcetion in an undirected graph using BFS

  Algo:
   As BFS traverse in the level wise and if we reach a node which is already visited then we can declare that there is a cycle [ except the node which we came from (parent)]
*/

#include<bits/stdc++.h>
using namespace std;
bool detectCycle(int src , vector<int> adj[], vector<int> & visited){
  visited[src]=1;
  queue<pair<int,int>> q;
  q.push(make_pair(src, -1));
  while(!q.empty()){
    int curr_node = q.front().first;
    int parent = q.front().second;
    q.pop();
    for( auto adjNode : adj[curr_node]){
      if(!visited[adjNode]){
        visited[adjNode] = 1;
        q.push(make_pair(adjNode, curr_node));
      }
      else if( parent != adjNode )
      {
        return true;
      }
    }
  }
  return false; 
}
bool isCycle(int V, vector<int>adj[]){
  vector<int> visited(V,0);
  for(int i=0; i<V; i++){
    if(!visited[i]){
      if(detectCycle(i,adj,visited)){
        return true;
      }
    }
  }
  return false;
}

int main(){
  return 0;
}