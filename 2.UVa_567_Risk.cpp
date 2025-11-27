#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    while (true) {
        vector<vector<int>> g(21);
        int x;

        if (!(cin >> x)) break;

        g[1].push_back(x);
        g[x].push_back(1);

        for (int i = 2; i <= 19; i++) {
            int num;
            cin >> num;
            for (int j = 0; j < num; j++) {
                int v;
                cin >> v;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }

        int N;
        cin >> N;

        cout << "Test Set #" << T++ << "\n";

        while (N--) {
            int A, B;
            cin >> A >> B;

            queue<int> q;
            vector<int> dist(21, -1);
            dist[A] = 0;
            q.push(A);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : g[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            cout << setw(2) << A << " to "
                 << setw(2) << B << ": "
                 << dist[B] << "\n";
        }

        cout << "\n";
    }

    return 0;
}
