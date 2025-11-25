 #include<bits/stdc++.h>
 using namespace std;
 int fx[] = {1, 0, -1, 0};
 int fy[] = {0, 1, 0, -1};
 void bfs_grid(int n, int x, int y){
  int dis[n][n], color[n][n];
 queue<pair<int, int> > q;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
 dis[i][j] = INT_MAX;
 color[i][j] = -1;
  } }
 dis[x][y] = 0;
 color[x][y] = 1;
 q.push({x, y});
 while (!q.empty()) {
 pair<int, int> u = q.front();
 q.pop();
 for (int i = 0; i < 4; i++) {
  int new_x = u.first + fx[i];
  int new_y = u.second + fy[i];
 if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && color[new_x][new_y] == -1) {
 color[new_x][new_y] = 1;
 dis[new_x][new_y] = dis[u.first][u.second] + 1;
 q.push({new_x, new_y});
 } }
 color[u.first][u.second] = 2;
 }
 cout << "Distance:" << endl;
 for (int i = 0; i < n; i++) {
 for (int j = 0; j < n; j++) {
  cout << dis[i][j] << " ";
 }
 cout << endl;
 }
 return;
 }
  int main()
 {
 int n, x, y;
 cout << "Enter the grid size : ";
 cin >> n;
 cout << "Enter the row and column of source: ";
 cin >> x >> y;
 bfs_grid(n, x, y);
 return 0;
   }
