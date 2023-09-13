#include <bits/stdc++.h>

using namespace std;

int readll() {
    int t = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while ('0' <= ch && ch <= '9') t = (t << 3) + (t << 1) + (ch - '0'), ch = getchar();
    return t;
}
const int maxn = 1e5 + 5;
int n;
struct Edge {
    int v, nex;
} rE[maxn << 1];
int rhd[maxn], rtote;
void raddedge(int u, int v) {
    ++rtote, rE[rtote].v = v, rE[rtote].nex = rhd[u], rhd[u] = rtote;
    ++rtote, rE[rtote].v = u, rE[rtote].nex = rhd[v], rhd[v] = rtote;
}

int fat[maxn], sz[maxn], dis[maxn], tp[maxn], pos[maxn], post[maxn], wsn[maxn], posc;
void dfs1(int u, int fa) {
    sz[u] = 1, wsn[u] = 0;
    for (int i = rhd[u]; i; i = rE[i].nex) {
        int v = rE[i].v;
        if (v == fa) continue;
        fat[v] = u, dis[v] = dis[u] + 1;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[wsn[u]]) wsn[u] = v;
    }
}
void dfs2(int u, int Tp) {
    pos[u] = ++posc, tp[u] = Tp;
    if (wsn[u]) dfs2(wsn[u], Tp);
    for (int i = rhd[u]; i; i = rE[i].nex) {
        int v = rE[i].v;
        if (v == fat[u] || v == wsn[u]) continue;
        dfs2(v, v);
    }
    post[u] = posc;
}

int getlca(int u, int v) {
    while (tp[u] != tp[v]) {
        if (dis[tp[u]] < dis[tp[v]]) swap(u, v);
        u = fat[tp[u]];
    }
    if (dis[u] < dis[v]) swap(u, v);
    return v;
}

int C[maxn];
inline int lowbit(int x) { return x & -x; }
void Cadd(int x, int vl) { for (; x <= n; x += lowbit(x)) C[x] += vl; }
int Cask(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += C[x];
    return res;
}
int fa[maxn];
int getfa(int u) { return fa[u] == u ? u : fa[u] = getfa(fa[u]); }

void upd(int u, int par) {
    int b = getfa(u);
    while (dis[fat[b]] >= dis[par]) {
        Cadd(pos[b], 1), Cadd(post[b] + 1, -1);
        fa[b] = fat[b], b = getfa(fat[b]);
    }
}

int Tc, eu[maxn], ev[maxn], fl[maxn];
void solve() {
    Tc++; printf("Case #%d:\n", Tc);
    memset(C, 0, sizeof(C)), memset(rhd, 0, sizeof(rhd)), memset(fl, 0, sizeof(fl));
    rtote = posc = 0;
    int m;
    n = readll(), m = readll();
    for (int i = 1; i <= m; i++) {
        int u = readll(), v = readll();
        eu[i] = u, ev[i] = v;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        int fu = getfa(eu[i]), fv = getfa(ev[i]);
        if (fu != fv) {
            fl[i] = 1;
            fa[fu] = fv;
            cnt++;
            raddedge(eu[i], ev[i]);
        }
        if (cnt == n - 1) break;
    }
    dis[1] = 1, dfs1(1, 0), dfs2(1, 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) if (!fl[i]) {
        int lca = getlca(eu[i], ev[i]);
        upd(eu[i], lca), upd(ev[i], lca);
    }
    // for (int i = 1; i <= blgc; i++) printf("%d|%d ", dis[i], wsn[i]);
    int q = readll();
    for (int i = 1; i <= q; i++) {
        int t = readll(), u = readll(), v = readll(), lca;
        lca = getlca(u, v);
        if (t == 1) upd(u, lca), upd(v, lca);
        else
            printf("%d\n", dis[u] - Cask(pos[u]) + dis[v] - Cask(pos[v]) - ((dis[lca] - Cask(pos[lca])) << 1));
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}