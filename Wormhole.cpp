#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<tuple<int,int,int>> edges;
        while(m--){
            int u,v,w;
            cin>>u>>v>>w;
            edges.push_back({u,v,w});
        }
        vector<long long> dis(n,1e18);
        dis[0]=0;
        for(int i=0;i<n-1;i++){
            for(auto &[u,v,w]:edges){
                if(dis[u]+w<dis[v]) dis[v]=dis[u]+w;
            }
        }
        bool neg=false;
        for(auto &[u,v,w]:edges){
            if(dis[u]+w<dis[v]) neg=true;
        }
        cout<<(neg?"possible":"not possible")<<"\n";
    }
}

