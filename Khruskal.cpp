#include <bits/stdc++.h>
using namespace std;
struct Edge {
int u, v, w;
};
bool cmp(Edge a, Edge b) {
return a.w < b.w;
}
int parent[1000];
int findParent(int x) {
if (parent[x] == x) return x;
return parent[x] = findParent(parent[x]);
}
void unionSet(int a, int b) {
a = findParent(a);
b = findParent(b);
parent[b] = a;
}
int main() {
int n, m;
cin >> n >> m;
vector<Edge> edges(m);
for (int i = 0; i < m; i++)
cin >> edges[i].u >> edges[i].v >> edges[i].w;
for (int i = 1; i <= n; i++)
parent[i] = i;
sort(edges.begin(), edges.end(), cmp);
int mstCost = 0;
for (auto e : edges) {
if (findParent(e.u) != findParent(e.v)) {
unionSet(e.u, e.v);
mstCost += e.w;
cout << e.u << " " << e.v << " " << e.w << endl;
}
}
cout << mstCost << endl;
}
