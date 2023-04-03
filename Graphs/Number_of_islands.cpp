/*
 Island is something which is surrounded by water on all the 8 sides ( sides ways as well as diagonally)
 eg:

 0 1 1 0
 0 1 1 0        // This has 3 islands
 0 0 1 0
 0 0 0 0
 1 1 0 1

TE -- 
SE --

*/
#include<bits/stdc++.h>
using namespace std;
void DFS(int row,  int column, vector<vector<int>>&adjMatrix , vector<vector<int>> &visited){
  visited[row][column]=1;
  for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){
      int nrow = row+i;
      int ncol = column+j;
      if(nrow>=0 && nrow< adjMatrix.size() && ncol>=0 && ncol< adjMatrix[0].size() && adjMatrix[nrow][ncol]==1 && !visited[nrow][ncol]){
        DFS(nrow,ncol, adjMatrix,visited);
      }
    }
  }
}
int main(){
  int islands=0;
  int rows, columns;
  cin>>rows>>columns;
  vector<vector<int>> adjMatrix(rows, vector<int>(columns));
  vector<vector<int>> visited(rows , vector<int>(columns,0));
  //Input
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
        int val;
        cout << "enter value : "<< endl;
        cin>>val;
        adjMatrix[i][j]=val;
    }
  }
  //Traversal
  for(int i=0;i<rows;i++){
    for(int j=0;j<columns;j++){
      if(adjMatrix[i][j]!=0 && !visited[i][j]){
        islands++;
        DFS(i,j,adjMatrix,visited);
      }
    }
  }
  cout<<islands<<endl;

}
