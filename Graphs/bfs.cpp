// Time complexity O(E+V)
//space Complexity O(V)[to store BFS answer] + O(V)[ For Visited Array] +  O(V+E) [ for Adjacency List ] 
//This uses Queue data structure
#include<bits/stdc++.h>
using namespace std;
vector<int>BFS(int n_f_vertices , vector<int>adjList[]){
  vector<int> visited(n_f_vertices+1,0);
  vector<int>bfs;
  for(int i=1 ; i<=n_f_vertices;i++){
    if(!visited[i]){
      queue<int> queue;
      queue.push(i);
      visited[i]=1;
      while(!queue.empty()){
        int curr_node = queue.front();
        bfs.push_back(curr_node);
        queue.pop();
        for(auto it : adjList[curr_node]){
          if(!visited[it]){
            queue.push(it);
            visited[it]=1;
          }
        }
      }
    }
  }
  return bfs;
}
int main(){
  int edges,vertices;
  cin>>edges>>vertices;
  vector<int> adjList[vertices+1];
  for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  vector<int>bfs=BFS(vertices,adjList);
  for(auto it : bfs){
    cout<<it<<" ";
  }
  cout<<endl;
  return 0;
}