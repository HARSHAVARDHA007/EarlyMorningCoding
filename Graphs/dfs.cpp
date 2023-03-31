// Time complexity O(E+V)
//space Complexity O(V)[to store BFS answer] + O(V)[ For Visited Array] + O(V+E) [ for Adjacency List ] + O(V) stack trace
//This uses stack Data structure 
#include<bits/stdc++.h>
using namespace std;
void DFS(int curr_node , vector<int> visited , vector<int>adjList[], vector<int> dfs){
  dfs.push_back(curr_node);
  for(auto it : adjList[curr_node]){
    if(!visited[it]){
      DFS(it , visited , adjList , dfs); 
    }
  }
}
int main(){
  int edges,vertices;
  cin>>edges>>vertices;
  vector<int> adjList[vertices+1];
  vector<int> visited(vertices+1,0);
  vector<int> dfs;
  for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  //DFS algo 
  for(int i=1 ; i< vertices; i++){
    if(!visited[i]){
      DFS(i, visited , adjList , dfs);
    }
  }
  for(auto it : dfs){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}