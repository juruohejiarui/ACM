#include <bits/stdc++.h>

using namespace std;

const int maxn = 205, maxm = 605, INF = 1e9;
struct Edge {
    int v, nex, w;
    Edge(int v = 0, int nex = 0, int w = 0) : v(v), nex(nex), w(w) {}
} E[(maxn + maxm) << 2];
int hd[maxn], cur[maxn], tote = 1;

void addedge(int u, int v, int w) {
    E[++tote] = Edge(v, hd[u], w), hd[u] = tote;
    E[++tote] = Edge(u, hd[v], 0), hd[v] = tote;
}

int S, T, dep[maxn];
queue<int> q;

int dfs(int u, int flw = INF) {
    if (u == T) return flw;
    for (int &i = cur[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (dep[u] >= dep[v] || !E[i].w) continue;
        int k = dfs(v, min(E[i].w, flw));
        if (k > 0) {
            E[i].w -= k, E[i ^ 1].w += k;
            return k;
        }
    }
    return 0;
}

bool bfs() {
    memset(dep, -1, sizeof(dep)); dep[S] = 0, q.push(S);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = hd[u]; i; i = E[i].nex) {
            int v = E[i].v;
            if (dep[v] != -1 || !E[i].w) continue;
            dep[v] = dep[u] + 1, q.push(v);
        }
    }
    return dep[T] != -1;
}

int dinic() {
    int ans = 0, tmp = 0;
    while (bfs()) {
        for (int i = S; i <= T; i++) cur[i] = hd[i];
        while (tmp = dfs(S)) ans += tmp;
    }
    return ans;
}
int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, m, c1, c2;
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    S = 0, T = (n << 1) + 1;
    for (int i = 1; i <= n; i++)
        if (i != c1 && i != c2) addedge((i << 1) - 1, (i << 1), 1);
        else addedge((i << 1) - 1, (i << 1), INF);
    addedge(S, (c1 << 1) - 1, INF), addedge((c2 << 1), T, INF);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        addedge((u << 1), (v << 1) - 1, INF);
        addedge((v << 1), (u << 1) - 1, INF);
    }
    printf("%d\n", dinic());
    return 0;
}