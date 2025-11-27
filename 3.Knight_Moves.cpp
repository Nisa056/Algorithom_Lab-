#include <bits/stdc++.h>
using namespace std;

const int kr[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int kc[] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs_knight(int startR, int startC, int endR, int endC) {
    const int n = 8;
    int dis[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dis[i][j] = INT_MAX;

    queue<pair<int,int>> q;
    dis[startR][startC] = 0;
    q.push({startR,startC});

    while(!q.empty()) {
        auto [r,c] = q.front(); q.pop();
        if(r==endR && c==endC) return dis[r][c];

        for(int i=0;i<8;i++){
            int nr = r + kr[i], nc = c + kc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && dis[nr][nc]==INT_MAX){
                dis[nr][nc] = dis[r][c]+1;
                q.push({nr,nc});
            }
        }
    }
    return 0;
}

int main() {
    string s1,s2;
    while(cin >> s1 >> s2){
        int startR = s1[1]-'1', startC = s1[0]-'a';
        int endR = s2[1]-'1', endC = s2[0]-'a';
        int moves = bfs_knight(startR,startC,endR,endC);
        cout << "To get from " << s1 << " to " << s2 << " takes " << moves << " knight moves." << endl;
    }
    return 0;
}
