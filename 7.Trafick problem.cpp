#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Wormhole {
    int start, end, time;
};

bool hasNegativeCycle(int N, const vector<Wormhole>& wormholes) {
    vector<ll> dist(N, INF);
    dist[0] = 0;

    for (int i = 0; i < N - 1; ++i) {
        bool relaxed = false;
        for (auto w : wormholes) {
            if (dist[w.start] != INF && dist[w.start] + w.time < dist[w.end]) {
                dist[w.end] = dist[w.start] + w.time;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }

    for (auto w : wormholes) {
        if (dist[w.start] != INF && dist[w.start] + w.time < dist[w.end])
            return true;
    }
    return false;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<Wormhole> wormholes(M);
    for (int i = 0; i < M; ++i)
        cin >> wormholes[i].start >> wormholes[i].end >> wormholes[i].time;

    if (hasNegativeCycle(N, wormholes))
        cout << "possible\n";
    else
        cout << "not possible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    if (!(cin >> C)) return 0;

    while (C--) solve();

    return 0;
}

