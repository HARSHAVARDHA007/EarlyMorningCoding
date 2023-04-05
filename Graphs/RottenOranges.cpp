/*
Find minimum time find taken to rot all the oranges in the given grid
A rot orange can rot in 4-way direction in unit time.

Algo:

//DFS is not ideal to apply here as it goes depth wise and least time won't be fetched

BFS is ideal to be applied here as it moves level wise
But It will have many starting points (consider all the roten oranges as starting points and have an another variable to keep track of time)

*/

#include <bits/stdc++.h>
using namespace std;
int rottenOranges(vector<vector<int>> &grid)
{
  int answer = 0;
  int rows = grid.size();
  int cols = grid[0].size();
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<vector<int>> visited(rows, vector<int>(cols, 0));
  queue<pair<pair<int, int>, int>> q;
  // finding all the starting points
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (grid[i][j] == 2)
      {
        q.push(make_pair(make_pair(i, j), 0));
      }
    }
  }
  // Traverse all the 4- directions of the elemments
  while (!q.empty())
  {
    auto curr_ele = q.front();
    q.pop();
    int x = curr_ele.first.first;
    int y = curr_ele.first.second;
    answer = max(answer, curr_ele.second);
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
      int new_row = x + dx[i];
      int new_col = y + dy[i];
      if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !visited[new_row][new_col] && grid[new_row][new_col] == 1)
      {
        grid[new_row][new_col] = 2;
        q.push(make_pair(make_pair(new_row, new_col), curr_ele.second + 1));
      }
    }
  }
  // any orange unreachable case
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (grid[i][j] == 1)
      {
        return -1;
      }
    }
  }
  return answer;
}
int main()
{
  int rows, columns;
  cin >> rows >> columns;
  vector<vector<int>> adjMatrix(rows, vector<int>(columns));
  // Input
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
    {
      cin >> adjMatrix[i][j];
    }
  }
  int answer = rottenOranges(adjMatrix);
  cout << answer << endl;
  return 0;
}