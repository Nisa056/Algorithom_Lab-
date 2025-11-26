#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>> g(n+1);
        while(m--){
            int u,v,w; cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> cnt(n+1,0);
        pq.push({0,1});
        int ans = -1;
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();
            cnt[u]++;
            if(u==n && cnt[u]==2){ ans=d; break; }
            if(cnt[u]>2) continue;
            for(auto [v,w]:g[u]) pq.push({d+w,v});
        }
        cout<<"Case "<<tc<<": "<<ans<<"\n";
    }
}
