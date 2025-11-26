#include <bits/stdc++.h>
using namespace std;

int main() {
    string a,b;
    int dx[8]={1,1,2,2,-1,-1,-2,-2};
    int dy[8]={2,-2,1,-1,2,-2,1,-1};
    while(cin>>a>>b){
        vector<vector<int>> dis(8,vector<int>(8,-1));
        int sx=a[0]-'a', sy=a[1]-'1';
        int tx=b[0]-'a', ty=b[1]-'1';
        queue<pair<int,int>>q;
        q.push({sx,sy}); dis[sx][sy]=0;
        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            for(int i=0;i<8;i++){
                int nx=x+dx[i], ny=y+dy[i];
                if(nx>=0&&ny>=0&&nx<8&&ny<8&&dis[nx][ny]==-1){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<dis[tx][ty]<<" knight moves.\n";
    }
}
