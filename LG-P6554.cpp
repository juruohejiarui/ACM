#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef double LD;

const int maxn = 5e5 + 5;
struct Edge {
    int v, nex;
    Edge(int v = 0, int nex = 0) : v(v), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v) {
    E[++tote] = Edge(v, hd[u]), hd[u] = tote;
    E[++tote] = Edge(u, hd[v]), hd[v] = tote;
}
LL vl[maxn], f[maxn], g[maxn]; int deg[maxn], cnt[maxn], lfcnt;

void dfs1(int u, int fa) {
    bool is_lf = true;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        is_lf = false, dfs1(v, u);
        cnt[u] += cnt[v];
        f[u] += f[v];
    }
    if (is_lf) lfcnt++, cnt[u] = 1;
    f[u] += cnt[u] * vl[u];
}
void dfs2(int u, int fa) {
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        g[v] = g[u] + f[u] - cnt[v] * vl[u] - f[v] + (lfcnt - cnt[v]) * vl[v];
        dfs2(v, u);
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int v, u; scanf("%d%d", &u, &v);
        addedge(u, v);
        deg[u]++, deg[v]++;
    }
    int rt = 1;
    while (deg[rt] == 1) rt++;
    for (int i = 1; i <= n; i++) scanf("%lld", &vl[i]);
    dfs1(rt, 0);
    dfs2(rt, 0);
    LD ans = -1e18;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1) ans = max(ans, 1.0 * g[i] / (lfcnt - 1));
        else ans = max(ans, 1.0 * (f[i] + g[i]) / lfcnt);
    }
    printf("%.4lf\n", ans);
    return 0;
}