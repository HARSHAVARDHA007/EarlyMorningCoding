/*
This Algorithm is used to traverse a matrix using graph traversal algorithms.
We can use either BFS or DFS to do a flood fill algorithm
*/
#include<bits/stdc++.h>
using namespace std;
    void DFS(int sr, int sc , int start_color , int new_color , vector<vector<int>>& image , vector<vector<int>>& visited, int rows[],int columns[]){
        visited[sr][sc]=1;
        image[sr][sc]= new_color;
        for(int i=0 ; i<4 ;i++){
            int nrow= sr+rows[i];
            int ncol= sc+columns[i];
            if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && !visited[nrow][ncol] && image[nrow][ncol]==start_color){
                DFS(nrow,ncol,start_color, new_color , image, visited, rows, columns);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int X[]={-1,0,1,0};
        int Y[]={0,1,0,-1};
        vector<vector<int>>answer = image;
        int rows = image.size();
        int columns = image[0].size();
        int start_color = image[sr][sc];
        vector<vector<int>>visited(rows, vector<int>(columns,0));
        DFS(sr, sc, start_color, newColor, answer, visited , X,Y);
        return answer;
    
    }
int main(){
  int rows, columns;
  cin>>rows>>columns;
  vector<vector<int>> adjMatrix(rows, vector<int>(columns));
  //Input
  for(int i=0; i<rows; i++){
    for(int j=0; j<columns; j++){
      cin >> adjMatrix[i][j];
    }
  }
  int sr , sc, newColor;
  cin>>sr >>sc >> newColor;
  vector<vector<int>> answer = floodFill( adjMatrix, sr , sc , newColor);
  for( auto row: answer){
    for(auto ele: row){
      cout<< ele << " ";
    }
    cout<< endl;
  }
  return 0;
}