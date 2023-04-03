/*
province is something in which you can move from any single node to any other node in a graph.
So, Basically no of provinces is nothing but number of un-components in a graph.
Algo:
 We can apply any graph traversal and count no of un-connected components ( no of times DFS/BFS traversal is being called )
 TE -- O(V+E)
 SE -- 
*/
#include <bits/stdc++.h>
using namespace std;
void DFS(int currNode, vector<int>adjList[], vector<int> &visited){
  visited[currNode]=1;
  for(auto it : adjList[currNode]){
    if(!visited[it]){
      DFS(it,adjList,visited);
    }
  }
}
int main(){
  int vertices,edges;
  int provinces=0;
  cin>>vertices>>edges;
  vector<int> adjList[vertices+1];
  vector<int> visited(vertices+1,0);
  for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  for(int i=1;i<=vertices;i++){
    if(!visited[i]){
      provinces++;
      DFS(i,adjList,visited);
    }
  }
  cout<<provinces<<endl;
  return 0;
}
