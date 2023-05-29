/*

ALgo:

If we reach a node which is already visited in the PATH and that is not a parent then we say graph has a cycle. We use DFS to traverse the graph

Space -- O(V)
Time -- O(V+2E)
*/
#include<bits/stdc++.h>
using namespace std;
bool detect_cycle_DFS(int source, int parent , vector<int> &visited, vector<int> adjMatrix[]){
  visited[source]=1;
  for(auto it : adjMatrix[source]){
    if(!visited[it]){
      if(detect_cycle_DFS(it,source,visited,adjMatrix)){
        return true;
      }
    }
    else if( it != parent ){
      return true;
    }
  }
  return false;
}
int main(){
  bool cycle = false;
  int vertices,edges;
  cin>>vertices>>edges;
  vector<int> visited(vertices,0);
  vector<int> adjMatrix[vertices];
  for(int i=0;i<edges;i++){
    int u,v;
    cin>>u>>v;
    adjMatrix[u].push_back(v);
    adjMatrix[v].push_back(u);
  }
  for(int i=0;i<vertices;i++){
    if(!visited[i]){
      cycle = detect_cycle_DFS(i,-1,visited,adjMatrix);
      if(cycle){
        cout<<true<<endl;
        break;
      }
    }
  }
  if(!cycle){
    cout<<false<<endl;
  }
  return 0;
}