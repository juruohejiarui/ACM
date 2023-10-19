#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 105, maxm = 1e3 + 5;
const LL INF = 2233333333333333;
struct Edge {
    int v, nex; LL w;
} E[maxm << 1];
int hd[maxn], cur[maxn], tote = 1;

inline void addedge(int u, int v, LL w) {
    E[++tote].v = v, E[tote].nex = hd[u], E[tote].w = w, hd[u] = tote;
    E[++tote].v = u, E[tote].nex = hd[v], E[tote].w = 0, hd[v] = tote;
}

int S, T, dep[maxn];
queue<int> q;

LL dfs(int u, LL flw) {
    if (u == T) return flw;
    LL sum = 0;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (dep[v] == dep[u] + 1 && E[i].w > 0) {
            LL k = dfs(v, min(E[i].w, flw));
            if (!k) continue;
            E[i].w -= k, E[i ^ 1].w += k;
            sum += k, flw -= k;
            if (!flw) break;
        }
        
    }
    if (!sum) dep[u] = -1;
    return sum;
}
bool bfs() {
    memset(dep, -1, sizeof(dep)); dep[S] = 0, q.push(S);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = hd[u]; i; i = E[i].nex) {
            int v = E[i].v;
            if (dep[v] == -1 && E[i].w)
                dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[T] != -1;
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    S = 1, T = n;
    for (int i = 1; i <= m; i++) {
        int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
        addedge(u, v, w * 2018 + 1);
    }
    LL ans = 0;
    while (bfs()) ans += dfs(S, INF);
    printf("%lld %lld\n", ans / 2018, ans % 2018);
    return 0;
}