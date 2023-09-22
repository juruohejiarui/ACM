#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL readll() {
    char ch = getchar();
    LL t = 0;
    while ('0' > ch || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9') 
        t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t;
}
const int maxn = 1e5 + 5;
const LL INF = 1e18;

struct Edge {
    int v, nex; LL w;
    Edge(int v = 0, LL w = 0, int nex = 0) : v(v), w(w), nex(nex) {}
} E[maxn << 1];
int hd[maxn], tote;
void addedge(int u, int v, LL w) {
    E[++tote].v = v, E[tote].nex = hd[u], hd[u] = tote;
    E[++tote].v = u, E[tote].nex = hd[v], hd[v] = tote;
    E[tote].w = E[tote - 1].w = w;
}
int n, grd[maxn][20], dep0[maxn], isr[maxn], lsl;
LL h0[maxn], dep[maxn];
pair<LL, int> ls[maxn];

void dfs1(int u, int fa, LL h) {
    grd[u][0] = fa;
    if (isr[u]) h0[u] = h = 0;
    else h0[u] = h;
    for (int i = hd[u]; i; i = E[i].nex) {
        int v = E[i].v;
        if (v == fa) continue;
        dep[v] = dep[u] + E[i].w, dep0[v] = dep0[u] + 1, dfs1(v, u, h + E[i].w);
    }
}
void init1() {
    dfs1(1, 0, 0);
    for (int i = 1; i <= 16; i++) 
        for (int u = 1; u <= n; u++) grd[u][i] = grd[grd[u][i - 1]][i - 1];
}

int getlca(int u, int v) {
    // printf("%d %d -> ", u, v);
    if (dep0[u] < dep0[v]) swap(u, v);
    for (int i = 16; i >= 0; i--) if (dep0[grd[u][i]] >= dep0[v]) u = grd[u][i];
    if (u == v) return u;
    for (int i = 16; i >= 0; i--) if (grd[u][i] != grd[v][i])
        u = grd[u][i], v = grd[v][i];
    // printf("%d\n", grd[u][0]);
    return grd[u][0];
}


void solve() {
    for (int i = 1; i <= n; i++) hd[i] = isr[i] = 0;
    tote = 0;
    int m, q;
    n = readll(), m = readll(), q = readll();
    for (int i = 1; i <= m; i++) isr[readll()] = 1;
    for (int i = 1; i < n; i++) {
        int u = readll(), v = readll(); LL w = readll();
        addedge(u, v, w);
    }
    init1();
    // for (int i = 1; i <= n; i++) printf("%lld ", h0[i]);
    // putchar('\n');
    while (q--) {
        lsl = readll();
        for (int i = 1; i <= lsl; i++) {
            int x = readll();
            ls[i] = make_pair(-h0[x], x);
        }
        sort(ls + 1, ls + 1 + lsl);
        int lst = ls[1].second; LL ans = -ls[1].first, lstv = 0;
        for (int i = 1; i <= lsl; i++) {
            int lca = getlca(lst, ls[i].second), t = ls[i].second;
            LL v1 = lstv + dep[lst] - dep[lca];
            if (i > 1 && v1 >= -ls[i - 1].first) break;
            LL v = max(v1, min(h0[t], dep[t] - dep[lca]));
            if (ans <= v) break;
            if (i < lsl) ans = min(ans, max(v, -ls[i + 1].first));
            else ans = min(ans, v);
            lstv = v, lst = lca;
        }
        printf("%lld\n", ans);
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T = readll();
    while (T--) solve();
    return 0;
}